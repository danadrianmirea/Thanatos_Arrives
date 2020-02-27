#include "enemy.h"

namespace gamespace
{
	enemy::enemy()
	{

	}

	enemy::enemy(float xPosition, float yPosition, float recWidth, float recHeight,
		const char* textureFile, int columns, int rows, int frameWidth, int frameHeight)
		: animatedSprite(xPosition, yPosition, recWidth, recHeight, textureFile, columns, rows, frameWidth, frameHeight)
	{
		isAttacking = false;
		explosionInstance = new explosion();
		active = false;
		visible = false;
	}

	enemy::~enemy()
	{
		delete explosionInstance;
	}

	void enemy::Draw()
	{
		if (state != dead)
		{
			if (moveDirection.x <= 0.f)
				animatedSprite::Draw();
			else
				DrawTexturePro(spriteTexture, { sourceRec.x,sourceRec.y, -sourceRec.width, sourceRec.height }, actualRectangle, origin, rotation, WHITE);
		}
		else
			explosionInstance->Draw();
	}

	void enemy::Update(float frameTime)
	{
		animatedSprite::Update(frameTime);

		switch (state)
		{
		case idle:
			break;
		case walking:
			Move(moveDirection.x * frameTime * moveSpeed, moveDirection.y * frameTime * moveSpeed);
			break;
		case windup:
			break;
		case attacking:
			Move(moveDirection.x * frameTime * attackSpeed, moveDirection.y * frameTime * attackSpeed);
			break;
		case damaged:
			Move(moveDirection.x * frameTime * damagedSpeed, moveDirection.y * frameTime * damagedSpeed);
			break;
		case dead:
			if (explosionInstance->active)
			{
				explosionInstance->Update(frameTime);
			}
			else
			{
				active = false;
				visible = false;
			}
			break;
		}
		stateTimer += frameTime;
	}

	void enemy::Activate(Vector2 initialPosition) 
	{
		actualRectangle.x = initialPosition.x;
		actualRectangle.y = initialPosition.y;
		active = true;
		visible = true;
		ChangeState(idle);
		currentHP = maxHP;
	}

	void enemy::UpdateEnemy(Vector2 targetPosition)
	{

	}

	void enemy::RecieveDamage(Vector2 damageSource, float damageRecieved)
	{
		if (state != damaged && state != dead)
		{
			ChangeState(damaged);
			currentHP -= damageRecieved;
			if (currentHP > 0.f)
			{
				float resultantX = actualRectangle.x - damageSource.x;
				float resultantY = actualRectangle.y - damageSource.y;

				float magnitude = sqrtf(resultantX * resultantX + resultantY * resultantY);

				moveDirection.x = resultantX / magnitude;
				moveDirection.y = resultantY / magnitude;
			}
			else
			{
				ChangeState(dead);
			}
		}

	}

	bool enemy::CollideWithWall(Rectangle wall)
	{
		if (!explosionInstance->active)
		{
			if (CheckCollisionRecs(actualRectangle, wall))
			{
				if (safePosition.x + actualRectangle.width <= wall.x)
				{
					actualRectangle.x = wall.x - actualRectangle.width / 2;
				}
				if (safePosition.x >= wall.x + wall.width)
				{
					actualRectangle.x = wall.x + wall.width + actualRectangle.width / 2;
				}

				if (safePosition.y + actualRectangle.height <= wall.y)
				{
					actualRectangle.y = wall.y - actualRectangle.height + wallCollisionOffset;
				}
				if (safePosition.y >= wall.y + wall.height)
				{
					actualRectangle.y = wall.y + wall.height + wallCollisionOffset;
				}

				if (state == attacking || state == damaged)
					ChangeState(idle);

				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return true;
		}
	}

	void enemy::UpdateSafePosition()
	{
		safePosition = { actualRectangle.x, actualRectangle.y };
	}

	rectangle* enemy::CheckIfAttackingPlayer(Rectangle playerHitbox) 
	{
		return nullptr;
	}

	void enemy::ChangeState(enemyStates newState)
	{
		if (newState != state)
		{
			state = newState;
			isAttacking = false;
			switch (state)
			{
			case idle:
				NewAnimation(idleAnim);
				break;
			case walking:
				NewAnimation(walkAnim);
				break;
			case windup:
				NewAnimation(windupAnim);
				break;
			case attacking:
				isAttacking = true;
				NewAnimation(attackAnim);
				break;
			case damaged:
				NewAnimation(damageAnim);
				break;
			case dead:
				explosionInstance->Activate({ actualRectangle.x, actualRectangle.y });
				break;
			}
			stateTimer = 0.f;
		}
	}
}
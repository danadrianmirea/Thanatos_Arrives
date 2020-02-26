#include "enemy.h"

namespace gamespace
{
	enemy::enemy()
	{

	}

	enemy::enemy(float xPosition, float yPosition)
		: animatedSprite(xPosition, yPosition, 24.f, 24.f, "../res/assets/padaros.png", 2, 5, 8, 8)
	{
		idleAnim.animationTime = 1.1f;
		idleAnim.addFrame({ 0,0 });
		idleAnim.addFrame({ 1,0 });

		walkAnim.animationTime = 0.3f;
		walkAnim.addFrame({ 0,1 });
		walkAnim.addFrame({ 1,1 });

		windupAnim.animationTime = 0.2f;
		windupAnim.addFrame({ 0,2 });
		windupAnim.addFrame({ 1,2 });

		attackAnim.animationTime = 0.2f;
		attackAnim.addFrame({ 0,3 });

		damageAnim.animationTime = 0.2f;
		damageAnim.addFrame({ 1,3 });
		damageAnim.addFrame({ 0,4 });

		NewAnimation(idleAnim);
		ChangeState(idle);
		isAttacking = false;

		currentHP = maxHP;
		explosionInstance = new explosion();
	}

	enemy::~enemy()
	{
		delete explosionInstance;
	}

	void enemy::Draw()
	{
		if (!explosionInstance->active)
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
			if (currentHP <= 0.f)
			{
				if (explosionInstance->active)
				{
					explosionInstance->Update(frameTime);
				}
				else
				{
					active = false;
					visible = false;
				}
			}
			break;
		default:
			break;
		}
		stateTimer += frameTime;

		
	}

	void enemy::UpdateEnemy(Vector2 targetPosition)
	{
		if (state != attacking && state != windup)
		{
			lastKnownTargetPosition.x = targetPosition.x - actualRectangle.x;
			lastKnownTargetPosition.y = targetPosition.y - actualRectangle.y;

			distanceToTarget = sqrtf(lastKnownTargetPosition.x * lastKnownTargetPosition.x + lastKnownTargetPosition.y * lastKnownTargetPosition.y);

			if (state != damaged)
			{
				moveDirection.x = lastKnownTargetPosition.x / distanceToTarget;
				moveDirection.y = lastKnownTargetPosition.y / distanceToTarget;
			}
		}
		switch (state)
		{
		case idle:
			if (stateTimer >= recoveryTime && distanceToTarget <= targetWalkDistance)
				ChangeState(walking);
			break;
		case walking:
			if (stateTimer >= attackCooldown && distanceToTarget <= targetAttackDistance)
				ChangeState(windup);
			else
				if (distanceToTarget > targetWalkDistance)
					ChangeState(idle);

			break;
		case windup:
			if (stateTimer >= windupTime)
				ChangeState(attacking);
			break;
		case attacking:
			if (stateTimer >= attackTime)
			{
				ChangeState(idle);
				isAttacking = false;
			}
			break;
		case damaged:
			if (stateTimer >= damagedTime)
				ChangeState(idle);
			break;
		default:
			break;
		}
	}

	void enemy::RecieveDamage(Vector2 damageSource, float damageRecieved) 
	{
		if (state != damaged)
		{
			ChangeState(damaged);
			currentHP -= damageRecieved;
			if (currentHP >= 0.f)
			{
				float resultantX = actualRectangle.x - damageSource.x;
				float resultantY = actualRectangle.y - damageSource.y;

				float magnitude = sqrtf(resultantX * resultantX + resultantY * resultantY);

				moveDirection.x = resultantX / magnitude;
				moveDirection.y = resultantY / magnitude;
			}
			else
			{
				explosionInstance->Activate({ actualRectangle.x, actualRectangle.y });
			}
		}

	}

	void enemy::ChangeState(enemyStates newState)
	{
		if (newState != state)
		{
			state = newState;
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
			}
			stateTimer = 0.f;
		}
	}
}
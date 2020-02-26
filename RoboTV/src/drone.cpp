#include "drone.h"

namespace gamespace
{

	drone::drone()
	{
	}

	drone::drone(Vector2 targetPosition) : animatedSprite(0.f,0.f,12.f,12.f,"../res/assets/drone_spritesheet.png",2,4,4,4)
	{
		thanatosPosition = targetPosition;
		actualRectangle.y = thanatosPosition.y;
		actualRectangle.x = thanatosPosition.x + droneOffset;

		idleAnim.animationTime = 1.9f;
		idleAnim.addFrame({ 0,0 });
		idleAnim.addFrame({ 1,0 });

		NewAnimation(idleAnim);
		attackInstance = new pyrnos();

		for (int i = 0; i < maxVelos; i++)
		{
			velosList.push_back(new velos(true));
		}

	}

	drone::~drone()
	{
		delete attackInstance;
		for (int i = 0; i < maxVelos; i++)
		{
			delete velosList[i];
		}
	}

	void drone::Draw() 
	{
		animatedSprite::Draw();
		if (attackInstance->visible)
			attackInstance->Draw();

		for (int i = 0; i < maxVelos; i++)
		{
			if (velosList[i]->active)
			{
				velosList[i]->Draw();
			}
		}
	}

	void drone::Update(float frameTime, Vector2 targetPosition, cursor* cursorInstance)
	{
		animatedSprite::Update(frameTime);

		thanatosPosition = targetPosition;
		
		float resultantX = cursorInstance->actualRectangle.x - thanatosPosition.x;
		float resultantY = cursorInstance->actualRectangle.y - thanatosPosition.y;

		float magnitude = sqrtf(resultantX * resultantX + resultantY * resultantY);

		actualRectangle.x = thanatosPosition.x + (resultantX / magnitude * droneOffset);
		actualRectangle.y = thanatosPosition.y + (resultantY / magnitude * droneOffset);

		if (IsMouseButtonPressed(0))
		{
			Fire(attackInstance);
		}
		if (IsMouseButtonPressed(1) && magnitude >= minCursorDistance)
		{
			for (int i = 0; i < maxVelos; i++)
			{
				if (!velosList[i]->active)
				{
					Fire(velosList[i]);
					velosList[i]->UpdateTarget({ cursorInstance->actualRectangle.x, cursorInstance->actualRectangle.y });
						i = maxVelos;
				}
			}
		}

		if (attackInstance->active)
			attackInstance->Update(frameTime);

		for (int i = 0; i < maxVelos; i++)
		{
			if (velosList[i]->active)
			{
				velosList[i]->Update(frameTime);
			}
		}

	}

	attack* drone::GetCollidingAttack(Rectangle enemyHitbox)
	{
		if (attackInstance->active)
			if (attackInstance->CheckCollisionWithEnemy(enemyHitbox))
				return attackInstance;
		
		for (int i = 0; i < maxVelos; i++)
		{
			if (velosList[i]->active)
			{
				if (velosList[i]->CheckCollisionWithEnemy(enemyHitbox))
				{
					velosList[i]->active = false;
					velosList[i]->visible = false;
					return velosList[i];
				}
			}
		}

		return nullptr;
	}

	void drone::CollideVelosWithWall(rectangle wall) 
	{
		for (int i = 0; i < maxVelos; i++)
		{
			if (velosList[i]->active)
			{
				if (velosList[i]->CheckCollisionWithEnemy(wall.actualRectangle))
				{
					velosList[i]->active = false;
					velosList[i]->visible = false;
				}
			}
		}
	}

	void drone::Fire(attack* attacktoFire)
	{
		float resultantX = actualRectangle.x - thanatosPosition.x;
		float resultantY = actualRectangle.y - thanatosPosition.y;

		float magnitude = sqrtf(resultantX * resultantX + resultantY * resultantY);

		float normalizedX = resultantX / magnitude;
		float normalizedY = resultantY / magnitude;

		float attackAngle = acosf(normalizedX) * 180.f / PI + 90.f;
		if (normalizedY < 0)
			attackAngle = -attackAngle;

		attacktoFire->Activate({ actualRectangle.x + normalizedX * attackOffset, actualRectangle.y + normalizedY * attackOffset }, attackAngle, normalizedY < 0);
	}


}
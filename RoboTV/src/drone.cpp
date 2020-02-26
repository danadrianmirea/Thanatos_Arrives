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
	}

	drone::~drone()
	{
		delete attackInstance;
	}

	void drone::Draw() 
	{
		animatedSprite::Draw();
		if (attackInstance->visible)
			attackInstance->Draw();
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
			resultantX = actualRectangle.x - thanatosPosition.x;
			resultantY = actualRectangle.y - thanatosPosition.y;

			magnitude = sqrtf(resultantX * resultantX + resultantY * resultantY);

			float normalizedX = resultantX / magnitude;
			float normalizedY = resultantY / magnitude;

			float attackAngle = acosf(normalizedX) * 180.f / PI + 90.f;
			if (normalizedY < 0)
				attackAngle = -attackAngle;
			attackInstance->Activate({ actualRectangle.x + normalizedX * attackOffset, actualRectangle.y + normalizedY * attackOffset},attackAngle, normalizedY<0);
		}

		if (attackInstance->active)
			attackInstance->Update(frameTime);
	}

	attack* drone::GetCollidingAttack(Rectangle enemyHitbox)
	{
		if (attackInstance->active)
			if (attackInstance->CheckCollisionWithEnemy(enemyHitbox))
				return attackInstance;
		
		return nullptr;
	}

}
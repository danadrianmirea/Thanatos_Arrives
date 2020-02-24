#include "drone.h"

namespace gamespace
{

	drone::drone()
	{
	}

	drone::drone(thanatos* thanatosInstance) : animatedSprite(0.f,0.f,12.f,12.f,"../res/assets/drone_spritesheet.png",2,4,4,4)
	{
		parentThanatos = thanatosInstance;
		actualRectangle.y = parentThanatos->actualRectangle.y;
		actualRectangle.x = parentThanatos->actualRectangle.x + droneOffset;

		idleAnim.animationTime = 1.9f;
		idleAnim.addFrame({ 0,0 });
		idleAnim.addFrame({ 1,0 });

		NewAnimation(idleAnim);
		attackInstance = new attack();
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

	void drone::Update(float frameTime)
	{
		animatedSprite::Update(frameTime);
		/*actualRectangle.y = parentThanatos->actualRectangle.y;
		actualRectangle.x = parentThanatos->actualRectangle.x + droneOffset;*/

		if (IsMouseButtonPressed(0))
		{
			float resultantX = actualRectangle.x - parentThanatos->actualRectangle.x;
			float resultantY = actualRectangle.y - parentThanatos->actualRectangle.y;

			float magnitude = sqrtf(resultantX * resultantX + resultantY * resultantY);

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

	void drone::UpdateDrone(cursor* cursorInstance) 
	{
		float resultantX = cursorInstance->actualRectangle.x - parentThanatos->actualRectangle.x;
		float resultantY = cursorInstance->actualRectangle.y - parentThanatos->actualRectangle.y;

		float magnitude = sqrtf(resultantX * resultantX + resultantY * resultantY);

		actualRectangle.x = parentThanatos->actualRectangle.x + (resultantX / magnitude * droneOffset);
		actualRectangle.y = parentThanatos->actualRectangle.y + (resultantY / magnitude * droneOffset);
	}

}
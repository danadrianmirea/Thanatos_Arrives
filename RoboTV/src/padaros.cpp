#include "padaros.h"

namespace gamespace
{
	padaros::padaros()
	{

	}

	padaros::padaros(float xPosition, float yPosition)
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
	}

	padaros::~padaros()
	{

	}

	void padaros::Update(float frameTime)
	{
		animatedSprite::Update(frameTime);
		if (state == walking) 
		{
			lastKnownTargetPosition.x = lastKnownTargetPosition.x / distanceToTarget;
			lastKnownTargetPosition.y = lastKnownTargetPosition.y / distanceToTarget;

			Move(lastKnownTargetPosition.x * frameTime * moveSpeed, lastKnownTargetPosition.y * frameTime * moveSpeed);
		}
			stateTimer += frameTime;
	}

	void padaros::UpdatePadaros(Vector2 targetPosition)
	{
		lastKnownTargetPosition.x = targetPosition.x - actualRectangle.x;
		lastKnownTargetPosition.y = targetPosition.y - actualRectangle.y;

		distanceToTarget = sqrtf(lastKnownTargetPosition.x * lastKnownTargetPosition.x + lastKnownTargetPosition.y * lastKnownTargetPosition.y);

		switch (state)
		{
		case idle:
			if (distanceToTarget <= targetWalkDistance)
				ChangeState(walking);
			break;
		case walking:
			if (stateTimer >= recoveryTime && distanceToTarget <= targetAttackDistance)
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
				ChangeState(idle);
			break;
		case damaged:
			if (stateTimer >= damagedTime)
				ChangeState(idle);
			break;
		default:
			break;
		}
	}

	void padaros::ChangeState(padarosStates newState)
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
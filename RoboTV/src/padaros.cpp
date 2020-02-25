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
		isAttacking = false;
	}

	padaros::~padaros()
	{

	}

	void padaros::Draw()
	{
		if (moveDirection.x <= 0.f)
			animatedSprite::Draw();
		else
			DrawTexturePro(spriteTexture, { sourceRec.x,sourceRec.y, -sourceRec.width, sourceRec.height }, actualRectangle, origin, rotation, WHITE);
	}

	void padaros::Update(float frameTime)
	{
		animatedSprite::Update(frameTime);
		if (state == walking) 
		{
			Move(moveDirection.x * frameTime * moveSpeed, moveDirection.y * frameTime * moveSpeed);
		}
		if (state == attacking) 
		{
			Move(moveDirection.x * frameTime * attackSpeed, moveDirection.y * frameTime * attackSpeed);
		}
			stateTimer += frameTime;
	}

	void padaros::UpdatePadaros(Vector2 targetPosition)
	{
		if (state != attacking && state != windup)
		{
			lastKnownTargetPosition.x = targetPosition.x - actualRectangle.x;
			lastKnownTargetPosition.y = targetPosition.y - actualRectangle.y;

			distanceToTarget = sqrtf(lastKnownTargetPosition.x * lastKnownTargetPosition.x + lastKnownTargetPosition.y * lastKnownTargetPosition.y);

			moveDirection.x = lastKnownTargetPosition.x / distanceToTarget;
			moveDirection.y = lastKnownTargetPosition.y / distanceToTarget;
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
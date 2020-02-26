#include "sfaira.h"

namespace gamespace
{
	sfaira::sfaira()
	{

	}

	sfaira::sfaira(float xPosition, float yPosition) 
		:enemy(xPosition, yPosition, 24.f, 24.f, "../res/assets/sfaira.png", 2, 4, 8, 8)
	{
		targetWalkDistance = sfairaTargetWalkDistance;
		targetAttackDistance = sfairaTargetAttackDistance;
		windupTime = sfairaWindupTime;
		attackTime = sfairaAttackTime;
		recoveryTime = sfairaRecoveryTime;
		attackCooldown = sfairaAttackCooldown;
		damagedTime = sfairaDamagedTime;
		moveSpeed = sfairaMoveSpeed;
		attackSpeed = sfairaAttackSpeed;
		damagedSpeed = sfairaDamagedSpeed;
		attackDamage = sfairaAttackDamage;

		idleAnim.animationTime = 1.1f;
		idleAnim.addFrame({ 0,0 });
		idleAnim.addFrame({ 1,0 });

		walkAnim.animationTime = 0.5f;
		walkAnim.addFrame({ 0,0 });
		walkAnim.addFrame({ 1,0 });
		walkAnim.addFrame({ 0,1 });
		walkAnim.addFrame({ 1,1 });

		windupAnim.animationTime = 0.1f;
		windupAnim.addFrame({ 0,2 });
		windupAnim.addFrame({ 1,2 });

		attackAnim.animationTime = 0.2f;
		attackAnim.addFrame({ 0,3 });
		windupAnim.addFrame({ 1,2 });
		windupAnim.addFrame({ 0,2 });
		attackAnim.addFrame({ 0,3 });


		damageAnim.animationTime = 0.2f;
		damageAnim.addFrame({ 0,3 });

		NewAnimation(idleAnim);

		ChangeState(idle);
		currentHP = sfairaMaxHP;
	}

	sfaira::~sfaira()
	{

	}

	void sfaira::UpdateEnemy(Vector2 targetPosition) 
	{
		/*if (state != attacking && state != windup)
		{
			lastKnownTargetPosition.x = targetPosition.x - actualRectangle.x;
			lastKnownTargetPosition.y = targetPosition.y - actualRectangle.y;

			distanceToTarget = sqrtf(lastKnownTargetPosition.x * lastKnownTargetPosition.x + lastKnownTargetPosition.y * lastKnownTargetPosition.y);

			if (state != damaged)
			{
				moveDirection.x = lastKnownTargetPosition.x / distanceToTarget;
				moveDirection.y = lastKnownTargetPosition.y / distanceToTarget;
			}
		}*/

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

}
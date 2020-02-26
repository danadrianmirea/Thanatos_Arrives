#ifndef PADAROS_H
#define PADAROS_H

#include "animatedSprite.h"
namespace gamespace
{

	class padaros : public animatedSprite
	{

	public:

		const float attackRadius = 10.f;
		padaros();
		padaros(float xPosition, float yPosition);
		~padaros();
		void Draw();
		void Update(float frameTime);
		void UpdatePadaros(Vector2 targetPosition);
		void RecieveDamage(Vector2 damageSource, float damageRecieved);
		bool isAttacking;

	private:

		const float targetWalkDistance = 180.f;
		const float targetAttackDistance = 70.f;
		const float windupTime = 0.4f;
		const float attackTime = 0.15f;
		const float recoveryTime = 0.3f;
		const float attackCooldown = 1.0f;
		const float damagedTime = 0.6f;
		const float moveSpeed = 140.f;
		const float attackSpeed = 600.f;
		const float damagedSpeed = 100.f;

		const float maxHP = 70.f;

		enum padarosStates
		{
			idle, walking, windup, attacking, damaged
		};

		void ChangeState(padarosStates newState);

		float stateTimer;
		float distanceToTarget;
		float currentHP;
		Vector2 lastKnownTargetPosition;
		Vector2 moveDirection;
		padarosStates state;
		animationData idleAnim;
		animationData walkAnim;
		animationData windupAnim;
		animationData attackAnim;
		animationData damageAnim;

	};
}
#endif
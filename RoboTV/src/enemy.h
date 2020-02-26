#ifndef ENEMY_H
#define ENEMY_H

#include "animatedSprite.h"
#include "explosion.h"

namespace gamespace
{

	class enemy : public animatedSprite
	{

	public:

		const float attackRadius = 10.f;
		enemy();
		enemy(float xPosition, float yPosition, float recWidth, float recHeight,
			const char* textureFile, int columns, int rows, int frameWidth, int frameHeight);
		~enemy();
		void Draw();
		void Update(float frameTime);
		virtual void UpdateEnemy(Vector2 targetPosition);
		void RecieveDamage(Vector2 damageSource, float damageRecieved);
		bool CollideWithWall(Rectangle wall);
		void UpdateSafePosition();
		bool isAttacking;
		float attackDamage;

	protected:

		float targetWalkDistance = 180.f;
		float targetAttackDistance = 70.f;
		float windupTime = 0.4f;
		float attackTime = 0.15f;
		float recoveryTime = 0.3f;
		float attackCooldown = 1.0f;
		float damagedTime = 0.6f;
		float moveSpeed = 140.f;
		float attackSpeed = 600.f;
		float damagedSpeed = 100.f;
		const float wallCollisionOffset = 2.f;

		float maxHP;

		enum enemyStates
		{
			idle, walking, windup, attacking, damaged
		};

		void ChangeState(enemyStates newState);

		float stateTimer;
		float distanceToTarget;
		float currentHP;
		Vector2 lastKnownTargetPosition;
		Vector2 moveDirection;
		Vector2 safePosition;
		enemyStates state;
		animationData idleAnim;
		animationData walkAnim;
		animationData windupAnim;
		animationData attackAnim;
		animationData damageAnim;
		explosion* explosionInstance;

	};
}
#endif
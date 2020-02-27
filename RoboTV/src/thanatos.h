#ifndef THANATOS_H
#define THANATOS_H

#include "animatedSprite.h"

#include "cursor.h"
#include "drone.h"


namespace gamespace
{
	class thanatos : public animatedSprite
	{
	public:
		thanatos();
		thanatos(float xPosition, float yPosition, cursor* gameCursor);
		~thanatos();
		void Draw();
		void Update(float frameTime);
		void UpdateSafePosition();
		bool CoolideWithWall(const rectangle* wall);
		void RecieveDamage(Vector2 damageSource, float damageTaken);
		attack* CheckIfAttackingEnemy(Rectangle enemyHitbox);
		Rectangle AABB;

	private:
		const float AABBxOffset = -8.5f;
		const float AABByOffset = -4.f;
		const float AABBWidthOffset = -9.5f;
		const float AABBHeightOffset = -8.f;
		const float wallCollisionOffset = 3.f;

		const float moveSpeed = 150.f;
		const float dashSpeed = 800.f;
		const float damageSpeed = 600.f;
		const float maxHP = 100.f;

		const float attackTime = 0.2f;
		const float dashTime = 0.1f;
		const float damageTime = 0.05f;
		const float dashCooldownTime = 0.7f;
		const float invulnerabilityTime = 0.8f;
		const float resourceCooldownTime = 0.3f;

		enum thanatosStates
		{
			idle, walking, attacking, dashing, damaged
		};

		void ChangeState(thanatosStates newState);

		float currentHP;
		float stateTimer;
		float dashCooldown;
		float damageCooldown;
		float resourceCooldown;

		animationData idleAnim;
		animationData walkAnim;
		animationData attackAnim;
		animationData dashAnim;
		animationData damageAnim;
		Vector2 safePosition;
		Vector2 moveDirection;
		thanatosStates state;

		cursor* cursorInstance;
		drone* droneInstance;
	};
}
#endif
#ifndef PADAROS_H
#define PADAROS_H

#include "enemy.h"

namespace gamespace
{
	class padaros : public enemy
	{
	public:
		padaros();
		padaros(float xPosition, float yPosition);
		~padaros();
		void UpdateEnemy(Vector2 targetPosition);
		rectangle* CheckIfAttackingPlayer(Rectangle playerHitbox);

	private:
		const float padarosTargetWalkDistance = 330.f;
		const float padarosTargetAttackDistance = 70.f;
		const float padarosWindupTime = 0.4f;
		const float padarosAttackTime = 0.15f;
		const float padarosRecoveryTime = 0.3f;
		const float padarosAttackCooldown = 1.0f;
		const float padarosDamagedTime = 0.6f;
		const float padarosMoveSpeed = 140.f;
		const float padarosAttackSpeed = 600.f;
		const float padarosDamagedSpeed = 100.f;
		const float padarosMaxHP = 50.f;
		const float padarosAttackDamage = 30.f;
	};
}
#endif
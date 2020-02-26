#ifndef SFEIRA_H
#define SFEIRA_H

#include "enemy.h"

namespace gamespace
{
	class sfaira : public enemy
	{
	public:
		sfaira();
		sfaira(float xPosition, float yPosition);
		~sfaira();
		void UpdateEnemy(Vector2 targetPosition);

	private:
		const float sfairaTargetWalkDistance = 180.f;
		const float sfairaTargetAttackDistance = 70.f;
		const float sfairaWindupTime = 0.4f;
		const float sfairaAttackTime = 0.15f;
		const float sfairaRecoveryTime = 0.3f;
		const float sfairaAttackCooldown = 1.0f;
		const float sfairaDamagedTime = 0.6f;
		const float sfairaMoveSpeed = 140.f;
		const float sfairaAttackSpeed = 600.f;
		const float sfairaDamagedSpeed = 100.f;
		const float sfairaMaxHP = 70.f;

	};
}

#endif
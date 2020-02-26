#ifndef SFEIRA_H
#define SFEIRA_H

#include <vector>

#include "enemy.h"
#include "velos.h"

namespace gamespace
{
	class sfaira : public enemy
	{
	public:
		sfaira();
		sfaira(float xPosition, float yPosition);
		~sfaira();
		void Draw();
		void Update(float frameTime);
		void UpdateEnemy(Vector2 targetPosition);

	private:
		void Fire(velos* attackToFire, Vector2 targetPosition);

		const float sfairaTargetWalkDistance = 380.f;
		const float sfairaTargetAttackDistance = 380.f;
		const float sfairaWindupTime = 0.4f;
		const float sfairaAttackTime = 0.15f;
		const float sfairaRecoveryTime = 0.8f;
		const float sfairaAttackCooldown = 1.0f;
		const float sfairaDamagedTime = 0.3f;
		const float sfairaMoveSpeed = 140.f;
		const float sfairaAttackSpeed = 600.f;
		const float sfairaDamagedSpeed = 200.f;
		const float sfairaMaxHP = 70.f;
		const float sfairaAttackDamage = 30.f;
		const int maxVelos = 20;
		//const float attackOffset = 30.f;

		std::vector<velos*> velosList;
	};
}

#endif
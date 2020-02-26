#ifndef ATTACK_H
#define ATTACK_H
#include "animatedSprite.h"

namespace gamespace
{
	const float attackDuration = 0.3f;

	class attack :
		public animatedSprite
	{
	public:
		attack();
		~attack();
		void Draw();
		void Update(float frameTime);
		void Activate(Vector2 position, float attackRotation, bool yInverted);
		bool CheckCollisionWithEnemy(Rectangle enemyHitbox);

		const float attackDamage = 30.f;

		float attackRadius;
		bool inverted;

	private:
		float activeTime;
	};

}
#endif
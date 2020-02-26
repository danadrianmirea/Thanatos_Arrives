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
		attack(float recWidth, float recHeight, const char* textureFile, 
			int columns, int rows, int frameWidth, int frameHeight);
		~attack();
		void Draw();
		virtual void Activate(Vector2 position, float attackRotation, bool yInverted);
		bool CheckCollisionWithEnemy(Rectangle enemyHitbox);

		const float attackDamage = 30.f;

		float attackRadius;
		bool inverted;

	protected:
		float activeTime;
	};

}
#endif
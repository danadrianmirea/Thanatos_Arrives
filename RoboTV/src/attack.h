#ifndef ATTACK_H
#define ATTACK_H
#include "animatedSprite.h"

namespace gamespace
{
	class attack :
		public animatedSprite
	{
	public:
		attack();
		~attack();
		void Draw();
		void Activate(Vector2 position, float attackRotation);
		void CheckCollisionWithEnemy(const animatedSprite* enemy);

		float attackRadius;
	};

}
#endif
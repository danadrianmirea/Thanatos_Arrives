#ifndef  DRONE_H
#define DRONE_H

#include "cursor.h"
#include "attack.h"

namespace gamespace
{
	class drone : public animatedSprite
	{
	public:
		drone();
		drone(Vector2 targetPosition);
		~drone();
		void Draw();
		void Update(float frameTime, Vector2 targetPosition, cursor* cursorInstance);
		attack* GetCollidingAttack(Rectangle enemyHitbox);

	private:
		const float droneOffset = 18.f;
		const float attackOffset = 20.f;

		Vector2 thanatosPosition;
		attack* attackInstance;
		animationData idleAnim;
	};
}
#endif
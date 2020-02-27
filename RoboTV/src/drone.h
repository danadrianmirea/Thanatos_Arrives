#ifndef  DRONE_H
#define DRONE_H

#include <vector>

#include "cursor.h"
#include "pyrnos.h"
#include "velos.h"

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
		void CollideVelosWithWall(rectangle wall);
		void GainResource();
		int GetCurrentResource();

	private:
		void Fire(attack* attacktoFire);

		const float droneOffset = 18.f;
		const float attackOffset = 20.f;
		const float minCursorDistance = 40.f;
		const int maxVelos = 3;
		const int maxResource = 3;

		int resource;
		Vector2 thanatosPosition;
		pyrnos* attackInstance;
		std::vector<velos*> velosList;
		animationData idleAnim;
	};
}
#endif
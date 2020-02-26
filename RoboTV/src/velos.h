#ifndef VELOS_H
#define VELOS_H

#include "attack.h"

namespace gamespace
{
	class velos : public attack
	{
	public:
		velos(bool friendly);
		~velos();
		void Update(float frameTime);
		void UpdateTarget(Vector2 newPosition);

	private:
		Vector2 moveDirection;
		const float moveSpeed = 800.f;
		const float velosAttackRadius = 10.f;
		const float velosAttackDamage = 30.f;
		const float velosAttackDuration = 2.0f;
	};
}
#endif
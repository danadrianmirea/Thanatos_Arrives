#ifndef VELOS_H
#define VELOS_H

#include "attack.h"

namespace gamespace
{
	class velos : public attack
	{
	public:
		velos();
		~velos();
		void Update(float frameTime);
		//void Activate(Vector2 position, float attackRotation, bool yInverted);
		void UpdateTarget(Vector2 newPosition);

	private:
		Vector2 moveDirection;
		const float moveSpeed = 800.f;
	};
}
#endif
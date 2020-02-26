#ifndef PYRNOS_H
#define PYRNOS_H

#include "attack.h"

namespace gamespace
{
	class pyrnos : public attack
	{
	public:
		pyrnos();
		~pyrnos();
		void Update(float frameTime);
		//void Activate(Vector2 position, float attackRotation, bool yInverted);

	};
}
#endif
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
	private:
		const float pyrnosAttackRadius = 10.f;
		const float pyrnosAttackDamage = 20.f;
		const float pyrnosAttackDuration = 0.3f;

	};
}
#endif
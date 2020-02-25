#ifndef PADAROS_H
#define PADAROS_H

#include "animatedSprite.h"
namespace gamespace
{
	class padaros : public animatedSprite
	{
	public:
		padaros();
		padaros(float xPosition, float yPosition);
		~padaros();
		void Update(float frameTime);

		animationData idleAnim;
		animationData walkAnim;
		animationData windupAnim;
		animationData attackAnim;
		animationData damageAnim;

	};
}
#endif
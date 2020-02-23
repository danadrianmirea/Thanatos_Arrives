#ifndef  DRONE_H
#define DRONE_H

#include "thanatos.h"

namespace gamespace
{
	const float droneOffset = 18.f;

	class drone : public animatedSprite
	{
	public:
		drone();
		drone(thanatos* thanatosInstance);
		~drone();
		void Update(float frameTime);

	private:
		thanatos* parentThanatos;

		animationData idleAnim;
	};
}
#endif
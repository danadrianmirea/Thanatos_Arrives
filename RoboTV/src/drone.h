#ifndef  DRONE_H
#define DRONE_H

#include "thanatos.h"

#include "cursor.h"

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
		void UpdateDrone(cursor* cursorInstance);

	private:
		thanatos* parentThanatos;
		animationData idleAnim;
	};
}
#endif
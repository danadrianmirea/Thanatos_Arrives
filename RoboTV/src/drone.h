#ifndef  DRONE_H
#define DRONE_H

#include "thanatos.h"

#include "cursor.h"
#include "attack.h"

namespace gamespace
{
	const float droneOffset = 18.f;
	const float attackOffset = 20.f;

	class drone : public animatedSprite
	{
	public:
		drone();
		drone(thanatos* thanatosInstance);
		~drone();
		void Draw();
		void Update(float frameTime);
		void UpdateDrone(cursor* cursorInstance);

	private:
		thanatos* parentThanatos;
		attack* attackInstance;
		animationData idleAnim;
	};
}
#endif
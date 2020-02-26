#ifndef EXPLOSION_H
#define EXPLOSION_H
	
#include "animatedSprite.h"

namespace gamespace
{
	class explosion :
		public animatedSprite
	{
	public:
		explosion();
		~explosion();
		void Update(float frameTime);
		void Activate(Vector2 position);

	private:
		const float duration = 0.4f;
		float activeTime;
	};
}
#endif
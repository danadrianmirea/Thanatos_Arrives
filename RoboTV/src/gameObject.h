#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "raylib.h"

namespace gamespace
{
	class gameObject
	{
	public:
		gameObject();
		virtual ~gameObject();
		virtual void Draw();
		virtual void Update(float frameTime);
		bool active;
		bool visible;
	};
}
#endif
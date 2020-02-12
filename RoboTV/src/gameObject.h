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
		bool active;
		float x, y;
	};
}
#endif
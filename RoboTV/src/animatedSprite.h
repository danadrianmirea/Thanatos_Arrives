#ifndef  ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include "rectangle.h"

namespace gamespace
{
	class animatedSprite :public rectangle
	{
	public:
		animatedSprite();
		~animatedSprite();
		Texture2D spritesheet;
	};
}
#endif
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
		void Draw();

		Texture2D spritesheet;
		Rectangle sourceRec;
		Vector2 origin;
		float rotation;

	private:
		int spriteRows;
		int spriteColumns;
	};
}
#endif
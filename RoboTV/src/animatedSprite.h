#ifndef  ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include "rectangle.h"

namespace gamespace
{
	
	class animatedSprite :public rectangle
	{
	public:
		animatedSprite();
		animatedSprite(float xPosition, float yPosition, float recWidth, float recHeight,
			const char* textureFile, int columns, int rows, int frameWidth, int frameHeight);
		~animatedSprite();
		void Draw();

		Texture2D spritesheet;
		Rectangle sourceRec;
		Vector2 origin;
		float rotation;

	private:
		int spriteRows;
		int spriteColumns;
		int spriteWidth;
		int spriteHeight;
	};
}
#endif
#ifndef  SPRITE_H
#define SPRITE_H

#include "rectangle.h"

namespace gamespace
{
	class sprite : public rectangle
	{
	public:
		sprite();
		sprite(float xPosition, float yPosition, float recWidth, float recHeight,
			const char* textureFile, int frameWidth, int frameHeight);
		~sprite();
		void Draw();

		Texture2D spriteTexture;
		Rectangle sourceRec;
		Vector2 origin;
		float rotation;

	protected:

		int spriteWidth;
		int spriteHeight;
	};
}

#endif
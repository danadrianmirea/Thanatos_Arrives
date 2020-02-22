#include "sprite.h"

namespace gamespace
{

	sprite::sprite()
	{

	}

	sprite::sprite(float xPosition, float yPosition, float recWidth, float recHeight,
		const char* textureFile, int frameWidth, int frameHeight) : rectangle (xPosition, yPosition, recWidth, recHeight, WHITE)
	{
		spriteTexture = LoadTexture(textureFile);
		spriteWidth = frameWidth;
		spriteHeight = frameHeight;

		sourceRec = { 0.f,0.f,static_cast<float>(spriteWidth), static_cast<float>(spriteHeight) };
		origin = { actualRectangle.width / 2.f, actualRectangle.height / 2.f };
		rotation = 0.f;

	}


	sprite::~sprite()
	{
	}

	void sprite::Draw() 
	{
		DrawTexturePro(spriteTexture, sourceRec, actualRectangle, origin, rotation, WHITE);
	}
}
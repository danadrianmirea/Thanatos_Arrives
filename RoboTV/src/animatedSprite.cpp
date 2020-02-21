#include "animatedSprite.h"

namespace gamespace
{
	animatedSprite::animatedSprite()
	{

	}

	animatedSprite::animatedSprite(float xPosition, float yPosition, float recWidth, float recHeight,
		const char* textureFile, int columns, int rows, int frameWidth, int frameHeight) : rectangle(xPosition, yPosition, recWidth, recHeight, WHITE)
	{
		spritesheet = LoadTexture(textureFile);
		spriteColumns = columns;
		spriteRows = rows;
		spriteWidth = frameWidth;
		spriteHeight = frameHeight;

		sourceRec = { 0.f,0.f,static_cast<float>(spriteWidth), static_cast<float>(spriteHeight) };
		origin = { actualRectangle.width / 2.f, actualRectangle.height / 2.f };
		rotation = 0.f;
		currentAnimTime = 0.f;
		animate = false;
	}


	animatedSprite::~animatedSprite()
	{

	}

	void animatedSprite::Draw()
	{
		DrawTexturePro(spritesheet, sourceRec, actualRectangle, origin, rotation, WHITE);
	}

	void animatedSprite::NewAnimation(animationData animData) 
	{
		currentAnimation = animData;
		animate = true;
	}

	void animatedSprite::UpdateAnimation(float elapsedTime)
	{
		if (animate)
		{
			currentAnimTime += elapsedTime;
			if (currentAnimTime > currentAnimation.animationTime)
				currentAnimTime = currentAnimTime - currentAnimation.animationTime;

			int frameIndex = static_cast<int>(currentAnimation.frameList.size() * currentAnimTime / currentAnimation.animationTime);
			

			sourceRec.x = (float)currentAnimation.frameList[frameIndex].x * spriteWidth;
			sourceRec.y = (float)currentAnimation.frameList[frameIndex].y * spriteHeight;
		}
	}
}
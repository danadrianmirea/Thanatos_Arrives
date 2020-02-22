#include "animatedSprite.h"

namespace gamespace
{
	animatedSprite::animatedSprite()
	{

	}

	animatedSprite::animatedSprite(float xPosition, float yPosition, float recWidth, float recHeight,
		const char* textureFile, int columns, int rows, int frameWidth, int frameHeight) : sprite (xPosition, yPosition, recWidth, recHeight, textureFile, frameWidth, frameHeight)
	{
		spriteColumns = columns;
		spriteRows = rows;
		currentAnimTime = 0.f;
		animate = false;
	}


	animatedSprite::~animatedSprite()
	{

	}

	void animatedSprite::Draw()
	{
		DrawTexturePro(spriteTexture, sourceRec, actualRectangle, origin, rotation, WHITE);
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
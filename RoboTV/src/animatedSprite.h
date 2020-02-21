#ifndef  ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <vector>

#include "rectangle.h"

namespace gamespace
{
	struct vector2Int
	{
		int x;
		int y;
	};

	struct animationData 
	{
		std::vector<vector2Int> frameList;
		float animationTime;
	};
	
	class animatedSprite :public rectangle
	{
	public:
		animatedSprite();
		animatedSprite(float xPosition, float yPosition, float recWidth, float recHeight,
			const char* textureFile, int columns, int rows, int frameWidth, int frameHeight);
		~animatedSprite();
		void Draw();
		void NewAnimation(animationData animData);
		void UpdateAnimation(float elapsedTime);

		Texture2D spritesheet;
		Rectangle sourceRec;
		Vector2 origin;
		float rotation;
		animationData currentAnimation;
		float currentAnimTime;
		bool animate;

	private:
		int spriteRows;
		int spriteColumns;
		int spriteWidth;
		int spriteHeight;
	};
}
#endif
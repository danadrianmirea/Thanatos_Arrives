#ifndef  ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <vector>

#include "sprite.h"

namespace gamespace
{
	struct vector2Int
	{
		int x;
		int y;
	};

	class animationData
	{
	public:
		animationData() {}
		animationData(float animTime) 
		{
			animationTime = animTime;
		}
		~animationData() 
		{
			clearData();
		}

		void clearData() 
		{
			std::vector<vector2Int>().swap(frameList); //swaps the vector for an empty one, freeing memory
		}

		std::vector<vector2Int> frameList;
		float animationTime;
		void addFrame(vector2Int newFrame) 
		{
			frameList.insert(frameList.end(), newFrame);
		}
	};

	class animatedSprite : public sprite
	{
	public:
		animatedSprite();
		animatedSprite(float xPosition, float yPosition, float recWidth, float recHeight,
			const char* textureFile, int columns, int rows, int frameWidth, int frameHeight);
		~animatedSprite();
		void Draw();
		void Update(float frameTime);
		void NewAnimation(animationData animData);
		void UpdateAnimation(float elapsedTime);

		animationData currentAnimation;
		float currentAnimTime;
		bool animate;

	protected:
		int spriteRows;
		int spriteColumns;

	};
}
#endif
#include "animatedSprite.h"

namespace gamespace
{
	animatedSprite::animatedSprite()
	{

	}


	animatedSprite::~animatedSprite()
	{
	}

	void animatedSprite::Draw()
	{
		DrawTexturePro(spritesheet, sourceRec, actualRectangle, origin, rotation, WHITE);
	}
}
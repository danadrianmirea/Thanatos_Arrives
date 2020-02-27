#include "button.h"

namespace gamespace
{
	button::button()
	{
	}

	button::button(float xPosition, float yPosition, bool big) 
		:sprite(xPosition, yPosition, 240.f, 120.f, "../res/assets/button.png", 16, 8)
	{
		if (big)
		{
			actualRectangle.width = 96.f;
			spriteTexture = LoadTexture("../res/assets/big_button.png");
			spriteWidth = 32;
		}
	}


	button::~button()
	{
	}
}
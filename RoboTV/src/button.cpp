#include "button.h"

namespace gamespace
{
	button::button()
	{
	}

	button::button(float xPosition, float yPosition, bool big, std::string text)
		:sprite(xPosition, yPosition, 240.f, 120.f, "../res/assets/button.png", 16, 8)
	{
		if (big)
		{
			actualRectangle.width = 96.f;
			spriteTexture = LoadTexture("../res/assets/big_button.png");
			spriteWidth = 32;
		}

		showText = text;
	}


	button::~button()
	{
	}

	void button::Draw() 
	{
		sprite::Draw();
		DrawText(showText.c_str(), actualRectangle.x, actualRectangle.y, 48, WHITE);
	}
}
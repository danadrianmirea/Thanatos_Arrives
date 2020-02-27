#include "button.h"

namespace gamespace
{
	button::button()
	{
	}

	button::button(float xPosition, float yPosition, std::string text, int xOffset)
		:sprite(xPosition, yPosition, 320.f, 80.f, "../res/assets/big_button.png", 32, 8)
	{
		textXOffset = xOffset;
		showText = text;
	}


	button::~button()
	{
	}

	void button::Draw() 
	{
		sprite::Draw();
		DrawText(showText.c_str(), static_cast<int>(actualRectangle.x) + textXOffset, static_cast<int>(actualRectangle.y) + textYOffset, 48, WHITE);
	}
}
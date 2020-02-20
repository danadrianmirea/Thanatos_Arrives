#include "rectangle.h"

namespace gamespace
{
	rectangle::rectangle()
	{
		actualRectangle.x = 0.f;
		actualRectangle.y = 0.f;
		actualRectangle.width = 10.f;
		actualRectangle.height = 5.f;
		color = RED;
	}

	rectangle::rectangle(float xPosition, float yPosition, float recWidth, float recHeight, Color recColor)
	{
		actualRectangle.x = xPosition;
		actualRectangle.y = yPosition;
		actualRectangle.width = recWidth;
		actualRectangle.height = recHeight;
		color = recColor;
	}


	rectangle::~rectangle()
	{
	}

	void rectangle::Move(float x, float y)
	{
		actualRectangle.x += x;
		actualRectangle.y += y;
	}

	void rectangle::Draw() 
	{
		DrawRectangleRec(actualRectangle, color);
	}
}
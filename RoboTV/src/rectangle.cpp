#include "rectangle.h"

namespace gamespace
{
	rectangle::rectangle()
	{
		width = 100.f;
		height = 50.f;
		color = RED;
	}


	rectangle::~rectangle()
	{
	}

	void rectangle::Draw() 
	{
		DrawRectangle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(width), static_cast<int>(height), color);
	}
}
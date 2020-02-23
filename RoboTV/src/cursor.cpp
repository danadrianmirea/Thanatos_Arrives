#include "cursor.h"

namespace gamespace
{
	cursor::cursor(): sprite(0.f,0.f,16.f,16.f,"../res/assets/reticle.png",6,6)
	{
	}

	cursor::~cursor()
	{
	}

	void cursor::UpdateCursor(float xPosition, float yPosition) 
	{
		actualRectangle.x = xPosition;
		actualRectangle.y = yPosition;
	}
}
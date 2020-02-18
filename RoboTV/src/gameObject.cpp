#include "gameObject.h"

namespace gamespace
{
	gameObject::gameObject()
	{
		x = 0.f;
		y = 0.f;
	}

	gameObject::gameObject(float xPosition, float yPosition)
	{
		x = xPosition;
		y = yPosition;
	}

	gameObject::~gameObject()
	{
	}

	void gameObject::Draw() 
	{
	}
}
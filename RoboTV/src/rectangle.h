#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "gameObject.h"

namespace gamespace {
	class rectangle: public gameObject
	{
	public:
		rectangle();
		rectangle(float xPosition, float yPosition, float recWidth, float recHeight, Color recColor);
		~rectangle();
		void Move(float x, float y);
		void Draw();
		float width, height;
		Color color;
		Rectangle actualRectangle;
	};
}
#endif
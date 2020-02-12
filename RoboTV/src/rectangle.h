#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "gameObject.h"

namespace gamespace {
	class rectangle : public gameObject
	{
	public:
		rectangle();
		~rectangle();
		void Draw();
		float width, height;
		Color color;
	};
}
#endif
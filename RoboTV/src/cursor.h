#ifndef CURSOR_H
#define CURSOR_H

#include "sprite.h"

namespace gamespace
{
	class cursor : public sprite
	{
	public:
		cursor();
		~cursor();
		void UpdateCursor(float xPosition, float yPosition);
	};
}
#endif
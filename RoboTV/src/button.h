#ifndef BUTTON_H
#define BUTTON_H

#include "sprite.h"

namespace gamespace
{
	class button : public sprite
	{
	public:
		button();
		button(float xPosition, float yPosition, bool big);
		~button();
	};
}
#endif // !BUTTON_H
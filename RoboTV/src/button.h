#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "sprite.h"

namespace gamespace
{
	class button : public sprite
	{
	public:
		button();
		button(float xPosition, float yPosition, std::string text, int xOffset);
		~button();
		void Draw();

	private:
		const int textYOffset = -20;
		int textXOffset = -60;
		std::string showText;
	};
}
#endif // !BUTTON_H
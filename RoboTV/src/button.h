#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "sprite.h"

namespace gamespace
{
	enum buttonOptions
	{
		none, play, credits, options, exit, sound
	};

	class button : public sprite
	{
	public:
		button();
		button(float xPosition, float yPosition, std::string text, int xOffset, buttonOptions option);
		~button();
		void Draw();
		buttonOptions currentOption;

	private:
		const int textYOffset = -20;
		int textXOffset = -60;
		std::string showText;
	};
}
#endif // !BUTTON_H
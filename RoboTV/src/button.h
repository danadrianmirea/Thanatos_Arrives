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
		button(float xPosition, float yPosition, bool big, std::string text);
		~button();
		void Draw();

	private:
		const int textXOffset = -60;
		const int textYOffset = -20;
		std::string showText;
	};
}
#endif // !BUTTON_H
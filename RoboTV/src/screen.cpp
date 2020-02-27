#include "screen.h"

namespace gamespace
{

	screen::screen(int windowWidth, int windowHeight)
	{
		screenWidth = windowWidth;
		screenHeight = windowHeight;
		mute = false;
	}


	screen::~screen()
	{
	}

	bool screen::mute;

	void screen::Mute(bool muteState)
	{
		mute = muteState;
	}
	bool screen::IsMuted() 
	{
		return mute;
	}
}
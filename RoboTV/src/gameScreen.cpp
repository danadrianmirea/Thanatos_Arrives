#include "gameScreen.h"
#include <math.h>

namespace gamespace
{
	gameScreen::gameScreen()
	{
	}


	gameScreen::~gameScreen()
	{
	}

	void gameScreen::Init()
	{
		elapsedScreenTime = 0.f;
	}

	void gameScreen::Update()
	{
		elapsedScreenTime += GetFrameTime();
	}

	void gameScreen::Draw()
	{
		ClearBackground(BLACK);
		DrawText(TextFormat("%1.1f", elapsedScreenTime), 190, 200, 20, LIGHTGRAY);
	}
}
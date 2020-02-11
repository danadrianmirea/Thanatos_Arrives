#include "gameScreen.h"

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
	
	}

	void gameScreen::Update()
	{
		
	}

	void gameScreen::Draw()
	{
		ClearBackground(BLACK);
		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
	}
}
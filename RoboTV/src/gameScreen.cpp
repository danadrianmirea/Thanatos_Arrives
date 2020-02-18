#include "gameScreen.h"

#include <math.h>

#include "rectangle.h"

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
		gameObject* testRec = new rectangle();
		gameObjectList.push_front(testRec);
	}

	void gameScreen::Update()
	{
		elapsedScreenTime += GetFrameTime();
	}

	void gameScreen::Draw()
	{
		ClearBackground(BLACK);
		std::list<gameObject*> ::iterator it;
		for (it = gameObjectList.begin(); it != gameObjectList.end(); ++it)
		{
			gameObjectList.front()->Draw();
		}
		
		DrawText(TextFormat("%1.1f", elapsedScreenTime), 190, 200, 20, LIGHTGRAY);
	}
}
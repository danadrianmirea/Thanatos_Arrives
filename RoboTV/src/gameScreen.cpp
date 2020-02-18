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
		gameObject* testRec = new rectangle(500.f, 250.f ,200.f ,200.f, RED);
		testRectangle = testRec;
		gameObjectList.push_front(testRec);
	}

	void gameScreen::Update()
	{
		elapsedScreenTime += GetFrameTime();
		if (IsKeyDown(KEY_RIGHT)) testRectangle->x += GetFrameTime() * 200.0f;
		if (IsKeyDown(KEY_LEFT)) testRectangle->x -= GetFrameTime() *200.0f;
		if (IsKeyDown(KEY_UP)) testRectangle->y -= GetFrameTime() *200.0f;
		if (IsKeyDown(KEY_DOWN)) testRectangle->y += GetFrameTime() *200.0f;
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
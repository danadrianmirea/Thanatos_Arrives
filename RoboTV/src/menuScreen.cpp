#include "menuScreen.h"

namespace gamespace
{
	menuScreen::menuScreen(int windowWidth,int windowHeight) : screen(windowWidth, windowHeight)
	{
		exitNumber = 1;
	}


	menuScreen::~menuScreen()
	{
	}

	void menuScreen::Init() 
	{
		active = true;
		elapsedScreenTime = 0.f;

		gameCursor = new cursor();
		gameObjectList.push_front(gameCursor);

		button* testButton = new button((float)(screenWidth / 2),(float)(screenHeight / 2), "PLAY", -55);
		buttonList.push_front(testButton);
		gameObjectList.push_front(testButton);

		testButton = new button((float)(screenWidth / 2), (float)(screenHeight / 2) + buttonOffset, "SOUND", -76);
		buttonList.push_front(testButton);
		gameObjectList.push_front(testButton);


		HideCursor();

	}
	void menuScreen::Update() 
	{
		gameCursor->UpdateCursor(GetMousePosition().x, GetMousePosition().y);

		for (std::list<gameObject*>::iterator it = gameObjectList.begin(); it != gameObjectList.end(); it++)
		{
			if ((*it)->active)
				(*it)->Update(GetFrameTime());
		}
	}
	
	void menuScreen::Draw()
	{
		ClearBackground(BLACK);

		for (std::list<gameObject*>::iterator it = gameObjectList.begin(); it != gameObjectList.end(); it++)
		{
			if ((*it)->visible)
				(*it)->Draw();
		}
	}
	void menuScreen::Destroy() 
	{
		gameObjectList.erase(gameObjectList.begin(), gameObjectList.end());
	}
}
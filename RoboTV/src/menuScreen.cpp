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

		button* testButton = new button((float)(screenWidth / 2),(float)(screenHeight / 2), "PLAY", -55, buttonOptions::play);
		buttonList.push_front(testButton);
		gameObjectList.push_front(testButton);

		testButton = new button((float)(screenWidth / 2), (float)(screenHeight / 2) + buttonOffset, "SOUND", -76, buttonOptions::sound);
		buttonList.push_front(testButton);
		gameObjectList.push_front(testButton);

		testButton = new button((float)(screenWidth / 2), (float)(screenHeight / 2) + buttonOffset * 2, "EXIT", -55, buttonOptions::exit);
		buttonList.push_front(testButton);
		gameObjectList.push_front(testButton);

		HideCursor();
		currentOption = none;
	}
	void menuScreen::Update() 
	{
		gameCursor->UpdateCursor(GetMousePosition().x, GetMousePosition().y);
		
		for (std::list<gameObject*>::iterator it = gameObjectList.begin(); it != gameObjectList.end(); it++)
		{
			if ((*it)->active)
				(*it)->Update(GetFrameTime());
		}


		currentOption = none;

		if (IsMouseButtonPressed(0))
		{
			for (std::list<button*>::iterator it = buttonList.begin(); it != buttonList.end(); it++)
			{
				if ((*it)->active)
				{
					if (CheckCollisionRecs(gameCursor->actualRectangle, (*it)->actualRectangle))
					{
						currentOption = (*it)->currentOption;
					}
				}
			}
		}
		switch (currentOption)
		{
		case gamespace::none:
			break;
		case gamespace::play:
			break;
		case gamespace::credits:
			break;
		case gamespace::options:
			break;
		case gamespace::exit:
			exitNumber = -1;
			active = false;
			break;
		case gamespace::sound:
			break;
		default:
			break;
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
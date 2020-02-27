#include "menuScreen.h"

namespace gamespace
{
	menuScreen::menuScreen()
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

	}
	void menuScreen::Update() 
	{
		for (std::list<gameObject*>::iterator it = gameObjectList.begin(); it != gameObjectList.end(); it++)
		{
			if ((*it)->active)
				(*it)->Update(GetFrameTime());
		}
	}
	
	void menuScreen::Draw()
	{
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
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

		player= new playerCharacter(500.f, 250.f);
		gameObjectList.push_front(player);

		background = new sprite(500.f, 250.f, 720.f, 480.f, "../res/assets/jail.png", 240, 160);
		gameObjectList.push_front(background);
	}

	void gameScreen::Update()
	{
		elapsedScreenTime += GetFrameTime();
		
		for (std::list<gameObject*> ::iterator it = gameObjectList.begin(); it != gameObjectList.end(); it++)
		{
			if((*it)->active)
			(*it)->Update(GetFrameTime());
		}
	}

	void gameScreen::Draw()
	{
		ClearBackground(BLACK);
		std::list<gameObject*> ::iterator it;
		for (it = gameObjectList.begin(); it != gameObjectList.end(); it++)
		{
			if((*it)->visible)
			(*it)->Draw();
		}
	}
}
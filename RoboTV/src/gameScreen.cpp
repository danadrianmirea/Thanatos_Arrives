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

		gameCursor = new cursor();
		gameObjectList.push_front(gameCursor);

		player= new thanatos(500.f, 250.f);
		gameObjectList.push_front(player);

		thanatosDrone = new drone(player);
		gameObjectList.push_front(thanatosDrone);

		testWall = new rectangle(300.f, 200.f, 30.f, 30.f, RED);
		gameObjectList.push_front(testWall);

		background = new sprite(500.f, 250.f, 720.f, 480.f, "../res/assets/jail.png", 240, 160);
		gameObjectList.push_front(background);

		gameCamera.target = { player->actualRectangle.x, player->actualRectangle.y };
		gameCamera.offset = { 0,0 };
		gameCamera.rotation = 0.0f;
		gameCamera.zoom = 1.5f;

		HideCursor();
	}

	void gameScreen::Update()
	{
		elapsedScreenTime += GetFrameTime();
		
		gameCursor->UpdateCursor(GetMousePosition().x, GetMousePosition().y);
		for (std::list<gameObject*> ::iterator it = gameObjectList.begin(); it != gameObjectList.end(); it++)
		{
			if((*it)->active)
			(*it)->Update(GetFrameTime());
		}

		thanatosDrone->UpdateDrone(gameCursor);

		if (!player->CoolideWithWall(testWall)) 
		{
			player->UpdateSafePosition();
		}

		gameCamera.target = { player->actualRectangle.x,  player->actualRectangle.y };
		gameCamera.offset = { -player->actualRectangle.x + 500,  -player->actualRectangle.y + 290};
		//DrawText(TextFormat("%1.1f", elapsedScreenTime), 190, 200, 20, LIGHTGRAY);
	}

	void gameScreen::Draw()
	{
		ClearBackground(BLACK);

		BeginMode2D(gameCamera);
		std::list<gameObject*> ::iterator it;
		for (it = gameObjectList.begin(); it != gameObjectList.end(); it++)
		{
			if((*it)->visible)
			(*it)->Draw();
		}
		EndMode2D();
	}
}
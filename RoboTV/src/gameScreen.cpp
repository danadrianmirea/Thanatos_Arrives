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

		player = new thanatos(100.f, 50.f, gameCursor);
		gameObjectList.push_front(player);

		thanatosDrone = new drone(player);
		gameObjectList.push_front(thanatosDrone);

		testPadaros = new padaros(150.f, 50.f);
		gameObjectList.push_front(testPadaros);

		rectangle* leftWall = new rectangle(-360.f, -240.f, 39.f, 480.f, RED);
		wallLayer.push_front(leftWall);

		rectangle* righttWall = new rectangle(331.f, -240.f, 39.f, 480.f, RED);
		wallLayer.push_front(righttWall);

		rectangle* topWall = new rectangle(-360.f, -240.f, 720.f, 46.f, RED);
		wallLayer.push_front(topWall);

		rectangle* bottomWall = new rectangle(-360.f, 205.f, 720.f, 46.f, RED);
		wallLayer.push_front(bottomWall);

		background = new sprite(0.f, 0.f, 720.f, 480.f, "../res/assets/jail.png", 240, 160);
		gameObjectList.push_front(background);

		gameCamera.target = { player->actualRectangle.x, player->actualRectangle.y };
		gameCamera.offset = { 0,0 };
		gameCamera.rotation = 0.0f;
		gameCamera.zoom = 2.0f;

		HideCursor();
	}

	void gameScreen::Update()
	{
		elapsedScreenTime += GetFrameTime();

		gameCursor->UpdateCursor(GetMousePosition().x - gameCamera.offset.x, GetMousePosition().y - gameCamera.offset.y);

		for (std::list<gameObject*> ::iterator it = gameObjectList.begin(); it != gameObjectList.end(); it++)
		{
			if ((*it)->active)
				(*it)->Update(GetFrameTime());
		}

		thanatosDrone->UpdateDrone(gameCursor);

		//manage collisions

		bool isPlayerSafe = true;
		for (std::list<rectangle*>::iterator it = wallLayer.begin(); it != wallLayer.end(); it++)
		{
			if ((*it)->active)
				if (player->CoolideWithWall((*it)))
					isPlayerSafe = false;
		}

		if (isPlayerSafe)
			player->UpdateSafePosition();



		gameCamera.target = { player->actualRectangle.x,  player->actualRectangle.y };
		gameCamera.offset = { -player->actualRectangle.x + 1920 / 2,  -player->actualRectangle.y + 1080 / 2 };
	}

	void gameScreen::Draw()
	{
		ClearBackground(BLACK);

		BeginMode2D(gameCamera);
		std::list<gameObject*> ::iterator it;
		for (it = gameObjectList.begin(); it != gameObjectList.end(); it++)
		{
			if ((*it)->visible)
				(*it)->Draw();
		}
		EndMode2D();
		//DrawText(TextFormat("%1.1f", elapsedScreenTime), 190, 200, 20, LIGHTGRAY);
	}
}
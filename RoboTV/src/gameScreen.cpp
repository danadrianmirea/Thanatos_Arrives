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
		waveManagerInstance = new waveManager();

		elapsedScreenTime = 0.f;

		gameCursor = new cursor();
		gameObjectList.push_front(gameCursor);

		player = new thanatos(100.f, 50.f, gameCursor);
		gameObjectList.push_front(player);

		for (int i = 0; i < maxPadaros; i++)
		{
			testPadaros = new padaros(0.f, 0.f);
			gameObjectList.push_front(testPadaros);
			availablePadaros.push_front(testPadaros);
			enemyLayer.push_front(testPadaros);
		}

		for (int i = 0; i < maxSfaira; i++)
		{
			testSfaira = new sfaira(0.f, 0.f);
			gameObjectList.push_front(testSfaira);
			availableSfaira.push_front(testSfaira);
			enemyLayer.push_front(testSfaira);
		}

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
		waveManagerInstance->spawnNextWave(availablePadaros, availableSfaira);
	}

	void gameScreen::Update()
	{
		elapsedScreenTime += GetFrameTime();

		gameCursor->UpdateCursor(GetMousePosition().x - gameCamera.offset.x, GetMousePosition().y - gameCamera.offset.y);
		
		//Update all gameObjects
		for (std::list<gameObject*> ::iterator it = gameObjectList.begin(); it != gameObjectList.end(); it++)
		{
			if ((*it)->active)
				(*it)->Update(GetFrameTime());
		}

		//Update enemies
		for (std::list<enemy*>::iterator it = enemyLayer.begin(); it != enemyLayer.end(); it++)
		{
			if ((*it)->active)
				(*it)->UpdateEnemy({ player->actualRectangle.x, player->actualRectangle.y });
		}


		//manage collisions

		//player->walls
		bool isPlayerSafe = true;
		for (std::list<rectangle*>::iterator it = wallLayer.begin(); it != wallLayer.end(); it++)
		{
			if ((*it)->active)
				if (player->CoolideWithWall((*it)))
					isPlayerSafe = false;
		}

		if (isPlayerSafe)
			player->UpdateSafePosition();

		//enemies->walls
		bool isEnemySafe;
		{
			isEnemySafe = true;

			for (std::list<enemy*>::iterator it = enemyLayer.begin(); it != enemyLayer.end(); it++)
			{
				if ((*it)->active)
				{
					for (std::list<rectangle*>::iterator it2 = wallLayer.begin(); it2 != wallLayer.end(); it2++)
					{
						if ((*it2)->active)
							if ((*it)->CollideWithWall((*it2)->actualRectangle))
								isEnemySafe = false;
					}
				}

				if (isEnemySafe)
					(*it)->UpdateSafePosition();
			}
		}

		//player against enemy attacks

		rectangle* enemyAttack;
		for (std::list<enemy*>::iterator it = enemyLayer.begin(); it != enemyLayer.end(); it++)
		{
			enemyAttack = nullptr;

			if ((*it)->active)
			{
				enemyAttack = (*it)->CheckIfAttackingPlayer(player->AABB);
				if (enemyAttack != nullptr)
				{
					player->RecieveDamage({ enemyAttack->actualRectangle.x, enemyAttack->actualRectangle.y }, (*it)->attackDamage);
				}
			}
		}

		//enemies against player attacks

		attack* collidingAttack;
		for (std::list<enemy*>::iterator it = enemyLayer.begin(); it != enemyLayer.end(); it++)
		{
			if ((*it)->active)
			{
				collidingAttack = player->CheckIfAttackingEnemy((*it)->actualRectangle);
				if(collidingAttack != nullptr)
				{
					(*it)->RecieveDamage({ collidingAttack->actualRectangle.x, collidingAttack->actualRectangle.y }, collidingAttack->attackDamage);
				}
			}
		}

		//camera

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

	void gameScreen::Destroy() 
	{
		gameObjectList.erase(gameObjectList.begin(), gameObjectList.end());
		wallLayer.erase(wallLayer.begin(), wallLayer.end());
	}
}
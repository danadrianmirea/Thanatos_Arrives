#include "gameScreen.h"

#include <math.h>

#include "rectangle.h"

namespace gamespace
{
	gameScreen::gameScreen(int windowWidth, int windowHeight) : screen(windowWidth, windowHeight)
	{
		exitNumber = 0;
		gameMusic = LoadMusicStream("../res/assets/battle.ogg");
	}


	gameScreen::~gameScreen()
	{
		UnloadMusicStream(gameMusic);
	}

	void gameScreen::Init()
	{
		active = true;
		waveManagerInstance = new waveManager();
		waveTimer = 0.f;
		elapsedScreenTime = 0.f;

		//player initialization

		gameCursor = new cursor();
		gameObjectList.push_front(gameCursor);

		player = new thanatos(100.f, 50.f, gameCursor);
		gameObjectList.push_front(player);

		//enemy initialization

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

		for (std::list<enemy*>::iterator it = enemyLayer.begin(); it != enemyLayer.end(); it++)
		{
			(*it)->active = false;
		}

		//wall settings

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

		//camera settings

		gameCamera.target = { player->actualRectangle.x, player->actualRectangle.y };
		gameCamera.offset = { 0,0 };
		gameCamera.rotation = 0.0f;
		gameCamera.zoom = 2.0f;

		HideCursor();

		if (!IsMuted())
		{
			StopMusicStream(gameMusic);
			PlayMusicStream(gameMusic);
			SetMusicVolume(gameMusic, 0.6f);
		}

		//spawn settings

		waveManagerInstance->spawnList.push_back({ -240.f, 150.f });
		waveManagerInstance->spawnList.push_back({ 240.f, 150.f });
		waveManagerInstance->spawnList.push_back({ -240.f, -150.f });
		waveManagerInstance->spawnList.push_back({ 240.f, -150.f });
		waveManagerInstance->spawnList.push_back({ 0.f, 150.f });
		waveManagerInstance->spawnList.push_back({ 0.f, -150.f });
		waveManagerInstance->spawnList.push_back({ -240.f, 0.f });
		waveManagerInstance->spawnList.push_back({ 240.f, 0.f });

		//wave Settings

		wave wave0;
		wave0.enemyList.push_back({ padarosType, 1 });
		wave0.enemyList.push_back({ padarosType, 2 });
		wave0.enemyList.push_back({ padarosType, 3 });
		wave0.enemyList.push_back({ sfairaType, 4 });

		waveManagerInstance->waveList.push_front(wave0);
		waveManagerInstance->ResetWaveIterator();
		liveEnemies = 0;
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
		liveEnemies = 0;
		for (std::list<enemy*>::iterator it = enemyLayer.begin(); it != enemyLayer.end(); it++)
		{
			if ((*it)->active)
			{
				(*it)->UpdateEnemy({ player->actualRectangle.x, player->actualRectangle.y });
				liveEnemies++;
			}
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
		gameCamera.offset = { -player->actualRectangle.x + screenWidth / 2,  -player->actualRectangle.y + screenHeight / 2 };


		//sound
		if (!IsMuted())
			UpdateMusicStream(gameMusic);

		//update waves
		if (liveEnemies <= 0 && !waveManagerInstance->levelCleared)
		{
			waveTimer += GetFrameTime();
			if (waveTimer > timeBetweenWaves)
			{
				waveManagerInstance->SpawnNextWave(availablePadaros, availableSfaira);
				waveTimer = 0.f;
				liveEnemies = 4000000;
			}
		}

		//endgame
		if ((liveEnemies <= 0 && waveManagerInstance->levelCleared) || !player->active) 
		{
			exitNumber = 1;
			active = false;
		}
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
		if (player->active)
		{
			DrawText(TextFormat("HEALTH: %1i", player->GetCurrentHealth()), screenWidth - 300, screenHeight - 50, 40, RED);
			DrawText(TextFormat("AMMO: %1i", player->GetCurrentResource()), screenWidth - 300, screenHeight - 100, 40, BLUE);
		}
	}

	void gameScreen::Destroy() 
	{
		gameObjectList.erase(gameObjectList.begin(), gameObjectList.end());
		availablePadaros.erase(availablePadaros.begin(), availablePadaros.end());
		availableSfaira.erase(availableSfaira.begin(), availableSfaira.end());
		wallLayer.erase(wallLayer.begin(), wallLayer.end());
		delete waveManagerInstance;
	}
}
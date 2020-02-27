#include "flowManager.h"

#include "raylib.h"
#include "gameScreen.h"
#include "menuScreen.h"

namespace flowspace {
	flowManager::flowManager()
	{
	}


	flowManager::~flowManager()
	{
	}

	void flowManager::InitGame()
	{
		// Initialization options and setup
		const int screenWidth = 1920;
		const int screenHeight = 1080;
		InitWindow(screenWidth, screenHeight, "Thanatos Arrives");
		SetConfigFlags(FLAG_VSYNC_HINT);
		//ToggleFullscreen();

		SetTargetFPS(60);
		gamespace::screen* menuScreenInstance = new gamespace::menuScreen(screenWidth,screenHeight);
		gamespace::screen* gameScreenInstance = new gamespace::gameScreen(screenWidth, screenHeight);
		activeScreen = menuScreenInstance;
		screenList.push_back(gameScreenInstance);
		screenList.push_back(menuScreenInstance);
		activeScreen->Init();
		GameLoop();
	}

	void flowManager::EndGame()
	{
		delete activeScreen;
		CloseWindow();
	}

	void flowManager::GameLoop()
	{
		while (activeScreen->exitNumber != -1)
		{
			while (activeScreen->active)
			{
				// Update
				activeScreen->Update();
				// Draw
				BeginDrawing();
				activeScreen->Draw();
				EndDrawing();

				if (IsKeyDown(KEY_LEFT_ALT) && IsKeyDown(KEY_F4))
					CloseWindow();
			}

			if (!activeScreen->active)
			{
				if (activeScreen->exitNumber == -1)
				{
					activeScreen->Destroy();
					//CloseWindow();
				}
				else
				{
					activeScreen->Destroy();
					activeScreen = screenList[activeScreen->exitNumber];
					activeScreen->Init();
				}
			}
		}
		activeScreen->Destroy();
		EndGame();
	}
}
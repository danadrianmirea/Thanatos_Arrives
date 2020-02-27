#include "flowManager.h"

#include "raylib.h"
#include "gameScreen.h"

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
		gamespace::screen* gameScreenInstance = new gamespace::gameScreen;
		activeScreen = gameScreenInstance;
		screenList.push_back(activeScreen);
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
		while (!WindowShouldClose())
		{
			while (activeScreen->active)
			{
				// Update
				activeScreen->Update();
				// Draw
				BeginDrawing();
				activeScreen->Draw();
				EndDrawing();
			}

			if (!activeScreen->active) 
			{
				activeScreen->Destroy();
				activeScreen = screenList[activeScreen->exitNumber];
				activeScreen->Init();
			}
		}
		activeScreen->Destroy();
		EndGame();
	}
}
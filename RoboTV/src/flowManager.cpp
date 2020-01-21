#include "flowManager.h"

#include "raylib.h"

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
		const int screenWidth = 800;
		const int screenHeight = 450;

		InitWindow(screenWidth, screenHeight, "Thanatos Arrives");

		SetTargetFPS(60);
		GameLoop();
	}

	void flowManager::EndGame() 
	{
		CloseWindow();
	}

	void flowManager::GameLoop() 
	{
		while (!WindowShouldClose())
		{
			// Update

			// Draw
			BeginDrawing();

			ClearBackground(RAYWHITE);
			DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

			EndDrawing();
		}

		EndGame();
	}
}
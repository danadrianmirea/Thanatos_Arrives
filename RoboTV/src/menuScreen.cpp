#include "menuScreen.h"

namespace gamespace
{
	menuScreen::menuScreen(int windowWidth, int windowHeight) : screen(windowWidth, windowHeight)
	{
		exitNumber = 1;
		InitAudioDevice();
		menuMusic = LoadMusicStream("../res/assets/menu.ogg");
	}


	menuScreen::~menuScreen()
	{
		UnloadMusicStream(menuMusic);
	}

	void menuScreen::Init()
	{
		active = true;
		showCredits = false;
		elapsedScreenTime = 0.f;

		gameCursor = new cursor();
		gameObjectList.push_front(gameCursor);

		logo = new sprite(screenWidth / 2.f, (screenHeight / 2.f) - (float)buttonOffset * 3, 680.f, 320.f, "../res/assets/logo.png", 34, 16);
		gameObjectList.push_front(logo);

		sprite* controls = new sprite(screenWidth / 2.f + 550.f, screenHeight / 2.f + 100.f, 500.f, 320.f, "../res/assets/controls.png", 50, 32);
		gameObjectList.push_front(controls);

		button* testButton = new button((float)(screenWidth / 2), (float)(screenHeight / 2), "PLAY", -55, buttonOptions::play);
		buttonList.push_front(testButton);
		gameObjectList.push_front(testButton);

		testButton = new button((float)(screenWidth / 2), (float)(screenHeight / 2) + buttonOffset, "SOUND", -76, buttonOptions::sound);
		buttonList.push_front(testButton);
		gameObjectList.push_front(testButton);

		testButton = new button((float)(screenWidth / 2), (float)(screenHeight / 2) + buttonOffset * 2, "CREDITS", -105, buttonOptions::credits);
		buttonList.push_front(testButton);
		gameObjectList.push_front(testButton);

		backFromCreditsButton = new button((float)(screenWidth / 2), (float)(screenHeight / 2) + buttonOffset * 3, "GO BACK", -105, buttonOptions::credits);

		testButton = new button((float)(screenWidth / 2), (float)(screenHeight / 2) + buttonOffset * 3, "EXIT", -55, buttonOptions::exit);
		buttonList.push_front(testButton);
		gameObjectList.push_front(testButton);

		HideCursor();
		currentOption = none;

		Mute(false);

		
		StopMusicStream(menuMusic);
		PlayMusicStream(menuMusic);
		SetMusicVolume(menuMusic, 0.6f);
	}
	void menuScreen::Update()
	{
		UpdateMusicStream(menuMusic);
		gameCursor->UpdateCursor(GetMousePosition().x, GetMousePosition().y);

		for (std::list<gameObject*>::iterator it = gameObjectList.begin(); it != gameObjectList.end(); it++)
		{
			if ((*it)->active)
				(*it)->Update(GetFrameTime());
		}


		currentOption = none;

		if (IsMouseButtonPressed(0))
		{
			if (!showCredits)
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
			else
				if (CheckCollisionRecs(gameCursor->actualRectangle, backFromCreditsButton->actualRectangle))
					currentOption = credits;
		}
		switch (currentOption)
		{
		case gamespace::none:
			break;
		case gamespace::play:
			active = false;
			exitNumber = 0;
			break;
		case gamespace::credits:
			showCredits = !showCredits;
			break;
		case gamespace::options:
			break;
		case gamespace::exit:
			exitNumber = -1;
			active = false;
			break;
		case gamespace::sound:
			if (!IsMuted())
			{
				CloseAudioDevice();
				Mute(true);
			}
			else
			{
				Mute(false);
				InitAudioDevice();
				StopMusicStream(menuMusic);
				PlayMusicStream(menuMusic);
				PlayMusicStream(menuMusic);
			}

			break;
		default:
			break;
		}
	}

	void menuScreen::Draw()
	{
		ClearBackground(BLACK);

		if (!showCredits)
		{
			for (std::list<gameObject*>::iterator it = gameObjectList.begin(); it != gameObjectList.end(); it++)
			{
				if ((*it)->visible)
					(*it)->Draw();
			}
		}
		else
		{
			logo->Draw();
			backFromCreditsButton->Draw();
			gameCursor->Draw();
			DrawText("Design, Art and Programming", screenWidth / 2 - 300, screenHeight / 2 - 50, 40, WHITE);
			DrawText("Julian Serulnikov Kohen", screenWidth / 2 - 260, screenHeight / 2 , 40, RED);
			DrawText("Music and Sound", screenWidth / 2 - 200, screenHeight / 2 + 100, 40, WHITE);
			DrawText("Ayrton GfXFactor Izquierdo", screenWidth / 2 - 300, screenHeight / 2 + 150, 40, SKYBLUE);
		}
		DrawText(TextFormat("version %1.1f", gameVersion), screenWidth - 320, screenHeight - 60, 40, WHITE);
	}
	void menuScreen::Destroy()
	{
		gameObjectList.erase(gameObjectList.begin(), gameObjectList.end());
	}
}
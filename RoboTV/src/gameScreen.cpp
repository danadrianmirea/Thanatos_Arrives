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
		testRec = new rectangle(500.f, 250.f, 200.f, 200.f, RED);
		gameObjectList.push_front(testRec);
		testSprite = new animatedSprite(500.f, 250.f, 200.f, 200.f, "../res/assets/thanatos_spritesheet.png", 2, 3, 8, 8);
		gameObjectList.push_front(testSprite);
		animationData newAnimation;
		newAnimation.animationTime = 3.f;
		newAnimation.frameList.push_back({ 0,0 });
		newAnimation.frameList.push_back({ 1,0 });
		testSprite->NewAnimation(newAnimation);
		//testSprite->spritesheet = LoadTexture("../res/assets/thanatos_spritesheet.png");
	}

	void gameScreen::Update()
	{
		elapsedScreenTime += GetFrameTime();

		if (IsKeyDown(KEY_RIGHT))
			testRec->Move(GetFrameTime() * 200.f, 0.f);

		if (IsKeyDown(KEY_LEFT))
			testRec->Move(-GetFrameTime() * 200.f, 0.f);

		if (IsKeyDown(KEY_UP))
			testRec->Move(0.f, -GetFrameTime() * 200.f);

		if (IsKeyDown(KEY_DOWN))
			testRec->Move(0.f, GetFrameTime() * 200.f);

		testSprite->UpdateAnimation(GetFrameTime());
	}

	void gameScreen::Draw()
	{
		ClearBackground(BLACK);
		std::list<gameObject*> ::iterator it;
		for (it = gameObjectList.begin(); it != gameObjectList.end(); it++)
		{
			(*it)->Draw();
		}

		DrawText(TextFormat("%1.1f", testSprite->currentAnimTime), 190, 200, 20, LIGHTGRAY);
	}
}
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

		testSprite = new animatedSprite(500.f, 250.f, 24.f, 24.f, "../res/assets/thanatos_spritesheet.png", 2, 3, 8, 8);
		gameObjectList.push_front(testSprite);
		animationData newAnimation;
		newAnimation.animationTime = 3.f;
		newAnimation.frameList.insert(newAnimation.frameList.end(), { 0,1 });
		newAnimation.frameList.insert(newAnimation.frameList.end(), { 1,1 });
		testSprite->NewAnimation(newAnimation);

		background = new sprite(500.f, 250.f, 720.f, 480.f, "../res/assets/jail.png", 240, 160);
		gameObjectList.push_front(background);
	}

	void gameScreen::Update()
	{
		elapsedScreenTime += GetFrameTime();

		if (IsKeyDown(KEY_RIGHT))
			testSprite->Move(GetFrameTime() * 200.f, 0.f);

		if (IsKeyDown(KEY_LEFT))
			testSprite->Move(-GetFrameTime() * 200.f, 0.f);

		if (IsKeyDown(KEY_UP))
			testSprite->Move(0.f, -GetFrameTime() * 200.f);

		if (IsKeyDown(KEY_DOWN))
			testSprite->Move(0.f, GetFrameTime() * 200.f);

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
			(*it)->Draw();
		}
	}
}
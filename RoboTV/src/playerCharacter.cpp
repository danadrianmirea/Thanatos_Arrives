#include "playerCharacter.h"

namespace gamespace
{

	playerCharacter::playerCharacter()
	{
	}

	playerCharacter::playerCharacter(float xPosition, float yPosition)
		:animatedSprite(xPosition, yPosition, 24.f, 24.f, "../res/assets/thanatos_spritesheet.png", 2, 3, 8, 8)
	{
		idleAnim.animationTime = 1.f;
		idleAnim.addFrame({ 0,0 });
		idleAnim.addFrame({ 1,0 });

		walkAnim.animationTime = 0.6f;
		walkAnim.addFrame({ 0,1 });
		walkAnim.addFrame({ 1,1 });

		attackAnim.animationTime = 0.3f;
		attackAnim.addFrame({ 0,2 });
		attackAnim.addFrame({ 0,0 });
		attackAnim.addFrame({ 0,2 });
		attackAnim.addFrame({ 0,0 });

		damageAnim.animationTime = 0.5f;
		damageAnim.addFrame({ 1,2 });

		NewAnimation(idleAnim);
	}



	playerCharacter::~playerCharacter()
	{
	}

	void playerCharacter::Update(float frameTime)
	{
		animatedSprite::Update(frameTime);
		if (IsKeyDown(KEY_RIGHT))
			Move(frameTime * 200.f, 0.f);

		if (IsKeyDown(KEY_LEFT))
			Move(-frameTime * 200.f, 0.f);

		if (IsKeyDown(KEY_UP))
			Move(0.f, -frameTime * 200.f);

		if (IsKeyDown(KEY_DOWN))
			Move(0.f, frameTime * 200.f);
	}
}
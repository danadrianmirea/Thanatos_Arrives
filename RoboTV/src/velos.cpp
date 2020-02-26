#include "velos.h"

namespace gamespace
{
	velos::velos(bool friendly) : attack(24.f, 24.f, "../res/assets/velos.png", 2, 1, 8, 8)
	{
		if(!friendly)
			spriteTexture = LoadTexture("../res/assets/daivelos.png");
		animationData attackAnimation;
		attackAnimation.addFrame({ 0,0 });
		attackAnimation.addFrame({ 1,0 });
		attackAnimation.animationTime = 0.2f;
		NewAnimation(attackAnimation);

		attackRadius = velosAttackRadius;
		attackDamage = velosAttackDamage;
		attackDuration = velosAttackDuration;
	}


	velos::~velos()
	{
	}

	void velos::Update(float frameTime)
	{
		animatedSprite::Update(frameTime);

		Move(moveDirection.x * frameTime * moveSpeed, moveDirection.y * frameTime * moveSpeed);

		if (activeTime >= attackDuration)
		{
			active = false;
			visible = false;
		}

		activeTime += frameTime;
	}

	void velos::UpdateTarget(Vector2 newPosition)
	{
		moveDirection.x = newPosition.x - actualRectangle.x;
		moveDirection.y = newPosition.y - actualRectangle.y;

		float magnitude = sqrtf(moveDirection.x * moveDirection.x + moveDirection.y * moveDirection.y);

		moveDirection.x = moveDirection.x / magnitude;
		moveDirection.y = moveDirection.y / magnitude;

		activeTime = 0.f;
	}
}
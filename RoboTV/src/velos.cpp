#include "velos.h"

namespace gamespace
{
	velos::velos() : attack(24.f, 24.f, "../res/assets/velos.png", 2, 1, 8, 8)
	{
		attackRadius = 10.f;
		animationData attackAnimation;
		attackAnimation.addFrame({ 0,0 });
		attackAnimation.addFrame({ 1,0 });
		attackAnimation.animationTime = 0.2f;

		NewAnimation(attackAnimation);
		attackRadius = 8.f;
	}


	velos::~velos()
	{
	}

	void velos::Update(float frameTime)
	{
		animatedSprite::Update(frameTime);
		Move(moveDirection.x * frameTime * moveSpeed, moveDirection.y * frameTime * moveSpeed);
	}

	void velos::Activate(Vector2 position, float attackRotation, bool yInverted) 
	{
		attack::Activate(position, attackRotation, yInverted);
		moveDirection.x = cosf(attackRotation);
		moveDirection.y = sinf(attackRotation);
	}
}
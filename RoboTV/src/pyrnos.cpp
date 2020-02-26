#include "pyrnos.h"

namespace gamespace
{
	pyrnos::pyrnos() : attack(24.f, 24.f, "../res/assets/pyrnos.png", 2, 3, 8, 8)
	{
		attackRadius = 10.f;
		animationData attackAnimation;
		attackAnimation.addFrame({ 0,0 });
		attackAnimation.addFrame({ 1,0 });
		attackAnimation.addFrame({ 0,1 });
		attackAnimation.addFrame({ 1,1 });
		attackAnimation.addFrame({ 0,2 });
		attackAnimation.animationTime = attackDuration;

		NewAnimation(attackAnimation);
	}


	pyrnos::~pyrnos()
	{

	}

	void pyrnos::Update(float frameTime)
	{
		animatedSprite::Update(frameTime);
		activeTime += frameTime;
		if (activeTime >= attackDuration)
		{
			active = false;
			visible = false;
		}
	}
}
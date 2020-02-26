#include "pyrnos.h"

namespace gamespace
{
	pyrnos::pyrnos() : attack(24.f, 24.f, "../res/assets/pyrnos.png", 2, 3, 8, 8)
	{
		attackRadius = pyrnosAttackRadius;


		animationData attackAnimation;
		attackAnimation.addFrame({ 0,0 });
		attackAnimation.addFrame({ 1,0 });
		attackAnimation.addFrame({ 0,1 });
		attackAnimation.addFrame({ 1,1 });
		attackAnimation.addFrame({ 0,2 });
		attackAnimation.animationTime = pyrnosAttackDuration;

		NewAnimation(attackAnimation);

		attackDamage = pyrnosAttackDamage;
	}


	pyrnos::~pyrnos()
	{

	}

	void pyrnos::Update(float frameTime)
	{
		animatedSprite::Update(frameTime);
		activeTime += frameTime;
		if (activeTime >= pyrnosAttackDuration)
		{
			active = false;
			visible = false;
		}
	}
}
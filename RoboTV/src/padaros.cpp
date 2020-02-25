#include "padaros.h"

namespace gamespace
{
	padaros::padaros()
	{

	}

	padaros::padaros(float xPosition, float yPosition) 
		: animatedSprite(xPosition, yPosition, 24.f, 24.f, "../res/assets/padaros.png", 2, 5, 8, 8)
	{
		idleAnim.animationTime = 1.1f;
		idleAnim.addFrame({ 0,0 });
		idleAnim.addFrame({ 1,0 });

		walkAnim.animationTime = 0.6f;
		walkAnim.addFrame({ 0,1 });
		walkAnim.addFrame({ 1,1 });

		windupAnim.animationTime = 0.2f;
		windupAnim.addFrame({ 0,2 });
		windupAnim.addFrame({ 1,2 });

		attackAnim.animationTime = 0.2f;
		attackAnim.addFrame({ 0,3 });

		damageAnim.animationTime = 0.2f;
		damageAnim.addFrame({ 1,3 });
		damageAnim.addFrame({ 0,4 });

		NewAnimation(idleAnim);
	}

	padaros::~padaros()
	{

	}

	void padaros::Update(float frameTime) 
	{
		animatedSprite::Update(frameTime);
	}
}
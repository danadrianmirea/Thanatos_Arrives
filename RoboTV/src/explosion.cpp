#include "explosion.h"

namespace gamespace
{

	explosion::explosion() : animatedSprite(0.f, 0.f, 24.f, 24.f, "../res/assets/explosion.png", 2, 5, 8, 8)
	{
		animationData explosionAnimation;
		explosionAnimation.animationTime = duration;
		explosionAnimation.addFrame({ 0,0 });
		explosionAnimation.addFrame({ 1,0 });
		explosionAnimation.addFrame({ 0,1 });
		explosionAnimation.addFrame({ 1,1 });
		explosionAnimation.addFrame({ 0,2 });
		explosionAnimation.addFrame({ 1,2 });
		explosionAnimation.addFrame({ 0,3 });
		explosionAnimation.addFrame({ 1,3 });
		explosionAnimation.addFrame({ 0,4 });
		explosionAnimation.addFrame({ 1,4 });

		NewAnimation(explosionAnimation);

		activeTime = 0.f;
		active = false;
		visible = false;
	}

	

	explosion::~explosion()
	{
	}

	void explosion::Update(float frameTime) 
	{
		animatedSprite::Update(frameTime);

		activeTime += frameTime;
		if (activeTime >= duration) 
		{
			active = false;
			visible = false;
		}
	}

	void explosion::Activate(Vector2 position) 
	{
		actualRectangle.x = position.x;
		actualRectangle.y = position.y;
		active = true;
		visible = true;
	}
}
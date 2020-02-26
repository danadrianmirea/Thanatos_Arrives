#include "attack.h"

namespace gamespace
{

	attack::attack() : animatedSprite(0.f, 0.f, 24.f, 24.f, "../res/assets/pyrnos.png", 2, 3, 8, 8)
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

		activeTime = 0.f;
		inverted = false;
		active = false;
		visible = false;
	}


	attack::~attack()
	{
	}

	void attack::Draw()
	{
		//DrawCircle(actualRectangle.x, actualRectangle.y, attackRadius, RED); //draw hitbox ("hitcircle", yeah, I know)
		if (!inverted)
			animatedSprite::Draw();
		else
			DrawTexturePro(spriteTexture, {sourceRec.x, sourceRec.y, sourceRec.width, -sourceRec.height}, actualRectangle, origin, rotation, WHITE);
	}

	void attack::Update(float frameTime)
	{
		animatedSprite::Update(frameTime);
		activeTime += frameTime;
		if (activeTime >= attackDuration)
		{
			active = false;
			visible = false;
		}
	}

	void attack::Activate(Vector2 position, float attackRotation, bool yInverted)
	{
		if (!active)
		{
			actualRectangle.x = position.x;
			actualRectangle.y = position.y;
			rotation = attackRotation;

			active = true;
			visible = true;
			activeTime = 0.f;
			inverted = yInverted;
		}
	}

	bool attack::CheckCollisionWithEnemy(Rectangle enemyHitbox)
	{
		return CheckCollisionCircleRec({ actualRectangle.x, actualRectangle.y }, attackRadius, enemyHitbox);
	}
}
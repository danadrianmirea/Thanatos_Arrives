#include "attack.h"

namespace gamespace
{

	attack::attack() : animatedSprite(0.f,0.f,24.f,24.f,"../res/assets/pyrnos.png",2,3,8,8)
	{
		attackRadius = 10.f;
	}


	attack::~attack()
	{
	}

	void attack::Draw() 
	{
		DrawCircle(actualRectangle.x, actualRectangle.y, attackRadius, RED); //draw hitbox ("hitcircle", yeah, I know)
		animatedSprite::Draw();
	}

	void attack::Activate(Vector2 position, float attackRotation)
	{
		actualRectangle.x = position.x;
		actualRectangle.y = position.y;
		rotation = attackRotation;
	}

	void attack::CheckCollisionWithEnemy(const animatedSprite* enemy) 
	{
	
	}
}
#include "attack.h"

namespace gamespace
{

	attack::attack()
	{

	}

	attack::attack(float recWidth, float recHeight, const char* textureFile,
		int columns, int rows, int frameWidth, int frameHeight) : animatedSprite(0.f, 0.f, recWidth, recHeight, textureFile, columns, rows, frameWidth, frameHeight)
	{
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
#include "thanatos.h"

namespace gamespace
{

	thanatos::thanatos()
	{
	}

	thanatos::thanatos(float xPosition, float yPosition)
		:animatedSprite(xPosition, yPosition, 24.f, 24.f, "../res/assets/thanatos_spritesheet.png", 2, 3, 8, 8)
	{
		AABB.x = actualRectangle.x + AABBxOffset;
		AABB.y = actualRectangle.y + AABByOffset;
		AABB.width = actualRectangle.width +AABBWidthOffset;
		AABB.height = actualRectangle.height + AABBHeightOffset;

		moveDirection.x = 0.f;
		moveDirection.y = 0.f;

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



	thanatos::~thanatos()
	{

	}

	void thanatos::Draw()
	{
		//DrawRectangleRec(AABB, RED);  //see hitbox compared to the character
		animatedSprite::Draw();
	}

	void thanatos::Update(float frameTime)
	{

		moveDirection.x = 0.f;
		moveDirection.y = 0.f;

		animatedSprite::Update(frameTime);
		if (IsKeyDown(KEY_D))
			moveDirection.x += 1;
		if (IsKeyDown(KEY_A))
			moveDirection.x -= 1;

		if (IsKeyDown(KEY_W))
			moveDirection.y -= 1;

		if (IsKeyDown(KEY_S))
			moveDirection.y += 1;

		if(moveDirection.x != 0.f)
		moveDirection.x = moveDirection.x / sqrtf(moveDirection.x * moveDirection.x + moveDirection.y * moveDirection.y);
		if(moveDirection.y != 0.f)
		moveDirection.y = moveDirection.y / sqrtf(moveDirection.x * moveDirection.x + moveDirection.y * moveDirection.y);

		Move(moveDirection.x * moveSpeed * frameTime, moveDirection.y * moveSpeed* frameTime);

		AABB.x = actualRectangle.x + AABBxOffset;
		AABB.y = actualRectangle.y + AABByOffset;
	}

	void thanatos::UpdateSafePosition()
	{
		safePosition = { AABB.x, AABB.y };
	}

	bool thanatos::CoolideWithWall(const rectangle* wall)
	{
		if (CheckCollisionRecs(AABB, wall->actualRectangle))
		{
			if (safePosition.x + AABB.width <= wall->actualRectangle.x ||
				safePosition.x >= wall->actualRectangle.x + wall->actualRectangle.width)
			{
				actualRectangle.x = safePosition.x - AABBxOffset;
			}

			if (safePosition.y + AABB.height <= wall->actualRectangle.y ||
				safePosition.y >= wall->actualRectangle.y + wall->actualRectangle.height)
			{
				actualRectangle.y = safePosition.y - AABByOffset;
			}


			return true;
		}
		else
		{
			return false;
		}
	}
}
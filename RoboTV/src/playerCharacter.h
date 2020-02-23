#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include "animatedSprite.h"

namespace gamespace
{
	const float AABBxOffset = -8.5f;
	const float AABByOffset = -4.f;
	const float AABBWidthOffset= -9.5f;
	const float AABBHeightOffset= -8.f;


	class playerCharacter : public animatedSprite
	{
	public:
		playerCharacter();
		playerCharacter(float xPosition, float yPosition);
		~playerCharacter();
		void Draw();
		void Update(float frameTime);
		void UpdateSafePosition();
		bool CoolideWithWall(const rectangle* wall);

	private:
		animationData idleAnim;
		animationData walkAnim;
		animationData attackAnim;
		animationData damageAnim;
		Rectangle AABB;
		Vector2 safePosition;
	};
}
#endif
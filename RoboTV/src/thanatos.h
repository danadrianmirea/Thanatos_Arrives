#ifndef THANATOS_H
#define THANATOS_H

#include "animatedSprite.h"

namespace gamespace
{
	const float AABBxOffset = -8.5f;
	const float AABByOffset = -4.f;
	const float AABBWidthOffset= -9.5f;
	const float AABBHeightOffset= -8.f;
	const float wallCollisionOffset = 3.f;
	
	const float moveSpeed = 150.f;

	const float attackTime = 0.3f;
	const float dashTime = 0.2f;
	const float damageTime = 0.5f;

	enum thanatosStates
	{
		idle, walking, attacking, dashing, damaged
	};

	class thanatos : public animatedSprite
	{
	public:
		thanatos();
		thanatos(float xPosition, float yPosition);
		~thanatos();
		void Draw();
		void Update(float frameTime);
		void UpdateSafePosition();
		bool CoolideWithWall(const rectangle* wall);

	private:
		void ChangeState(thanatosStates newState);

		float stateTimer;
		animationData idleAnim;
		animationData walkAnim;
		animationData attackAnim;
		animationData dashAnim;
		animationData damageAnim;
		Rectangle AABB;
		Vector2 safePosition;
		Vector2 moveDirection;
		thanatosStates state;
	};
}
#endif
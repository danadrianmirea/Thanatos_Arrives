#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include "animatedSprite.h"

namespace gamespace
{
	class playerCharacter : public animatedSprite
	{
	public:
		playerCharacter();
		playerCharacter(float xPosition, float yPosition);
		~playerCharacter();

	private:
		animationData idleAnim;
		animationData walkAnim;
		animationData attackAnim;
		animationData damageAnim;
	};
}
#endif
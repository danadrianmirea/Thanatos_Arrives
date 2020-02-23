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
		void Update(float frameTime);

	private:
		animationData idleAnim;
		animationData walkAnim;
		animationData attackAnim;
		animationData damageAnim;
	};
}
#endif
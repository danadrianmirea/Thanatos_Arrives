#include "playerCharacter.h"

namespace gamespace
{

	playerCharacter::playerCharacter()
	{
	}

	playerCharacter::playerCharacter(float xPosition, float yPosition)
		:animatedSprite(xPosition, yPosition, 24.f, 24.f, "../res/assets/thanatos_spritesheet.png", 2, 3, 8, 8)
	{
		
	}



	playerCharacter::~playerCharacter()
	{
	}
}
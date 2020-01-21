#ifndef FLOWMANAGER_H
#define FLOWMANAGER_H

#include "screen.h"

namespace flowspace
{

	class flowManager
	{
	public:
		flowManager();
		~flowManager();
		void InitGame();
		void EndGame();

	private:
		void GameLoop();
		gamespace::screen* activeScreen;
	};
}
#endif // !FLOWMANAGER_H
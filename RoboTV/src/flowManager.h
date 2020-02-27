#ifndef FLOWMANAGER_H
#define FLOWMANAGER_H

#include <vector>

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
		std::vector<gamespace::screen*>screenList;
		gamespace::screen* activeScreen;
	};
}
#endif // !FLOWMANAGER_H
#ifndef FLOWMANAGER_H
#define FLOWMANAGER_H

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
	};
}
#endif // !FLOWMANAGER_H
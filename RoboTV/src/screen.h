#ifndef SCREEN_H
#define SCREEN_H

namespace gamespace
{
	class screen
	{
	public:
		bool active;
		screen();
		~screen();
		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;
	};
}
#endif // !SCREEN_H
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

namespace gamespace
{
	class gameObject
	{
	public:
		gameObject();
		~gameObject();
		bool active;
		float x, y;
	};
}
#endif
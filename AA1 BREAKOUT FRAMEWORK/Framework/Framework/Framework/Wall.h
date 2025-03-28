#pragma once
#include "GameObject.h"

class Wall : public GameObject {
protected:
	bool isBottom;
public:
	Wall(Vector2 pos, ConsoleColor c, bool b)
		: GameObject(pos, '#', c), isBottom(b) {}

	bool GetIsBottom()  { return isBottom; }
};


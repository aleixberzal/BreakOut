#pragma once
#include "GameObject.h"

class Brick : public GameObject {
protected:
	bool destroyed;
public:
	Brick(Vector2 _pos, ConsoleColor c)
		: GameObject(_pos, '=', c), destroyed(false) {}
	 bool GetDestroyed()  { return destroyed; }
	 void Destroy() { destroyed = true; }

	void Render() override {
		if (!destroyed) {
			GameObject::Render();
		}
	}
};
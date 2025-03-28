#pragma once
#include "GameObject.h"
#include <Windows.h>

class Pad : public GameObject {
protected:
	int width;
	int mapSize;
public:
	Pad(Vector2 _pos, ConsoleColor c, int w, int _mapSize)
		:GameObject(_pos, '_', c), width(w), mapSize(_mapSize) {}
	int GetWidth()  { return width; }
	void Update() override;
	void Render() override;
};
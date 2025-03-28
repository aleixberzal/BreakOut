#pragma once
#include "Vector2.h"
#include "ConsoleControl.h"

class GameObject {
protected:
	Vector2 position;
	char charToPrint;
	ConsoleColor color;
public:
	GameObject(Vector2 _position, char _c, ConsoleColor _color)
		: position(_position), charToPrint(_c), color(_color) {}

	Vector2 GetPosition()  { return position; }
	char GetCharToPrint()  { return charToPrint; }

	virtual void Render();
	virtual void Update() {}
};
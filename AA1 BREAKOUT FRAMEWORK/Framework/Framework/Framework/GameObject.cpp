#include "GameObject.h"

void GameObject::Render()
{
	ConsoleSetColor(color, BLACK);
	ConsoleXY(position.x, position.y);
	std::cout << charToPrint;
}

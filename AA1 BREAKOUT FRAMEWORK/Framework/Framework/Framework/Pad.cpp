#include "Pad.h"

void Pad::Update(){
	if (GetAsyncKeyState('A') != 0) {
		bool isOutside = position.x - width <= 1;
		if(!isOutside)
			position.x--;
	}
	if (GetAsyncKeyState('D') != 0) {
		bool isOutside = position.x + width >= mapSize - 2;
		if (!isOutside)
			position.x++;
	}
}

void Pad::Render() {
	//render the center
	GameObject::Render();
	
	for (int i = 1; i <= width; i++) {
		//Dreta
		ConsoleXY(position.x + i, position.y);
		std::cout << charToPrint;
		//Esquerra
		ConsoleXY(position.x - i, position.y);
		std::cout << charToPrint;
	}
}

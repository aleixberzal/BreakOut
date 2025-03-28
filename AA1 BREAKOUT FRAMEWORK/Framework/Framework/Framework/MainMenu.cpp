#include "MenuScene.h"

void MenuScene::Update()
{
	if (GetAsyncKeyState('1') != 0) {
		nextScene = "Ranking"; //Selects the next scene 
		finished = true; //Indicates that this scene is finished
	}
	else if (GetAsyncKeyState('2') != 0) {
		nextScene = "Gameplay";
		finished = true;

	}
	else if (GetAsyncKeyState('3') != 0) {
		nextScene = "Credits";
		finished = true;
	}
	else if (GetAsyncKeyState('4') != 0) {
		nextScene = "Exit";
		finished = true;
	}
}

void MenuScene::Render()
{
	std::cout << " 1- Ranking\n 2- Gameplay\n 3- Exit\n 4- Scene";
}

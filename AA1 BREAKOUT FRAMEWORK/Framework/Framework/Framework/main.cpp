#include <Windows.h>
#include <iostream>

#include <cstdlib>
#include <time.h>

#include "MenuScene.h"
#include "GameplayScene.h"
#include "RankingScene.h"
#include <map>

int main(){
	srand(time(NULL));

	//The scenes are stored in a map
	// KEY -> Name of the scene
	// VALUE -> Pointer to the scene object
	// 
	//We store the current scene to update and render it.

	std::map<std::string, Scene*> scenes;
	Scene* currentScene;

	//Create the scenes
	scenes.emplace("Menu", new MenuScene());
	scenes.emplace("Gameplay", new GameplayScene());
	scenes.emplace("Ranking", new RankingScene());

	//Select the starting scene, in this case, the main menu
	currentScene = scenes["Menu"];
	currentScene->OnEnter();

	while (true) {

		//UPDATE
		currentScene->Update();

		//RENDER
		system("cls");
		ConsoleSetColor(WHITE, BLACK);
		currentScene->Render();

		//SCENE TRANSITIONING
		if (currentScene->IsFinished()) { //Check if the scene is finished

			currentScene->OnExit(); //IF finished, exit the scene
			if (currentScene->GetNextScene() == "Exit") { //IF the scene wants to go to "Exit", end the game
				return 0; //End the game
			}
			currentScene = scenes[currentScene->GetNextScene()]; //Select the next scene in the map with the string
			currentScene->OnEnter(); //Start the next scene
		}

		//CONTROL TIME (FPS)
		Sleep(100); //100ms sleep, 10 FPS
	}
}
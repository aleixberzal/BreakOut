#pragma once
#include "GameObject.h"
#include <vector>
#include <string>

class Scene {
protected:
	std::vector<GameObject*> objects;
	std::string nextScene;
	bool finished;
public:
	Scene() {
		nextScene = "Exit"; //A scene that hasn't got a next scene set will exit the game
		finished = false;
	}

	virtual void OnEnter() { finished = false; } //This prevents errors when u reopen a scene,
												 //Do not forget to include this part if you
												 //Override this function!
	virtual void Update() {
		for (GameObject* o : objects) {
			o->Update();
		}
	}
	virtual void Render() {
		for (GameObject* o : objects) {
			o->Render();
		}
	}

	virtual void OnExit() {}

	//GETTERS
	bool IsFinished() const { return finished; }
	std::string GetNextScene() const { return nextScene; }
};
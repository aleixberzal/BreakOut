#pragma once
#include "Scene.h"

#include "Wall.h"
#include "Brick.h"
#include "Pad.h"
#include "Ball.h"

#define MAP_SIZE 15

class GameplayScene : public Scene {
public:
	 void OnEnter() override;
	 void Update() override;
	 void Render() override;
	 void OnExit() override;
};


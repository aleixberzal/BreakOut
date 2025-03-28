#pragma once
#include "Scene.h"

#include "Wall.h"
#include "Brick.h"
#include "Pad.h"
#include "Ball.h"

#define MAP_SIZE 15

class GameplayScene : public Scene {
public:
	virtual void OnEnter() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void OnExit() override;
};


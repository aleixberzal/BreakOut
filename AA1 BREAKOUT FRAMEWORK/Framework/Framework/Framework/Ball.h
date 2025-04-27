#pragma once
#include "GameObject.h"
#include "Wall.h"
#include "Brick.h"
#include "Pad.h"
#include "GameplayScene.h"
#include "Vector2.h"
#include <vector>

class Ball : public GameObject {
protected:
    Vector2 direction;
    std::vector<GameObject*> objects;
    GameplayScene* gameplayScene;

    int score;
    bool touchedPad;
    int consecutiveBlocks;

    Vector2 CalculateCollision(GameObject* other);

public:
    Ball(Vector2 _pos, ConsoleColor c, std::vector<GameObject*> _objects, GameplayScene* _scene)
        : GameObject(_pos, '@', c), objects(_objects), gameplayScene(_scene),
        direction(Vector2(1, 1)), score(0), touchedPad(true), consecutiveBlocks(0) {
    }

    void Update() override;
    void Render() override;
    void Enter();

    int GetScore() const { return score; }
    Vector2 GetPosition() const { return position; }
};

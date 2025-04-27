#pragma once
#include "GameObject.h"
#include "Wall.h"
#include "Brick.h"
#include "Pad.h"


#include <vector>

class GameplayScene;

class Ball : public GameObject {
protected:
    Vector2 direction;
    std::vector<GameObject*> objects;
    GameplayScene* gameplayScene; // Referencia para actualizar score y vidas

    int score;              // Puntuación del jugador
    bool touchedPad;        // Flag para saber si tocamos la pala
    int consecutiveBlocks;  // Contador de bloques destruidos sin tocar la pala

    Vector2 CalculateCollision(GameObject* other);

public:
    // Constructor
    Ball(Vector2 _pos, ConsoleColor c, std::vector<GameObject*> _objects, GameplayScene* _scene)
        : GameObject(_pos, '@', c), objects(_objects), gameplayScene(_scene),
        direction(Vector2(1, 1)), score(0), touchedPad(true), consecutiveBlocks(0) {
    }

    void Update() override;
    void Render() override;
    void Enter();

    Vector2 GetPosition() const { return position; } // Getter para la posición, necesario para GameplayScene
};
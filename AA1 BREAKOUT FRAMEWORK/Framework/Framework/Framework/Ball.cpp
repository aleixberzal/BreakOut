#include "Ball.h"
#include "GameplayScene.h"
#include "Wall.h"
#include "Brick.h"
#include "Pad.h"
#include "ConsoleControl.h"
#include <iostream>

Vector2 Ball::CalculateCollision(GameObject* other)
{
    int vertical = 0;
    int horizontal = 0;

    for (int i = 0; i < objects.size(); i++) {
        bool top = (other->GetPosition() + Vector2(0, -1)) == objects[i]->GetPosition();
        bool bottom = (other->GetPosition() + Vector2(0, 1)) == objects[i]->GetPosition();
        vertical += (int)top + (int)bottom;

        bool left = (other->GetPosition() + Vector2(-1, 0)) == objects[i]->GetPosition();
        bool right = (other->GetPosition() + Vector2(1, 0)) == objects[i]->GetPosition();
        horizontal += (int)left + (int)right;
    }

    Vector2 outDir = direction;

    if (vertical == 0 && horizontal == 0) {
        vertical = rand() % 2 > 0;
        horizontal = rand() % 2 > 0;
    }

    if (vertical >= horizontal)
        outDir.x = -outDir.x;
    if (horizontal > vertical)
        outDir.y = -outDir.y;

    return outDir;
}

void Ball::Enter() {
    /*We instantiate the variables we will use to make our score*/
    score = 0;
    touchedPad = true;
    consecutiveBlocks = 0;
}

void Ball::Update()
{
    for (GameObject* go : objects) {
        if (go == this) {
            continue;
        }

        if (go->GetCharToPrint() == '_') {
            int padX = go->GetPosition().x;
            int padY = go->GetPosition().y;
            int padWidth = dynamic_cast<Pad*>(go)->GetWidth();
            int ballX = position.x;
            int ballY = position.y;

            if (direction.y > 0 && ballY == padY ) {
                if (ballX >= padX - padWidth && ballX <= padX + padWidth) {
                    if (ballX < padX) {
                        direction.x = -1;
                    }
                    else if (ballX > padX) {
                        direction.x = 1;
                    }
                    else {
                        direction.x = 0;
                    }
                    direction.y = -1;
                    position.y -= 1;
                    touchedPad = true;
                    consecutiveBlocks = 0;
                }
            }
        }
        else {
            bool collision = position == go->GetPosition();
            if (collision) {
                if (Wall* w = dynamic_cast<Wall*>(go)) {
                    direction = CalculateCollision(go);
                    if (w->GetIsBottom()) {
                        if (gameplayScene != nullptr) {
                            gameplayScene->LoseLife();
                        }
                        touchedPad = true;
                        consecutiveBlocks = 0;
                    }
                }
                else if (Brick* b = dynamic_cast<Brick*>(go)) {
                    if (!b->GetDestroyed()) {
                        /*We destroy the bricks in case the ball collides with it*/
                        b->Destroy();
                        direction = CalculateCollision(go);
                        /*We get our standard 15p, multiplied by the consecutive blocks we are hitting without our pad touching the ball*/
                        int sumarPuntos = 15 + (consecutiveBlocks * 5);
                        score += sumarPuntos;
                        consecutiveBlocks++;
                        touchedPad = false;
                    }
                }
            }
        }
    }

    position = position + direction;
}

void Ball::Render() {
    GameObject::Render();
    /*We put the player score under his lives*/
    ConsoleXY(0, MAP_SIZE + 1);
    std::cout << "Score: " << score;
}
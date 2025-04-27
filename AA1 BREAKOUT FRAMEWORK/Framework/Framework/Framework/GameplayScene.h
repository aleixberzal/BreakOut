#pragma once
#include "Scene.h"

#include "Wall.h"
#include "Brick.h"
#include "Pad.h"
#include "Ball.h"

#define MAP_SIZE 15

class GameplayScene : public Scene {
private:
    int score = 0;
    int lives = 3;
    int combo = 0;

public:
    void OnEnter() override {
        score = 0;
        lives = 3;
        combo = 0;

        // Wall generation
        for (int i = 0; i < MAP_SIZE; i++) {
            Wall* topWall = new Wall(Vector2(i, 0), YELLOW, false);
            Wall* bottomWall = new Wall(Vector2(i, MAP_SIZE - 1), YELLOW, true);
            if (i > 0 && i < MAP_SIZE - 1) {
                Wall* leftSideWall = new Wall(Vector2(0, i), YELLOW, false);
                Wall* rightSideWall = new Wall(Vector2(MAP_SIZE - 1, i), YELLOW, false);
                objects.push_back(leftSideWall);
                objects.push_back(rightSideWall);
            }
            objects.push_back(topWall);
            objects.push_back(bottomWall);
        }

        // Bricks
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j < MAP_SIZE - 1; j++) {
                objects.push_back(new Brick(Vector2(j, i), CYAN));
            }
        }

        // PAD
        objects.push_back(new Pad(Vector2(MAP_SIZE / 2, (MAP_SIZE * 3) / 4), WHITE, 1, MAP_SIZE));

        // BALL
        objects.push_back(new Ball(Vector2(2, MAP_SIZE / 2), WHITE, objects, this));
    }

    void Update() override {
        Scene::Update();

        if (lives <= 0 || AllBricksDestroyed()) {
            finished = true;
            nextScene = "Ranking";
        }
    }

    void Render() override {
        Scene::Render();

        ConsoleXY(0, MAP_SIZE + 1);
        std::cout << "Score: " << score << " Lives: " << lives;
    }

    void OnExit() override {
        for (GameObject* o : objects)
            delete o;

        objects.clear();
    }

    void AddScore(int basePoints) {
        combo++;
        score += basePoints + (combo * 5);
    }

    void ResetCombo() {
        combo = 0;
    }

    void LoseLife() {
        lives--;
    }

    bool AllBricksDestroyed() {
        for (GameObject* go : objects) {
            if (Brick* b = dynamic_cast<Brick*>(go)) {
                if (!b->GetDestroyed())
                    return false;
            }
        }
        return true;
    }

    int GetLives() const { return lives; }
    void SetLives(int l) { lives = l; }
};

#pragma once
#include "GameObject.h"
#include "Wall.h"
#include "Brick.h"
#include "Pad.h"

#include <vector>

class Ball : public GameObject {
protected:
	Vector2 direction;
	std::vector<GameObject*> objects;

	Vector2 CalculateCollision( GameObject* other);
	int score;
	int consecutiveBlocks;
	/*Important flag*/
	bool touchedPad;
public:
	Ball(Vector2 _pos, ConsoleColor c, std::vector<GameObject*> _objects)
		: GameObject(_pos, '@', c), objects(_objects), direction(Vector2(1, 1)), score(0), consecutiveBlocks(0), touchedPad(false) {}
	void Update() override;
	void Enter();
	void Render() override;
	void SetPosition(Vector2 newPos) {
		position = newPos;
	}
};
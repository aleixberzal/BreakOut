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
	/*Ball can still move diagonally, we just have to change the initial direction of the ball with the vector2 (1,1), and then we can see it will still move right*/
	Ball(Vector2 _pos, ConsoleColor c, std::vector<GameObject*> _objects)
		: GameObject(_pos, '@', c), objects(_objects), direction(Vector2(0, 1)), score(0), consecutiveBlocks(0), touchedPad(false) {}
	void Update() override;
	void Enter();
	void Render() override;
	void SetPosition(Vector2 newPos) {
		position = newPos;
	}
};
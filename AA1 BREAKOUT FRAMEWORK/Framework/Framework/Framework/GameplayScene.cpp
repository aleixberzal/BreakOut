#include "GameplayScene.h"

void GameplayScene::OnEnter()
{

	lives = 3;
	//Wall generation
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

	//Bricks
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j < MAP_SIZE - 1; j++) {
			objects.push_back(new Brick(Vector2(j, i), CYAN));
		}
	}

	//PAD
	objects.push_back(new Pad(Vector2(MAP_SIZE / 2, (MAP_SIZE * 3) / 4), WHITE, 1, MAP_SIZE));
	
	//BALL
	objects.push_back(new Ball(Vector2(MAP_SIZE / 2, (MAP_SIZE * 3) / 4 - 5), WHITE, objects));
}
void GameplayScene::Update()
{
	Scene::Update();

	
	for (GameObject* o : objects) {
		o->Update();
	}

	Ball* ball = nullptr;
	int brickCount = 0; 
	/*We chech all the gameObjects during the update and every brick goes into our total brick count*/
	for (GameObject* o : objects) {
		if (Ball* b = dynamic_cast<Ball*>(o)) {
			ball = b;
		}
		else if (dynamic_cast<Brick*>(o)) {
			brickCount++; 
		}
	}

	/*Either when the player touches the ground 3 times, or the brick count is null, the game stops*/
	int ballHeight = 1;
	if (ball != nullptr && ball->GetPosition().y + ballHeight >= MAP_SIZE - 1) {
		lives--;
		if (lives == -2) {
			nextScene = "Exit";
			finished = true;
		}
	}

	if (brickCount == 0) {
		nextScene = "Exit";  
		finished = true;
	}
}

void GameplayScene::Render()
{
	Scene::Render();
	/*We render th elives bellow the map*/
	ConsoleXY(0, MAP_SIZE);  
	std::cout << "Lives: " << lives + 2;

}

void GameplayScene::OnExit()
{
	for (GameObject* o : objects)
		delete o;

	objects.clear();
}

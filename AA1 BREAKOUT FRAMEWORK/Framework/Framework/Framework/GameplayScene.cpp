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
	objects.push_back(new Ball(Vector2(2, MAP_SIZE / 2), WHITE, objects));
}

void GameplayScene::Update()
{
	Scene::Update();

	/*We check the update of all our objects, this way we can check if the player is trying to move left or right*/
	for (GameObject* o : objects) {
		o->Update();
	}

	Ball* ball = nullptr;
	for (GameObject* o : objects) {
		if (Ball* b = dynamic_cast<Ball*>(o)) {
			ball = b;
			break;
		}
	}
	 
	/*In case our player hits the lowest wall we get one live, now hardcoded because its not functional*/
	int ballHeight = 1; 
	if (ball != nullptr && ball->GetPosition().y + ballHeight >= MAP_SIZE - 1) {
		lives--; 

		if (lives == -2) {
			nextScene = "Exit"; 
			finished = true;    
		}
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

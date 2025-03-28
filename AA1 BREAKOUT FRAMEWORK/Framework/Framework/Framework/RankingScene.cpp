#include "RankingScene.h"

void RankingScene::Update()
{
	if (GetAsyncKeyState('R') != 0) {
		finished = true;
	}
}

void RankingScene::Render()
{
	std::cout << "Press R to go back to the menu;";
}

#include "RankingScene.h"
#include "ConsoleControl.h"
#include <fstream>
#include <iostream>
#include <conio.h>

void RankingScene::OnEnter() {
    std::ifstream file("rankings.dat", std::ios::binary);
    if (file.is_open()) {
        PlayerData p;
        while (file.read(reinterpret_cast<char*>(&p), sizeof(PlayerData))) {
            rankings.push_back(p);
        }
        file.close();
    }
}

void RankingScene::Update() {
    if (_kbhit()) {
        finished = true;
        nextScene = "Menu";
    }
}

void RankingScene::Render() {
    system("cls");
    ConsoleXY(0, 0);
    std::cout << "Top Rankings:\n\n";
    for (const PlayerData& p : rankings) {
        std::cout << p.name << " - " << p.score << "\n";
    }
}

void RankingScene::OnExit() {
    rankings.clear();
}

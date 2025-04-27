#pragma once
#include "Scene.h"
#include <vector>
#include <string>

struct PlayerData {
    char name[20];
    int score;
};

class RankingScene : public Scene {
private:
    std::vector<PlayerData> rankings;
public:
    void OnEnter() override;
    void Update() override;
    void Render() override;
    void OnExit() override;
};

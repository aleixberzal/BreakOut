#pragma once
#include "Scene.h"

class RankingScene : public Scene {
protected:
	//Vector of pairs-> 1st is a string a 2nd is the score
	//If you don't undestand std::pair<>, you can use another approach
	std::vector<std::pair<std::string, int>> scores;
	
public:
	RankingScene() {
		nextScene = "Menu";
		//Constructor TODO -> load scores
	}
	~RankingScene() = default; //Destructor TODO -> save scores
	void Update() override;
	void Render() override;
};
#pragma once
#include <iostream>
#include "Scene.h"

class CreditScene : public Scene {
public:
    void showCredits();
    void OnEnter() override;
    void Update() override;
    void Render() override;
};

#pragma once
#include <iostream>
#include "Scene.h"

class CreditScene : public Scene {
public:
    void showCredits();
    void Render() override;
};

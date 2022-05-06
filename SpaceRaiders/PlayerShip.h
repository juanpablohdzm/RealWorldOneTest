#pragma once
#include "GameObject.h"
#include "Renderer.h"

class PlayerShip : public GameObject
{
public:
    PlayerShip()
    {
        sprite_ = RS_Player;
    }

    void Update() override;
};

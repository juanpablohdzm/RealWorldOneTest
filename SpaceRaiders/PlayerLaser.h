#pragma once
#include "Laser.h"
#include "Renderer.h"

class PlayerShip;

class PlayerLaser : public Laser
{
public:
    PlayerLaser(PlayerShip* player) : Laser(), player_(player)
    {
        sprite_ = RS_PlayerLaser;
    }

    void Update() override;


private:
    PlayerShip* player_;
};

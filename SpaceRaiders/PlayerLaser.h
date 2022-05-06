#pragma once
#include "Laser.h"
#include "Renderer.h"

class PlayerLaser : public Laser
{
public:
    PlayerLaser() : Laser()
    {
        sprite_ = RS_PlayerLaser;
    }

    void Update() override;
};

#pragma once
#include "Laser.h"
#include "Renderer.h"

class PlayerLaser : public Laser
{
public:
    PlayerLaser()
    {
        objType_ = "ot_PlayerLaser";
        sprite_ = RS_PlayerLaser;
    }

    void Update() override;
};

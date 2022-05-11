#pragma once
#include "Laser.h"
#include "../../Renderer.h"

class PlayerShip;

class PlayerLaser : public Laser
{
public:
    PlayerLaser(PlayerShip* player, const Vector2D& moveDirection) : Laser(), player_(player), moveDirection_(moveDirection)
    {
        sprite_ = RS_PlayerLaser;
    }

    void Update() override;

    void DestroyLaser() override;
private:
    PlayerShip* player_;
    Vector2D moveDirection_;
};

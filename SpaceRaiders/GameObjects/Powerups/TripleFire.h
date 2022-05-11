#pragma once
#include "PowerUp.h"
#include "../../RaiderSprites.h"

class TripleFire : public PowerUp
{
public:
    TripleFire(float duration): PowerUp(duration)
    {
        sprite_ = RS_TripleFire;
    }
protected:
    void Activate(PlayerShip* player) override;
};

#pragma once
#include "PowerUp.h"
#include "../../RaiderSprites.h"

class SpeedBoost : public PowerUp
{
public:
    SpeedBoost(float duration): PowerUp(duration)
    {
        sprite_ = RS_SpeedBoost;
    }
    
protected:
    void Activate(PlayerShip* player) override;
    void Destroy() override;
};

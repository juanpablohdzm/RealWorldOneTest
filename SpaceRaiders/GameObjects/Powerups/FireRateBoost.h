#pragma once
#include "PowerUp.h"
#include "../../RaiderSprites.h"

class FireRateBoost : public PowerUp
{
public:
    FireRateBoost(float duration): PowerUp(duration)
    {
        sprite_ = RS_FireRateBoost;
    }
protected:
    void Activate(PlayerShip* player) override;
    void Destroy() override;
    
};

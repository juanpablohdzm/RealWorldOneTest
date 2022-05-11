#pragma once
#include "PowerUp.h"

class FireRateBoost : public PowerUp
{
public:
    FireRateBoost(float duration): PowerUp(duration)
    {
        sprite_ = 'F';
    }
protected:
    void Activate(PlayerShip* player) override;
    void Destroy() override;
    
};

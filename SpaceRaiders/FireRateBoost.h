#pragma once
#include "PowerUp.h"

class FireRateBoost : public PowerUp
{
protected:

    FireRateBoost(float duration): PowerUp(duration)
    {
        sprite_ = 'F';
    }
    
    void Activate(PlayerShip* player) override;
    void Destroy() override;
    
};

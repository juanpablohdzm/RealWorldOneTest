#pragma once
#include "PowerUp.h"

class SpeedBoost : public PowerUp
{
protected:

    SpeedBoost(float duration): PowerUp(duration)
    {
        sprite_ = 'S';
    }
    
    void Activate(PlayerShip* player) override;
    void Destroy() override;
};

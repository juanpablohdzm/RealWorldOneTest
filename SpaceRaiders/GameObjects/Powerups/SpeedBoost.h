#pragma once
#include "PowerUp.h"

class SpeedBoost : public PowerUp
{
public:
    SpeedBoost(float duration): PowerUp(duration)
    {
        sprite_ = 'S';
    }
    
protected:
    void Activate(PlayerShip* player) override;
    void Destroy() override;
};

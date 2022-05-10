#pragma once
#include "PowerUp.h"

class TripleFire : public PowerUp
{
protected:

    TripleFire(float duration): PowerUp(duration)
    {
        sprite_ = 'T';
    }
    
    void Activate(PlayerShip* player) override;
};

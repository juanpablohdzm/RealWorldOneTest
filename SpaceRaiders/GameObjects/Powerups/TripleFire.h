#pragma once
#include "PowerUp.h"

class TripleFire : public PowerUp
{
public:
    TripleFire(float duration): PowerUp(duration)
    {
        sprite_ = 'T';
    }
protected:
    void Activate(PlayerShip* player) override;
};

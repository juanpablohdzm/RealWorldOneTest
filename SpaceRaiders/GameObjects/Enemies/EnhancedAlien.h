#pragma once
#include <iostream>

#include "Alien.h"
#include "../../RaiderSprites.h"

class EnhancedAlien : public Alien
{
public:
    EnhancedAlien()
    {
        velocity_ = 1.0f;
        sprite_ = RS_BetterAlien;
        points_ = 20;
        healthComponent_.SetHealth(2.0f);
    }
};

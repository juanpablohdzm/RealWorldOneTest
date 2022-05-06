#pragma once
#include "Alien.h"

class EnhancedAlien : public Alien
{
    EnhancedAlien()
    {
        velocity_ = 1.0f;
        sprite_ = RS_BetterAlien;
    }
};

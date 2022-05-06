#pragma once
#include "Alien.h"
#include "Renderer.h"

class EnhancedAlien : public Alien
{
public:
    EnhancedAlien()
    {
        velocity_ = 1.0f;
        sprite_ = RS_BetterAlien;
    }
};

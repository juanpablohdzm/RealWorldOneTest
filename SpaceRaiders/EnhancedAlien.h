#pragma once
#include "Alien.h"
#include "Renderer.h"

class EnhancedAlien : public Alien
{
public:
    EnhancedAlien() : Alien()
    {
        velocity_ = 1.0f;
        sprite_ = RS_BetterAlien;
        points_ = 20;
    }
};

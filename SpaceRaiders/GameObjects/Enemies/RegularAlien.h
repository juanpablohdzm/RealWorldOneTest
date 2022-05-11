#pragma once

#include "Alien.h"
#include "../../Renderer.h"

class RegularAlien : public Alien
{
public:
    RegularAlien() : Alien()
    {
        velocity_ = 0.5f;
        sprite_ = RS_Alien;
    }

    void Update() override;

private:

    void Transform();
    
};

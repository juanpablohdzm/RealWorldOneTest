#pragma once
#include "../GameObject.h"
#include "../../RaiderSprites.h"

class Explosion : public GameObject
{
public:
    // Explosion lasts 5 ticks before it dissappears
    Explosion() : GameObject(), timer_(5)
    {
        sprite_ = RS_Explosion;
    }
    
    void Update() override;

private:
    int timer_;
};

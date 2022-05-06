#pragma once
#include "GameObject.h"
#include "Renderer.h"

class Explosion : public GameObject
{
public:
    // Explosion lasts 5 ticks before it dissappears
    int timer = 5;
    Explosion()
    {
        objType_ ="ot_Explosion";
        sprite_ = RS_Explosion;
    }
    
    void Update(PlayField& world) override;
   
};

#pragma once
#include "GameObject.h"
#include "Laser.h"
#include "Renderer.h"

class AlienLaser : public Laser
{
public:
    AlienLaser()
    {
        objType_ = "ot_AlienLaser";
        sprite_ = RS_AlienLaser;
    }

    void Update() override;

protected:
    void Collision(GameObject* obj) override;
    
};

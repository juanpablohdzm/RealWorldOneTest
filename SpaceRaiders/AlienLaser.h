#pragma once
#include "GameObject.h"
#include "Laser.h"
#include "Renderer.h"

class AlienLaser : public Laser
{
public:
    AlienLaser() : Laser()
    {
        sprite_ = RS_AlienLaser;
    }

    void Update() override;

protected:
    void Collision(GameObject* obj) override;
    
};

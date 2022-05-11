#pragma once
#include "../GameObject.h"
#include "Laser.h"
#include "../../RaiderSprites.h"

class Alien;

class AlienLaser : public Laser
{
public:
    AlienLaser(Alien* alien) : Laser(), alien_(alien)
    {
        sprite_ = RS_AlienLaser;
    }

    void DestroyLaser() override;

    void Update() override;

protected:
    
    void Collision(GameObject* obj) override;

private:
    Alien* alien_;
};

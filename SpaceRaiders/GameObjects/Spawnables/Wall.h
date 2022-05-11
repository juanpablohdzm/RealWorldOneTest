#pragma once
#include "../GameObject.h"
#include "../../RaiderSprites.h"
#include "../../Components/HealthComponent.h"

class Wall : public GameObject
{
public:
    Wall() 
    {
        sprite_ = RS_Wall;
        healthComponent_ = HealthComponent(2.0f);
    }

    void Update() override;
    
};

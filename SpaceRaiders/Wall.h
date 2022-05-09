#pragma once
#include "GameObject.h"
#include "HealthComponent.h"

class Wall : public GameObject
{
public:
    Wall() 
    {
        sprite_ = 'w';
        healthComponent_ = HealthComponent(2.0f);
    }

    void Update() override;
    
};

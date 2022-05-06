#pragma once
#include "GameObject.h"
#include "HealthComponent.h"
#include "Renderer.h"


#define MAX_UPDATE_RATE  0.01f
#define TRANSFORM_ENERGY 1.0f

class Alien : public GameObject
{
public:
    Alien() : energy_(0.0f), healtComp_(1.0)
    {
        objType_"ot_AlienShip";
    }

    void Update() override;

protected:
    float direction_ = 1.f;
    float velocity_;
    float energy_;
    HealthComponent healtComp_;
};






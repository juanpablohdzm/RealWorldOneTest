#pragma once
#include <random>

#include "GameObject.h"
#include "HealthComponent.h"


#define MAX_UPDATE_RATE  0.01f
#define TRANSFORM_ENERGY 1.0f

typedef std::uniform_int_distribution<int> intRand;
typedef std::uniform_real_distribution<float> floatRand;

class Alien : public GameObject
{
public:
    Alien() : GameObject(), direction_(1.0f), velocity_(0.0f), energy_(0.0f), healthComp_(1.0)
    {
        rGen_.seed(1);
    }

    void Update() override;

    HealthComponent* GetHealthComponent() {return &healthComp_;}

protected:
    float direction_;
    float velocity_;
    float energy_;
    HealthComponent healthComp_;
    std::default_random_engine rGen_;
    
};






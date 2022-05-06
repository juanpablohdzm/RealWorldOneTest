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
    Alien() : energy_(0.0f), healtComp_(1.0)
    {
        rGen_.seed(1);
    }

    void Update() override;

    HealthComponent* GetHealthComponent() {return &healtComp_;}

protected:
    float direction_ = 1.f;
    float velocity_;
    float energy_;
    HealthComponent healtComp_;
    std::default_random_engine rGen_;
    
};






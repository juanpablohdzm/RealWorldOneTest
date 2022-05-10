#pragma once
#include <random>

#include "AlienLaser.h"
#include "GameObject.h"
#include "HealthComponent.h"


#define MAX_UPDATE_RATE  0.01f
#define TRANSFORM_ENERGY 1.0f

typedef std::uniform_int_distribution<int> intRand;
typedef std::uniform_real_distribution<float> floatRand;

class Alien : public GameObject
{
public:
    Alien() : points_(10), direction_(1.0f), velocity_(0.0f) , energy_(0.0f)
    {
        rGen_.seed(1);
    }

    void Update() override;
    
    void DespawnLaser(AlienLaser* laser);

    int GetWorthPoints() const {return points_;}
    void SpawnPowerUp();

protected:
    virtual void SpawnLaser();

    static int laserAvailableAmount;

    int points_;
    float direction_;
    float velocity_;
    float energy_;
    std::default_random_engine rGen_;
    
};






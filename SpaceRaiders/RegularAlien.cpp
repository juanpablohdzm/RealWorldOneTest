#include "stdafx.h"
#include "RegularAlien.h"

#include "EnhancedAlien.h"
#include "PlayField.h"


void RegularAlien::Update()
{
    Alien::Update();
    
    floatRand updateRate(-MAX_UPDATE_RATE, 2*MAX_UPDATE_RATE);
    energy_ += updateRate(rGen_);
    if (energy_ >= TRANSFORM_ENERGY)
        Transform();
}

void RegularAlien::Transform()
{
    auto world = PlayField::GetInstance();
    std::shared_ptr<GameObject> enhancedAlien = std::make_shared<EnhancedAlien>();
    world->AddObject(enhancedAlien);
    world->RemoveObject(this);
}

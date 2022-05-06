#include "stdafx.h"
#include "RegularAlien.h"

void RegularAlien::Update()
{
    Alien::Update();
    
    floatRand updateRate(-MAX_UPDATE_RATE, 2*MAX_UPDATE_RATE);
    energy += updateRate(rGen);
    if (energy >= TRANSFORM_ENERGY)
        Transform();
}

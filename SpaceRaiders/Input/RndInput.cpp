#include "stdafx.h"
#include "RndInput.h"

typedef std::uniform_int_distribution<int> intRand;
typedef std::uniform_real_distribution<float> floatRand;

bool RndInput::Left()
{
    const floatRand keyRate(0, 1);
    return (keyRate(rGen_) < 0.3f); 
}

bool RndInput::Right()
{
    const floatRand keyRate(0, 1);
    return (keyRate(rGen_) < 0.4f); 
}

bool RndInput::Fire()
{
    const floatRand keyRate(0, 1);
    return (keyRate(rGen_) < 0.5f); 
}

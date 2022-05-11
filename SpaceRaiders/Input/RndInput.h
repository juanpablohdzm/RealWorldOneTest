#pragma once
#include "IInput.h"
#include <random>

class RndInput : public IInput
{
public:	
    bool Left() override;
    bool Right() override;
    bool Fire() override;

private:
    std::default_random_engine rGen_;
};

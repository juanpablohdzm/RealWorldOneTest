#pragma once
#include "IInput.h"

class KeyboardInput : IInput
{
public:
    bool Left() override;
    bool Right() override;
    bool Fire() override;
};

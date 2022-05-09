#pragma once
#include "IInput.h"

class KeyboardInput : public IInput
{
public:
    bool Left() override;
    bool Right() override;
    bool Fire() override;
};

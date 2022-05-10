#include "stdafx.h"
#include "KeyboardInput.h"

#include <iostream>
#include <Windows.h>

bool KeyboardInput::Left()
{
    std::cin.clear();
    return GetKeyState('A') & 0x8000;    
}

bool KeyboardInput::Right()
{
    std::cin.clear();
    return GetKeyState('D') & 0x8000;    
}

bool KeyboardInput::Fire()
{
    std::cin.clear();
    return GetKeyState('W') & 0x8000;    
}

#include "stdafx.h"
#include "KeyboardInput.h"
#include <Windows.h>

bool KeyboardInput::Left()
{
    return GetKeyState('A') & 0x8000;    
}

bool KeyboardInput::Right()
{
    return GetKeyState('D') & 0x8000;    
}

bool KeyboardInput::Fire()
{
    return GetKeyState('W') & 0x8000;    
}

﻿#pragma once

struct IInput
{
    virtual bool Left() = 0;
    virtual bool Right() = 0;
    virtual bool Fire() = 0;
};

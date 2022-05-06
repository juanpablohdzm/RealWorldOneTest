#include "stdafx.h"
#include "Explosion.h"
#include "PlayField.h"

void Explosion::Update()
{
    timer_--;
    if (!timer_)
    {
        PlayField::GetInstance()->RemoveObject(this);
    }
}

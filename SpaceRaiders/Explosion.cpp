#include "stdafx.h"
#include "Explosion.h"
#include "PlayField.h"

void Explosion::Update()
{
    timer--;
    if (!timer)
    {
        PlayField::GetInstance()->RemoveObject(this);
    }
}

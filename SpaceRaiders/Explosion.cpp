#include "stdafx.h"
#include "Explosion.h"
#include "PlayField.h"

void Explosion::Update(PlayField& world)
{
    timer--;
    if (!timer)
    {
        world.RemoveObject(this);
        delete this;
    }
}

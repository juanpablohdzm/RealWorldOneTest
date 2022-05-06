#include "stdafx.h"
#include "Explosion.h"
#include "GameManager.h"

void Explosion::Update()
{
    timer_--;
    if (!timer_)
    {
        GameManager::GetInstance()->RemoveObject(this);
    }
}

#include "stdafx.h"
#include "PlayerLaser.h"

#include <iostream>

#include "AlienLaser.h"

#include "Alien.h"
#include "GameManager.h"
#include "PlayerShip.h"

void PlayerLaser::Update()
{
    Move({0.0f,-1.0f});

    auto world = GameManager::GetInstance();
    for (auto it : world->GetGameObjects())
    {
        if(it.get() == this) continue;
        if(dynamic_cast<PlayerLaser*>(it.get())) continue;
        if(dynamic_cast<PlayerShip*>(it.get())) continue;

        if(it->GetPosition() == pos_)
        {
            Collision(it.get());
            it->GetHealthComponent()->Damage(1);
            if (it->GetHealthComponent()->IsDead())
            {
                world->RemoveObject(it.get());
                if(auto alien = dynamic_cast<Alien*>(it.get()))
                    world->AddScore(alien->GetWorthPoints());
            }
            DestroyLaser();
            return;
        }
    }
    
    if (pos_.y() < 0)
    {
        DestroyLaser();
        return;
    }
}

void PlayerLaser::DestroyLaser()
{
    player_->DespawnLaser(this);
}

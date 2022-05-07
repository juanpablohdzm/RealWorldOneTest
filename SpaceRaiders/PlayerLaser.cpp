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

        if (auto alien  = dynamic_cast<Alien*>(it.get()))
        {
            if(it->GetPosition() == pos_)
            {
                //Spawn explosion, kill the alien that we hit
                //ToDo - add scoring
                Collision(alien);
                alien->GetHealthComponent()->Damage(1);
                if (alien->GetHealthComponent()->GetHealth() == 0)
                {
                    world->RemoveObject(it.get());
                    world->AddScore(alien->GetWorthPoints());
                }
                DestroyLaser();
                return;
            }
        }
        
        if(auto laser = dynamic_cast<AlienLaser*>(it.get()))
        {
            
            if(abs(it->GetPosition().x() - pos_.x()) < 0.5f)
            {
                Collision(laser);
                laser->DestroyLaser();
                DestroyLaser();
                return;
            }
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

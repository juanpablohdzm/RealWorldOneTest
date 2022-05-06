#include "stdafx.h"
#include "PlayerLaser.h"

#include "Alien.h"
#include "GameManager.h"
#include "PlayerShip.h"

void PlayerLaser::Update()
{
    bool deleted = false;
    Move({0.0f,-1.0f});

    auto world = GameManager::GetInstance();
    for (auto it : world->GetGameObjects())
    {
        if (dynamic_cast<Alien*>(it.get()) != nullptr && it->GetPosition().IntCmp(pos_))
        {
            deleted = true;
            //Spawn explosion, kill the alien that we hit
            //ToDo - add scoring
            Alien* alien = static_cast<Alien*>(it.get());
            Collision(alien);
            alien->GetHealthComponent()->Damage(1);
            if (alien->GetHealthComponent()->GetHealth() == 0)
                world->RemoveObject(it.get());
        }
    }
    
    if (pos_.y() < 0)
    {
        deleted = true;
    }
    
    if (deleted)
    {
        player_->DespawnLaser(this);
    }
}

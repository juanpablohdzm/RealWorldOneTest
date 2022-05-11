#include "stdafx.h"
#include "PlayerLaser.h"

#include "AlienLaser.h"

#include "../Enemies/Alien.h"
#include "../../GameManager.h"
#include "../Player/PlayerShip.h"
#include "../../PlayField.h"

void PlayerLaser::Update()
{
    Move(moveDirection_);

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
                {
                    world->AddScore(alien->GetWorthPoints());
                    alien->SpawnPowerUp();
                }
            }
            DestroyLaser();
            return;
        }
    }
    
    if (pos_.y() < 0 || pos_.x() < 0 || pos_.x() > PlayField::GetInstance()->GetBounds().x()-1)
    {
        DestroyLaser();
        return;
    }
}

void PlayerLaser::DestroyLaser()
{
    player_->DespawnLaser(this);
}

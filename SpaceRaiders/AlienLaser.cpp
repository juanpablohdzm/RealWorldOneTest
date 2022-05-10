#include "stdafx.h"
#include "AlienLaser.h"

#include "Alien.h"
#include "GameManager.h"
#include "PlayField.h"



void AlienLaser::Update()
{
    Move({0.0f,1.0f});

    auto world = GameManager::GetInstance();
    auto player = world->GetPlayerObject();
    if (player && pos_ == player->GetPosition())
    {
        DestroyLaser();
        player->GetHealthComponent()->Damage(1.0);
        if(player->GetHealthComponent()->IsDead())
            GameManager::GetInstance()->GameOver();
        return;
    }

    if (pos_.y() > PlayField::GetInstance()->GetBounds().y())
    {
        DestroyLaser();
        return;
    }
}

void AlienLaser::DestroyLaser()
{
    alien_->DespawnLaser(this);
}

void AlienLaser::Collision(GameObject* obj)
{
    Laser::Collision(obj);
    GameManager::GetInstance()->RemoveObject(obj);
}

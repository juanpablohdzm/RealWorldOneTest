#include "stdafx.h"
#include "AlienLaser.h"

#include "Alien.h"
#include "GameManager.h"
#include "PlayField.h"

void AlienLaser::Update()
{
    bool deleted = false;

    Move({0.0f,1.0f});

    auto world = GameManager::GetInstance();
    std::shared_ptr<GameObject> player = world->GetPlayerObject();
    if (player && pos_.IntCmp(player->GetPosition()))
    {
        deleted = true;
        Collision(player.get());
    }

    if (pos_.y() > PlayField::GetInstance()->GetBounds().y())
    {
        deleted = true;
    }
    
    if (deleted)
    {
        alien_->DespawnLaser(this);
    }
}

void AlienLaser::Collision(GameObject* obj)
{
    Laser::Collision(obj);
    GameManager::GetInstance()->RemoveObject(obj);
}

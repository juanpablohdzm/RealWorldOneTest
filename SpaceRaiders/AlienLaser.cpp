#include "stdafx.h"
#include "AlienLaser.h"

#include "Explosion.h"
#include "PlayField.h"

void AlienLaser::Update(PlayField& world)
{
    bool deleted = false;

    Move({0.0f,1.0f});
    
    std::shared_ptr<GameObject> player = world.GetPlayerObject();
    if (player && pos_.IntCmp(player->GetPosition()))
    {
        deleted = true;
        Collision(player.get());
    }

    if (pos_.y() > world.GetBounds().y())
    {
        deleted = true;
    }
    
    if (deleted)
    {
        world.DespawnLaser(this);
        delete this;
    }
}

void AlienLaser::Collision(GameObject* obj)
{
    Laser::Collision(obj);
    PlayField::GetInstance()->RemoveObject(obj);
}

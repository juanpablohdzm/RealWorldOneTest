#include "stdafx.h"
#include "PlayerLaser.h"

#include "PlayField.h"

void PlayerLaser::Update()
{
    bool deleted = false;
    Move({0.0f,-1.0f});

    auto world = PlayField::GetInstance();
    for (auto it : world->GetGameObjects())
    {
        if (strcmp(it->GetObjType_CStr(),"ot_AlienShip")==0 && it->GetPosition().IntCmp(pos_))
        {
            deleted = true;
            //Spawn explosion, kill the alien that we hit
            //ToDo - add scoring
            Collision(it.get());
            if (it->DecreaseHealth())
                world->RemoveObject(it.get());
        }
    }
    
    if (pos_.y() < 0)
    {
        deleted = true;
    }
    
    if (deleted)
    {
        world->DespawnLaser(this);
    }
}

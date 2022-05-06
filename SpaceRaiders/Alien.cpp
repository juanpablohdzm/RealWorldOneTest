#include "stdafx.h"
#include "Alien.h"

#include "Explosion.h"
#include "PlayField.h"

void Alien::Update()
{
    Move({direction_*velocity_,0.0f});

    auto world = PlayField::GetInstance();
    // Border check
    if (pos_.x() < 0 || pos_.x() >= world->GetBounds().x() - 1)
    {
        direction_ = -direction_;
        Move({0.0f,1.0f});
    }
		
    // Border check vertical:
    if (pos_.y() >= world->GetBounds().y() - 1)
    {
        // kill player
        std::shared_ptr<GameObject> player = world->GetPlayerObject();
        if (player && pos_.IntCmp(player->GetPosition()))
        {
            //Spawn explosion
            std::shared_ptr<GameObject> no = std::make_shared<Explosion>();
            no->SetPos(pos_);
            world->AddObject(no);
            world->RemoveObject(player.get());
        }
    }

    floatRand fireRate(0, 1);
    if (fireRate(rGen) < 0.5 && world.AlienLasers>0)
    {
        //Spawn laser
        GameObject& newLaser = *(new AlienLaser);
        newLaser.pos = pos;
        world.SpawnLaser(&newLaser);
    }
}

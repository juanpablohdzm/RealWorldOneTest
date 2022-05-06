#include "stdafx.h"
#include "PlayerShip.h"

#include "IInput.h"
#include "PlayerLaser.h"
#include "PlayField.h"

void PlayerShip::Update()
{
    auto world = PlayField::GetInstance();
    if (world->GetControllerInput()->Left())
        Move({-1.0f,0.0f});
    else if (world->GetControllerInput()->Right())
        Move({1.0f,0.0f});
	
    if (world->GetControllerInput()->Fire() && world->GetPlayerLasersAmount()>0)
    {
        //Spawn laser
        std::shared_ptr<GameObject> newLaser = std::make_shared<PlayerLaser>();
        newLaser->SetPos(pos_);
        world->SpawnLaser(newLaser);
    }
}

#include "stdafx.h"
#include "PlayerShip.h"

#include "IInput.h"
#include "PlayerLaser.h"
#include "GameManager.h"

void PlayerShip::Update()
{
    auto world = GameManager::GetInstance();
    if (world->GetControllerInput()->Left())
        Move({-direction_*speed_,0.0f});
    else if (world->GetControllerInput()->Right())
        Move({direction_*speed_,0.0f});
	
    if (world->GetControllerInput()->Fire())
    {
        Fire();
    }
}

void PlayerShip::DespawnLaser(PlayerLaser* laser)
{
    if(!laser) return;
    
    amountAvailableLasers_++;
    GameManager::GetInstance()->RemoveObject(laser);
}

void PlayerShip::Fire()
{
    if(amountAvailableLasers_ <= 0) return;

    amountAvailableLasers_--;
    std::shared_ptr<GameObject> newLaser = std::make_shared<PlayerLaser>(this);
    newLaser->SetPos(pos_);
    GameManager::GetInstance()->AddObject(newLaser);
}

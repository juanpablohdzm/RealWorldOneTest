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

    
    if (tickCount_ % fireRate_ == 0 && world->GetControllerInput()->Fire())
    {
        Fire(Vector2D{0.0f,-1.0f});
    }

    tickCount_++;
    if(tickCount_ == std::numeric_limits<int>::max())
        tickCount_ = std::numeric_limits<int>::min();
}

void PlayerShip::DespawnLaser(PlayerLaser* laser)
{
    if(!laser) return;
    
    amountAvailableLasers_++;
    GameManager::GetInstance()->RemoveObject(laser);
}

void PlayerShip::Fire(Vector2D direction)
{
    if(amountAvailableLasers_ <= 0) return;

    amountAvailableLasers_--;
    std::shared_ptr<GameObject> newLaser = std::make_shared<PlayerLaser>(this,direction);
    newLaser->SetPos(pos_);
    GameManager::GetInstance()->AddObject(newLaser);
}

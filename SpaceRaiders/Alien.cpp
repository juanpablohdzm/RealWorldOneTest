#include "stdafx.h"
#include "Alien.h"

#include "AlienLaser.h"
#include "Explosion.h"
#include "GameManager.h"
#include "PlayField.h"


void Alien::Update()
{
    Move({direction_*velocity_,0.0f});

    auto world = GameManager::GetInstance();
    // Border check
    if (pos_.x() < 0 || pos_.x() >= PlayField::GetInstance()->GetBounds().x() - 1)
    {
        direction_ = -direction_;
        Move({0.0f,1.0f});
    }
		
    // Border check vertical:
    if (pos_.y() >= PlayField::GetInstance()->GetBounds().y() - 1 || world->GetPlayerObject()->GetPosition() == pos_)
    {
        world->GameOver();
    }

    floatRand fireRate(0, 1);
    if (fireRate(rGen_) < 0.5)
    {
        SpawnLaser();
    }
}

int Alien::laserAvailableAmount = 10;

void Alien::DespawnLaser(AlienLaser* laser)
{
    laserAvailableAmount++;
    GameManager::GetInstance()->RemoveObject(laser);
}

void Alien::SpawnLaser()
{
    if(laserAvailableAmount <= 0) return;
    
    laserAvailableAmount --;
    std::shared_ptr<GameObject> laser = std::make_shared<AlienLaser>(this);
    laser->SetPos(pos_);
    GameManager::GetInstance()->AddObject(laser);
}

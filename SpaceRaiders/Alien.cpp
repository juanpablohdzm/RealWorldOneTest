#include "stdafx.h"
#include "Alien.h"

#include "AlienLaser.h"
#include "Explosion.h"
#include "FireRateBoost.h"
#include "GameManager.h"
#include "PlayField.h"
#include "SpeedBoost.h"
#include "TripleFire.h"


class PowerUp;

void Alien::Update()
{
    //Move({direction_*velocity_,0.0f});

    auto world = GameManager::GetInstance();
    // Border check
    if (pos_.x() < 0 || pos_.x() >= PlayField::GetInstance()->GetBounds().x() - 1)
    {
        direction_ = -direction_;
        Move({0.0f,1.0f});
    }
		
    //Border check vertical:
    if (pos_.y() >= PlayField::GetInstance()->GetBounds().y() - 1)
    {
       // world->GameOver();
    }

    if(world->GetPlayerObject() && world->GetPlayerObject()->GetPosition() == pos_)
    {
       // world->GameOver();
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

void Alien::SpawnPowerUp()
{
    auto world = GameManager::GetInstance();
    std::default_random_engine rGen;
    rGen.seed(1.0);
    std::uniform_int_distribution<int> random(0,10);
    if(random(rGen) <= 5)
    {
        std::uniform_int_distribution<int> powerup_choice(0,10);
        std::shared_ptr<PowerUp> powerUp = nullptr;
        auto choice = powerup_choice(rGen);
        if(choice <= 3)
        {
            powerUp = std::make_shared<SpeedBoost>(2.0);
            powerUp->SetPos(pos_);
            world->AddObject(powerUp);
        }
        if(choice > 3 && choice < 6)
        {
            powerUp = std::make_shared<FireRateBoost>(2.0);
            powerUp->SetPos(pos_);
            world->AddObject(powerUp);
        }
        if(choice >=6)
        {
            powerUp = std::make_shared<TripleFire>(1.0);
            powerUp->SetPos(pos_);
            world->AddObject(powerUp);
        }
    }
}


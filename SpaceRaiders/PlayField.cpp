#include "stdafx.h"
#include "PlayField.h"

#include <iostream>

#include "AlienLaser.h"
#include "GameObject.h"
#include "PlayerLaser.h"
#include "PlayerShip.h"

void PlayField::Update()
{
    // Update list of active objects in the world
    auto temp = gameObjects_;
    for (const std::shared_ptr<GameObject>& it : temp)
    {
        if(it != nullptr)
            it->Update();
    }
}

std::shared_ptr<GameObject> PlayField::GetPlayerObject()
{
    auto it = std::find_if(gameObjects_.begin(), gameObjects_.end(),
        [](std::shared_ptr<GameObject> in)
        {
            PlayerShip* playerShip = dynamic_cast<PlayerShip*>(in.get());
            return playerShip != nullptr;
        });
    if (it != gameObjects_.end())
        return (*it);

    return nullptr;
}

void PlayField::SpawnLaser(std::shared_ptr<GameObject> obj)
{
    
    if (dynamic_cast<AlienLaser*>(obj.get())!= nullptr)
        alienLasers_--;
    else if (dynamic_cast<PlayerLaser*>(obj.get())!= nullptr)
        playerLasers_--;
    AddObject(obj);
    
}

void PlayField::DespawnLaser(GameObject* obj)
{
    if (dynamic_cast<AlienLaser*>(obj)!= nullptr)
        alienLasers_++;
    else if (dynamic_cast<PlayerLaser*>(obj)!= nullptr)
        playerLasers_++;
    RemoveObject(obj);
}

void PlayField::AddObject(std::shared_ptr<GameObject> obj)
{
    gameObjects_.push_back(obj);
}


void PlayField::RemoveObject(GameObject* obj)
{
    gameObjects_.erase(std::remove_if(gameObjects_.begin(),gameObjects_.end(),[obj](const std::shared_ptr<GameObject>& other)->bool
    {
       return other.get() == obj;
    }),gameObjects_.end());
}

PlayField* PlayField::instance_ = nullptr;

PlayField* PlayField::GetInstance()
{
    if(instance_ == nullptr)
        instance_ = new PlayField();
    return instance_;
}



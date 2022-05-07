#include "stdafx.h"
#include "GameManager.h"

#include <iostream>

#include "GameObject.h"
#include "PlayerShip.h"

void GameManager::Update()
{
    // Update list of active objects in the world
    auto temp = gameObjects_;
    for (const std::shared_ptr<GameObject>& it : temp)
    {
        if(it != nullptr)
            it->Update();
    }
}

std::shared_ptr<GameObject> GameManager::GetPlayerObject()
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

void GameManager::AddObject(std::shared_ptr<GameObject> obj)
{
    gameObjects_.push_back(obj);
}


void GameManager::RemoveObject(GameObject* obj)
{
    gameObjects_.erase(std::remove_if(gameObjects_.begin(),gameObjects_.end(),[obj](const std::shared_ptr<GameObject>& other)->bool
    {
       return other.get() == obj;
    }),gameObjects_.end());
}

GameManager* GameManager::instance_ = nullptr;

GameManager* GameManager::GetInstance()
{
    if(instance_ == nullptr)
        instance_ = new GameManager();
    return instance_;
}



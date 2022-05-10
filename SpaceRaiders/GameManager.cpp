#include "stdafx.h"
#include "GameManager.h"

#include <iostream>

#include "Alien.h"
#include "Explosion.h"
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

bool GameManager::CheckIfWaveIsOver()
{
    return !std::any_of(gameObjects_.begin(),gameObjects_.end(),[](const std::shared_ptr<GameObject>& ptr)->bool
    {
       return dynamic_cast<Alien*>(ptr.get()) != nullptr; 
    });
}

void GameManager::GameOver()
{
    // kill player
    std::shared_ptr<GameObject> player = GetPlayerObject();
    if (player)
    {
        //Spawn explosion
        std::shared_ptr<GameObject> explosion = std::make_shared<Explosion>();
        explosion->SetPos(player->GetPosition());
        AddObject(explosion);
        RemoveObject(player.get());
        isGameOver_ = true;
    }
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



#include "stdafx.h"
#include "PlayField.h"
#include "GameObject.h"

void PlayField::Update()
{
    // Update list of active objects in the world
    for (const GameObjSharedPtr it : gameObjects_)
    {
        if(it != nullptr)
            it->Update(*this);
    }
}

GameObjSharedPtr PlayField::GetPlayerObject()
{
    if(player_)
        return player_;
    
    auto it = std::find_if(gameObjects_.begin(), gameObjects_.end(),
        [](GameObjSharedPtr in) { return (strcmp(in->GetObjType_CStr(),"ot_PlayerShip")==0); });
    if (it != gameObjects_.end())
        return (*it);

    return nullptr;
}

void PlayField::SpawnLaser(GameObjSharedPtr obj)
{
    
    if (strcmp(obj->GetObjType_CStr(), "ot_AlienLaser")==0)
        alienLasers_--;
    else if (strcmp(obj->GetObjType_CStr(), "ot_PlayerLaser")==0)
        playerLasers_--;
    AddObject(obj);
    
}

void PlayField::DespawnLaser(GameObject* obj)
{
    if (strcmp(obj->GetObjType_CStr(), "ot_AlienLaser")==0)
        alienLasers_++;
    else if (strcmp(obj->GetObjType_CStr(), "ot_PlayerLaser")==0)
        playerLasers_++;
    RemoveObject(obj);
}

void PlayField::AddObject(GameObjSharedPtr obj)
{
    gameObjects_.push_back(obj);
}


void PlayField::RemoveObject(GameObject* obj)
{
    gameObjects_.erase(std::remove(gameObjects_.begin(),gameObjects_.end(),obj),gameObjects_.end());
}

std::shared_ptr<PlayField> PlayField::instance_ = nullptr;

std::shared_ptr<PlayField> PlayField::GetInstance()
{
    if(instance_ == nullptr)
        instance_ = std::make_shared<PlayField>();
    return instance_;
}



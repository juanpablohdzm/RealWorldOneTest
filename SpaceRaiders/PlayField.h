#pragma once
#include <memory>
#include <vector>
#include "Vector2D.h"


class GameObject;
class IInput;

typedef  std::shared_ptr<GameObject> GameObjSharedPtr;

class PlayField
{
private:
    std::vector<GameObjSharedPtr> gameObjects_;
    GameObjSharedPtr player_;
    IInput* cotrollerInput_ = nullptr;
    Vector2D bounds_;
    int alienLasers_ = 10;
    int playerLasers_ = 4;

    static std::shared_ptr<PlayField> instance_;

    PlayField() = default;

public:

    PlayField(PlayField& other) = delete;
    PlayField(PlayField&& other) = delete;

    void operator=(const PlayField&) = delete;
    void operator=(const PlayField&&) = delete;

    void Init(const Vector2D& iBounds)
    {
        bounds_ = iBounds;
    };

    static std::shared_ptr<PlayField> GetInstance();
    const std::vector<GameObjSharedPtr>& GetGameObjects() { return gameObjects_; }
    Vector2D GetBounds()const {return bounds_;}
    GameObjSharedPtr GetPlayerObject();

    void Update();
    
    void SpawnLaser(GameObjSharedPtr obj);
    void DespawnLaser(GameObject* obj);
    
    void AddObject(GameObjSharedPtr obj);
    void RemoveObject(GameObject* obj);

};





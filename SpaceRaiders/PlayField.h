#pragma once
#include <memory>
#include <random>
#include <vector>
#include "Vector2D.h"


class GameObject;
struct IInput;

class PlayField
{
private:
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

    static PlayField* GetInstance();
    const std::vector<std::shared_ptr<GameObject>>& GetGameObjects() { return gameObjects_; }
    Vector2D GetBounds()const {return bounds_;}
    std::shared_ptr<GameObject> GetPlayerObject();

    int GetAlienLasersAmount() const{return alienLasers_;}
    int GetPlayerLasersAmount() const{return playerLasers_;}
    IInput* GetControllerInput() const{return controllerInput_;}

    void SetControllerInput(IInput* controller){controllerInput_ = controller;}

    void Update();
    
    void SpawnLaser(std::shared_ptr<GameObject> obj);
    void DespawnLaser(GameObject* obj);
    
    void AddObject(std::shared_ptr<GameObject> obj);
    void RemoveObject(GameObject* obj);

    ~PlayField(){ delete instance_;}
    
private:
    std::vector<std::shared_ptr<GameObject>> gameObjects_;
    IInput* controllerInput_ = nullptr;
    Vector2D bounds_;
    int alienLasers_ = 10;
    int playerLasers_ = 4;

    static PlayField* instance_;
};





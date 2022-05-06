#pragma once
#include <memory>
#include <random>
#include <vector>
#include "Vector2D.h"


class GameObject;
struct IInput;

class GameManager
{
private:
    GameManager() = default;
public:
    GameManager(GameManager& other) = delete;
    GameManager(GameManager&& other) = delete;

    void operator=(const GameManager&) = delete;
    void operator=(const GameManager&&) = delete;

    static GameManager* GetInstance();
    
    const std::vector<std::shared_ptr<GameObject>>& GetGameObjects() { return gameObjects_; }
    std::shared_ptr<GameObject> GetPlayerObject();

    IInput* GetControllerInput() const{return controllerInput_;}
    void SetControllerInput(IInput* controller){controllerInput_ = controller;}

    void Update();
    

    
    void AddObject(std::shared_ptr<GameObject> obj);
    void RemoveObject(GameObject* obj);

    ~GameManager(){ delete instance_;}
    
private:
    std::vector<std::shared_ptr<GameObject>> gameObjects_;
    IInput* controllerInput_ = nullptr;

    static GameManager* instance_;
};





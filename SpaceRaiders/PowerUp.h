#pragma once
#include <chrono>

#include "GameObject.h"

class PowerUp : public GameObject
{
public:

    PowerUp(float duration) : isActive_(false), duration_(duration){}
    void Update() override;

protected:
    virtual void Activate(class PlayerShip* player);
    virtual void Destroy();
    
    bool isActive_;
    float duration_;
    std::chrono::time_point<std::chrono::system_clock> activateTime_;
    class PlayerShip* player_;
};

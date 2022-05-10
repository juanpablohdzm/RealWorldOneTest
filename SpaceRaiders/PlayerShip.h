#pragma once
#include "GameObject.h"
#include "PlayerLaser.h"
#include "Renderer.h"

class PlayerShip : public GameObject
{
public:
    PlayerShip() : GameObject(),direction_(1.0),speed_(1.0), amountAvailableLasers_(4)
    {
        sprite_ = RS_Player;
    }

    void Update() override;
    
    void DespawnLaser(PlayerLaser* laser);

    float GetSpeed() const{return speed_;}
    void SetSpeed(float speed){speed_ = speed;}

private:
    void Fire();

    float direction_;
    float speed_;
    int amountAvailableLasers_;
};

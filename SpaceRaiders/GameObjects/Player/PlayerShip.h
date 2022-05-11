#pragma once
#include "../GameObject.h"
#include "../Weapons/PlayerLaser.h"
#include "../../Renderer.h"

class PlayerShip : public GameObject
{
public:
    PlayerShip() : GameObject(),direction_(1.0),speed_(1.0), amountAvailableLasers_(4),fireRate_(2.0), tickCount_(0)
    {
        sprite_ = RS_Player;
    }

    void Update() override;
    
    void DespawnLaser(PlayerLaser* laser);

    float GetSpeed() const{return speed_;}
    void SetSpeed(float speed){speed_ = speed;}

    int GetFireRate() const{return fireRate_;}
    void SetFireRate(int fire_rate){fireRate_ = fire_rate;}
    void Fire(Vector2D direction);

private:

    float direction_;
    float speed_;
    int amountAvailableLasers_;
    int fireRate_;
    int tickCount_;
};

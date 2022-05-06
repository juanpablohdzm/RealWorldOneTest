#pragma once
#include "GameObject.h"
#include "PlayerLaser.h"
#include "Renderer.h"

class PlayerShip : public GameObject
{
public:
    PlayerShip() : GameObject(), amountAvailableLasers(4)
    {
        sprite_ = RS_Player;
    }

    void Update() override;
    
    void DespawnLaser(PlayerLaser* laser);

private:
    void Fire();


    int amountAvailableLasers;
};

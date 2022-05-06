#include "stdafx.h"
#include "Laser.h"

#include <memory>

#include "Explosion.h"
#include "GameManager.h"

void Laser::Collision(GameObject* obj)
{
    std::shared_ptr<GameObject> explosion = std::make_shared<Explosion>();
    explosion->SetPos(pos_);
    GameManager::GetInstance()->AddObject(explosion);
}

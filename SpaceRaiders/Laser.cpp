#include "stdafx.h"
#include "Laser.h"

#include <memory>

#include "Explosion.h"
#include "PlayField.h"

void Laser::Collision(GameObject* obj)
{
    std::shared_ptr<GameObject> explosion = std::make_shared<Explosion>();
    explosion->SetPos(pos_);
    PlayField::GetInstance()->AddObject(explosion);
}

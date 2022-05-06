#include "stdafx.h"
#include "Laser.h"

#include <memory>

#include "Explosion.h"
#include "PlayField.h"

void Laser::Move(Vector2D delta)
{
    pos_ = pos_ + delta;
}

void Laser::Collision(GameObject* obj)
{
    std::shared_ptr<GameObject> no = std::make_shared<Explosion>();
    no->SetPos(pos_);
    PlayField::GetInstance()->AddObject(no);
}

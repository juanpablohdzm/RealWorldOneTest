#pragma once
#include "GameObject.h"

class Laser : public GameObject
{
protected:
    virtual void Move(Vector2D delta);
    virtual void Collision(GameObject* obj);

};

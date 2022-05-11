#pragma once
#include "../GameObject.h"

class Laser : public GameObject
{
public:
    virtual void DestroyLaser() = 0;
protected: 
    virtual void Collision(GameObject* obj);

};

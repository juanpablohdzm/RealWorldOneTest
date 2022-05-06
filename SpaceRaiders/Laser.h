#pragma once
#include "GameObject.h"

class Laser : public GameObject
{
protected: 
    virtual void Collision(GameObject* obj);

};

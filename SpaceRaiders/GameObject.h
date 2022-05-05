#pragma once
#include <string>

class PlayField;

class GameObject
{
public:
    virtual void Update(PlayField& world)  = 0;
    virtual bool DecreaseHealth() = 0;

protected:
    std::string m_objType = nullptr;
    unsigned char m_sprite;
    class Vector2D m_pos;

    
};

#pragma once
#include <string>
#include "Vector2D.h"

class PlayField;

class GameObject
{
public:
    virtual ~GameObject() = default;
    virtual void Update()  = 0;

    void SetObjType(const std::string& objType)
    {
        objType_ = objType;
    }

    void SetSprite(unsigned char sprite)
    {
        this->sprite_ = sprite;
    }

    void SetPos(const Vector2D& pos)
    {
        this->pos_ = pos;
    }

    const char* GetObjType_CStr() const
    {
        return objType_.c_str();
    }

    std::string GetObjType() const
    {
        return objType_;
    }

    unsigned char GetSprite() const
    {
        return sprite_;
    }

    Vector2D GetPosition() const
    {
        return pos_;
    }

protected:
    std::string objType_ = nullptr;
    unsigned char sprite_;
    Vector2D pos_;
    
};

#pragma once
#include <string>
#include "Vector2D.h"

class PlayField;

class GameObject
{
public:
    GameObject() : sprite_('d'), pos_(0,0){}
    
    virtual ~GameObject() = default;
    virtual void Update()  = 0;
    virtual void Move(Vector2D delta);

    void SetSprite(unsigned char sprite){this->sprite_ = sprite;}

    void SetPos(const Vector2D& pos){this->pos_ = pos;}

    unsigned char GetSprite() const{return sprite_;}

    Vector2D GetPosition() const{return pos_;}

protected:
    unsigned char sprite_;
    Vector2D pos_;
    
};

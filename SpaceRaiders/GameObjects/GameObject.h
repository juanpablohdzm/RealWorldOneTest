﻿#pragma once

#include "../RaiderSprites.h"
#include "../Components/HealthComponent.h"
#include "../Vector2D.h"

class GameManager;

class GameObject
{
public:
    GameObject() : sprite_(RS_Default), pos_(0,0), healthComponent_(1.0){}
    
    virtual ~GameObject() = default;
    virtual void Update()  = 0;
    virtual void Move(Vector2D delta);

    void SetSprite(unsigned char sprite){this->sprite_ = sprite;}

    void SetPos(const Vector2D& pos){this->pos_ = pos;}

    unsigned char GetSprite() const{return sprite_;}

    Vector2D GetPosition() const{return pos_;}

    [[nodiscard]] HealthComponent* GetHealthComponent() {return &healthComponent_;}

protected:
    unsigned char sprite_;
    Vector2D pos_;

    HealthComponent healthComponent_;
    
};

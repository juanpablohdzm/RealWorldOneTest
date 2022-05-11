#include "stdafx.h"
#include "GameObject.h"

void GameObject::Move(Vector2D delta)
{
    pos_ = pos_ + delta;
}

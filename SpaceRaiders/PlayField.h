#pragma once
#include "Vector2D.h"

class PlayField
{
private:
    PlayField() = default;
public:
    PlayField(PlayField& other) = delete;
    PlayField(PlayField&& other) = delete;

    void operator = (const PlayField&) = delete;
    void operator = (const PlayField&&) = delete;

    void Init(const Vector2D& iBounds)
    {
        bounds_ = iBounds;
    };

    Vector2D GetBounds()const {return bounds_;}

    static PlayField* GetInstance();

    ~PlayField(){delete instance_;}

private:
    static PlayField* instance_;

    Vector2D bounds_;
    
};

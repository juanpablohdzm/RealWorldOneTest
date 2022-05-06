#pragma once

class HealthComponent
{
private:
    float health_;
public:
    float GetHealth() const {return health_;}
    float SetHealth(float value) {health_ = value;}
    virtual void Damage(float value) {health_ -= value;}
};

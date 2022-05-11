#pragma once

class HealthComponent
{
public:
    HealthComponent(float initHealth) : health_(initHealth){};
    
    float GetHealth() const {return health_;}
    void SetHealth(float value) {health_ = value;}

    virtual void Damage(float value) {health_ -= value;}
    virtual bool IsDead() { return health_ <= 0;}
    
private:
    float health_;
};

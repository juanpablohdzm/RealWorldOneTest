#pragma once

class HealthComponent
{
public:
    HealthComponent(float initHealth) : health_(initHealth){};
    
    float GetHealth() const {return health_;}
    void SetHealth(float value) {health_ = value;}
    virtual void Damage(float value) {health_ -= value;}
    
private:
    float health_;
};

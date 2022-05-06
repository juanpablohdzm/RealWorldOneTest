#pragma once

class Alien : public GameObject
{
public:
    Alien() { objType_ = new char[64]; strcpy(objType_,"ot_AlienShip"); sprite = RS_Alien; }
    ~Alien() { delete objType_; }

private:
    // Alien constants - these could move out into PlayField as configurable variables
    const float maxUpdateRate = 0.01f;
    const float transformEnergy = 1.f;
    enum AlienState
    {
        as_Normal,
        as_Better
    };
    // Variables dictating energy level for upgrade, direction of movement, and current speed
    float health = 1.f;
    float energy = 0.f;
    float direction = 1.f;
    float velocity = 0.5f;
    AlienState state;

    void Transform()
    {
        state = as_Better;
        sprite = RS_BetterAlien;
        velocity *= 2.f;
    }
    bool DecreaseHealth() { health -= 1.f; return health <= 0;  }

    void Update(PlayField& world)
    {
        pos.x += direction * velocity;
        // Border check
        if (pos.x < 0 || pos.x >= world.bounds.x_ - 1)
        {
            direction = -direction;
            pos.y += 1;
        }
		
        // Border check vertical:
        if (pos.y >= world.bounds.y_ - 1)
        {
            // kill player
            GameObject* player = world.GetPlayerObject();
            if (player && pos.IntCmp(player->pos))
            {
                //Spawn explosion
                GameObject& no = *(new Explosion);
                no.pos = pos;
                world.AddObject(&no);
                world.RemoveObject(player);
            }
        }

        // Transform into better Alien
        if (state!=as_Better)
        {
            floatRand updateRate(-maxUpdateRate, 2*maxUpdateRate);
            energy += updateRate(rGen);
            if (energy >= transformEnergy)
                Transform();
        }

        floatRand fireRate(0, 1);
        if (fireRate(rGen) < 0.5 && world.AlienLasers>0)
        {
            //Spawn laser
            GameObject& newLaser = *(new AlienLaser);
            newLaser.pos = pos;
            world.SpawnLaser(&newLaser);
        }
    }
};


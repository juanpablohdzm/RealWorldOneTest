// SpaceRaiders.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <memory>

#include "Vector2D.h"
#include "Renderer.h"
#include "GameObject.h"


char ObjectType[][64] =
{
	"ot_AlienShip",
	"ot_PlayerShip",
	"ot_AlienLaser",
	"ot_PlayerLaser",
	"ot_Explosion"
};

class PlayField;
class GameObject;


class PlayerLaser : public GameObject
{
public:
	PlayerLaser() { objType_ = new char[64]; strcpy(objType_, "ot_PlayerLaser"); sprite = RS_PlayerLaser; }
	~PlayerLaser() { delete[] objType_; }

	void Update(PlayField& world)
	{
		bool deleted = false;
		pos.y -= 1.f;
		if (pos.y < 0)
		{
			deleted = true;
		}

		for (auto it : world.GameObjects())
		{
			if (strcmp(it->m_objType,"ot_AlienShip")==0 && it->pos.IntCmp(pos))
			{
				deleted = true;
				//Spawn explosion, kill the alien that we hit
				//ToDo - add scoring
				GameObject& no = *(new Explosion);
				no.pos = pos;
				world.AddObject(&no);
				if (it->DecreaseHealth())
					world.RemoveObject(it);
			}
		}

		if (deleted)
		{
			world.DespawnLaser(this);
			delete this;
		}
	}
};

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

class PlayerShip : public GameObject
{
public:
	PlayerShip() { objType_ = new char[64]; strcpy(objType_, "ot_PlayerShip"); sprite = RS_Player; }
	~PlayerShip() { delete objType_; }

	void Update(PlayField& world)
	{
		if (world.cotrollerInput->Left())
			pos.x -= 1;
		else if (world.cotrollerInput->Right())
			pos.x += 1;
	
		if (world.cotrollerInput->Fire() && world.PlayerLasers>0)
		{
			//Spawn laser
			GameObject& newLaser = *(new PlayerLaser);
			newLaser.pos = pos;
			world.SpawnLaser(&newLaser);
		}
	}
};

int main()
{
	rGen.seed(1);
	Vector2D size(80, 28);
	Renderer mainRenderer(size);
	PlayField world(size);

	intRand xCoord(0, (int)size.x_-1);
	intRand yCoord(0, 10);

	// Populate aliens
	for (int k = 0; k < 20; k++)
	{
		Alien& a = *(new Alien);
		a.pos.x = (float)xCoord(rGen);
		a.pos.y = (float)yCoord(rGen);
		world.AddObject(&a);
	}
	// Add player
	PlayerShip& p = *(new PlayerShip);
	p.pos = Vector2D(40, 27);
	world.AddObject(&p);

	// Test run with random input
	world.cotrollerInput = new RndInput;

    // ToDo - implement keyboard (or other device input)
    //world.cotrollerInput = new KeyboardInput;

	for (int i = 0; i < 100; i++)
	{
		world.Update();

		RenderItemList rl;
		for (auto it : world.GameObjects())
		{
			RenderItem a = RenderItem(Vector2D(it->pos), it->sprite );
			rl.push_back(a);
		}

		mainRenderer.Update(rl);
		// Sleep a bit so updates don't run too fast
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}

	return 0;
}


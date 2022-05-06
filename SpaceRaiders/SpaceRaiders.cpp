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


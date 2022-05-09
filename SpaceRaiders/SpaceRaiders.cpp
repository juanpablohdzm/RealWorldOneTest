// SpaceRaiders.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <vector>
#include <random>
#include <chrono>
#include <iostream>
#include <thread>
#include <memory>

#include "Alien.h"
#include "Vector2D.h"
#include "Renderer.h"
#include "GameObject.h"
#include "PlayerShip.h"
#include "GameManager.h"
#include "KeyboardInput.h"
#include "PlayField.h"
#include "RegularAlien.h"
#include "RndInput.h"
#include "Wall.h"

typedef std::uniform_int_distribution<int> intRand;
typedef std::uniform_real_distribution<float> floatRand;

const Vector2D size(80,28);

#define RANDOM_MODE 0

void PopulateField(GameManager* world, intRand xCoord, intRand yCoord, std::default_random_engine rGen)
{
	// Populate aliens
	// for (int k = 0; k < 10; k++)
	// {
	// 	auto regular_alien = std::make_shared<RegularAlien>();
	// 	regular_alien->SetPos({(float)xCoord(rGen),(float)yCoord(rGen)});
	// 	world->AddObject(regular_alien);
	// }

	intRand randomX(0, (int)size.x()-1);
	intRand randomY(12, 15);
	intRand possibility(0,2);
	for (int i = 0; i < 4; ++i)
	{
		//if(possibility(rGen) != 1) continue;
		auto wall = std::make_shared<Wall>();
		wall->SetPos({(float)randomX(rGen),(float)randomY(rGen)});
		world->AddObject(wall);
	}
	// Add player
	auto player_ship = std::make_shared<PlayerShip>();
	player_ship->SetPos(Vector2D(40, 27));
	world->AddObject(player_ship);
}


void MainLoop(Renderer& mainRenderer, GameManager* world)
{
	world->Update();

	RenderItemList rl;
	for (auto it : world->GetGameObjects())
	{
		RenderItem a{it->GetPosition(), (char)it->GetSprite()};
		rl.push_back(a);
	}

	mainRenderer.Update(rl);
	// Sleep a bit so updates don't run too fast
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}


int main()
{
	Renderer mainRenderer(size);
	auto world = GameManager::GetInstance();
	auto playField = PlayField::GetInstance();
	playField->Init(size);

	intRand xCoord(0, (int)size.x()-1);
	intRand yCoord(0, 10);
	std::default_random_engine rGen;
	rGen.seed(1);

	PopulateField(world, xCoord, yCoord, rGen);



#if RANDOM_MODE
	// Test run with random input
	world->SetControllerInput(new RndInput);
	
	for (int i = 0; i < 300; i++)
	{
		MainLoop(mainRenderer, world);
		if(world->IsGameOver()) break;
	}

#else

	world->SetControllerInput(new KeyboardInput);
	do
	{
		MainLoop(mainRenderer, world);
	}while(!world->IsGameOver());
	
#endif


	std::cin.get();
	return 0;
}


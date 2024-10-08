// SpaceRaiders.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <vector>
#include <random>
#include <chrono>
#include <iostream>
#include <thread>
#include <memory>

#include "./GameObjects/Enemies/Alien.h"
#include "Vector2D.h"
#include "Renderer.h"
#include "./GameObjects/GameObject.h"
#include "./GameObjects/Player/PlayerShip.h"
#include "GameManager.h"
#include "./Input/KeyboardInput.h"
#include "PlayField.h"
#include "./GameObjects/Enemies/RegularAlien.h"
#include "./Input/RndInput.h"
#include "./GameObjects/Spawnables/Wall.h"

typedef std::uniform_int_distribution<int> intRand;
typedef std::uniform_real_distribution<float> floatRand;

const Vector2D size(80,28);

#define RANDOM_MODE 1


void SpawnAliens(GameManager* world,std::default_random_engine& rGen)
{
	intRand xCoord(0, (int)size.x()-1);
	intRand yCoord(0, 10);
	const auto numberOfAliens = world->GetWave() + 10;
	for (int k = 0; k < numberOfAliens; k++)
	{
		auto regular_alien = std::make_shared<RegularAlien>();
		regular_alien->SetPos({(float)xCoord(rGen),(float)yCoord(rGen)});
		world->AddObject(regular_alien);
	}
}

void SpawnWalls(GameManager* world, std::default_random_engine& rGen)
{
	intRand randomX(0, (int)size.x()-1);
	intRand randomY(12, 15);
	for (int i = 0; i < 4; ++i)
	{
		auto wall = std::make_shared<Wall>();
		wall->SetPos({(float)randomX(rGen),(float)randomY(rGen)});
		world->AddObject(wall);
	}
}

void SpawnPlayer(GameManager* world)
{
	auto player_ship = std::make_shared<PlayerShip>();
	player_ship->SetPos(Vector2D(40, 27));
	world->AddObject(player_ship);
}

void InitWave(GameManager* world)
{
	std::default_random_engine rGen;
	rGen.seed(std::chrono::system_clock::now().time_since_epoch().count());

	world->SetWave(world->GetWave()+1);
	SpawnAliens(world,rGen);
	SpawnWalls(world, rGen);
}


void MainLoop(Renderer& mainRenderer, GameManager* world)
{
	if(world->CheckIfWaveIsOver())
	{
		InitWave(world);
	}
	
	world->Update();

	mainRenderer.Update();
	// Sleep a bit so updates don't run too fast
	std::this_thread::sleep_for(std::chrono::milliseconds(100));

}


int main()
{
	auto world = GameManager::GetInstance();

#if RANDOM_MODE
	world->SetControllerInput(new RndInput);
#else
	world->SetControllerInput(new KeyboardInput);
#endif
	
	Renderer mainRenderer(size);
	auto playField = PlayField::GetInstance();
	playField->Init(size);

	
	SpawnPlayer(world);

#if RANDOM_MODE
	// Test run with random input
	
	for (int i = 0; i < 300; i++)
	{
		MainLoop(mainRenderer, world);
		if(world->IsGameOver()) break;
	}

#else

	do
	{
		MainLoop(mainRenderer, world);
	}while(!world->IsGameOver());
	
#endif

	
	system("pause");
	return 0;
}


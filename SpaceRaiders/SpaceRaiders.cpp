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
#include "PlayField.h"
#include "RegularAlien.h"
#include "RndInput.h"

typedef std::uniform_int_distribution<int> intRand;
typedef std::uniform_real_distribution<float> floatRand;

const Vector2D size(80,28);

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

	// Populate aliens
	for (int k = 0; k < 20; k++)
	{
		auto a = std::make_shared<RegularAlien>();
		a->SetPos({(float)xCoord(rGen),(float)yCoord(rGen)});
		world->AddObject(a);
	}
	// Add player
	auto p = std::make_shared<PlayerShip>();
	p->SetPos(Vector2D(40, 27));
	world->AddObject(p);

	// Test run with random input
	world->SetControllerInput(new RndInput);

    // ToDo - implement keyboard (or other device input)
    //world.cotrollerInput = new KeyboardInput;

	//for (int i = 0; i < 100; i++)
	do
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
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}while(!world->IsGameOver());

	std::cin.get();
	return 0;
}


#include "stdafx.h"
#include <vector>
#include <iostream>
#include "Vector2D.h"
#include "Renderer.h"
#include <Windows.h>

#include "GameManager.h"
#include "GameObjects/GameObject.h"

void setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

Renderer::Renderer(const Vector2D& bounds)
: renderBounds(bounds)
{
	canvasSize = (int)(bounds.x() * bounds.y());
	disp[0].canvas = new unsigned char[canvasSize];
	disp[1].canvas = new unsigned char[canvasSize];
}


Renderer::~Renderer()
{
	delete[] disp[0].canvas;
	delete[] disp[1].canvas;
}

void Renderer::Update()
{
	FillCanvas(RS_BackgroundTile);

	const auto gameManager = GameManager::GetInstance();
	for (const auto& game_object : gameManager->GetGameObjects())
	{
		int x = int(game_object->GetPosition().x());
		int y = int(game_object->GetPosition().y());

		if (x >= 0 && x < renderBounds.x() && y >= 0 && y < renderBounds.y())
		{
			*CurCanvas(x, y) = game_object->GetSprite();
		}
	}

	DrawCanvas();
}

void Renderer::FillCanvas(unsigned char sprite)
{
	for (int i = 0; i < canvasSize; i++)
	{
		*CurCanvas(i,0) = sprite;
	}
}

void Renderer::DrawCanvas()
{
	const auto gameMode = GameManager::GetInstance();

	setCursorPosition(0, 0);
	std::string canvas{};
	int offset = 0;
	for (int y = 0; y < renderBounds.y(); y++)
	{
		for (int x = 0; x < renderBounds.x(); x++)
		{
			canvas.push_back(*CurCanvas(x,y));
		}
		canvas.push_back('\n');
		offset++;
	}
	std::cout << canvas;
	if (gameMode->IsGameOver())
		std::cout <<  "Game over your final Score is: " << gameMode->GetScore() << std::endl;
	else
		std::cout << "Wave number:" << gameMode->GetWave() << " Score is: " << gameMode->GetScore() << std::endl;

	curIdx++;
}


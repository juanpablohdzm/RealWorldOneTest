#include "stdafx.h"
#include <vector>
#include <iostream>
#include "Vector2D.h"
//#include "World.h"
#include "Renderer.h"
//#include "GameObject.h"
//#include "GameMode.h"
#include <Windows.h>

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
	canvasSize = (int)(bounds.x_ * bounds.y_);
	disp[0].canvas = new unsigned char[canvasSize];
	disp[1].canvas = new unsigned char[canvasSize];
}


Renderer::~Renderer()
{
	delete[] disp[0].canvas;
	delete[] disp[1].canvas;
}

void Renderer::Update(const RenderItemList& RenderList)
{
	FillCanvas(RS_BackgroundTile);

	for (auto ri : RenderList)
	{
		// std::cout << "object drawn" << std::endl;
		int x = int(ri.pos.x_);
		int y = int(ri.pos.y_);

		if (x >= 0 && x < renderBounds.x_ && y >= 0 && y < renderBounds.y_)
		{
			*CurCanvas((int)ri.pos.x_, + (int)ri.pos.y_) = ri.sprite;
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
	//ToDo: Scoring output/tracking
	//GameMode* gameMode = world.GetGameMode();
	//if (gameMode)
	//	std::cout << "Score: " << gameMode->GetScore() << std::endl;

	for (int y = 0; y < renderBounds.y_; y++)
	{
		for (int x = 0; x < renderBounds.x_; x++)
		{
			setCursorPosition(x, y);
			std::cout << *CurCanvas(x,y);
		}
		std::cout << std::endl;
	}

	curIdx++;

}


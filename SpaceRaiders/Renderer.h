#pragma once

class Renderer
{
public:
	Renderer(const Vector2D& bounds);
	~Renderer();

	// Draws all game objects after clearing filling the Canvas with _ symbol
	void Update();

private:
	Vector2D renderBounds;
	int curIdx = 0;
	struct
	{
		unsigned char* canvas = nullptr;
	} disp[2]; // double buffer our canvas for no flicker display
	int canvasSize = 0;
	unsigned char* CurCanvas(int x, int y) { return &disp[curIdx % 2].canvas[x + (int)renderBounds.x() * y];  }

	// Fills whole canvas array with sprite
	void FillCanvas(unsigned char sprite);

	// Prints canvas char array on console
	void DrawCanvas();
};


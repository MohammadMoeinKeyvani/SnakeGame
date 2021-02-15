#pragma once
#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	int GetWidth();
	int GetHeight();
	bool IsInsideBoard(const Location& loc);
private:
	static constexpr int dimention = 20;
	int width = 25;
	int height = 25;
	Graphics& gfx;
};
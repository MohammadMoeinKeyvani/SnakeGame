/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	board(gfx),
	snake({2 , 2})
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!isGameOver)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			deltaLocation = { 0 , -1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			deltaLocation = { 0 , 1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			deltaLocation = { 1 , 0 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			deltaLocation = { -1 , 0 };
		}

		++snakeMoveCounter;
		if ( !board.IsInsideBoard(snake.NextLocationOfHead( deltaLocation ) ) ||
			snake.IsHittingItself(deltaLocation) )
		{
			isGameOver = true;
		}
		if (snakeMoveCounter >= snakeMovePeriod)
		{
			snakeMoveCounter = 0;
			if (wnd.kbd.KeyIsPressed(VK_CONTROL))
			{
				snake.Grow();
			}
			snake.MoveBy(deltaLocation);
		}
	}
}

void Game::ComposeFrame()
{
	snake.Draw(board);
	if (isGameOver)
	{
		SpriteCodex::DrawGameOver(350 , 250 , gfx);
	}
}

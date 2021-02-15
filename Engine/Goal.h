#pragma once

#include "Snake.h"
#include "Board.h"
#include <random>

class Goal
{
public:
	Goal(Snake& snake, Board& board, std::mt19937 randomNumberGenerator);
	void Respawn(Snake& snake, Board& board, std::mt19937 randomNumberGenerator);
	Location GetLocation();
private:
	Location location;
	static constexpr Color c = Colors::Red;
};

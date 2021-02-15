#include "Goal.h"

Goal::Goal(Snake& snake, Board& board, std::mt19937 randomNumberGenerator)
{
	Respawn(snake, board, randomNumberGenerator);
}

void Goal::Respawn(Snake& snake, Board& board, std::mt19937 randomNumberGenerator)
{
	std::uniform_int_distribution<int> xDist(0, board.GetWidth() - 1);
}

Location Goal::GetLocation()
{
	return Location();
}

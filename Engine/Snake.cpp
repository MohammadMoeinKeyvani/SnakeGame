#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location& loc)
{
	segments[0].InitialHead(loc);
}

void Snake::MoveBy(const Location& deltaLoc)
{
	for (int i = lastUsedSegments - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(deltaLoc);
}

void Snake::Grow()
{
	segments[lastUsedSegments].InitialBody();
	lastUsedSegments++;
}

void Snake::Draw(Board& board)
{
	for (int i = 0; i < lastUsedSegments; i++)
	{
		segments[i].Draw(board);
	}
}

Location Snake::NextLocationOfHead(const Location& deltaLoc)
{
	Location l = segments[0].GetLocation();
	l.Add(deltaLoc);
	return l;
}

bool Snake::IsHittingItself(const Location& deltaLoc)
{
	for (int i = 0; i < lastUsedSegments - 1; i++)
	{
		if (segments[i].GetLocation() == NextLocationOfHead(deltaLoc))
		{
			return true;
		}
	}
	return false;
}

void Snake::Segment::MoveBy(const Location& deltaLoc)
{
	assert(abs(deltaLoc.x) + abs(deltaLoc.y) == 1);
	loc.Add(deltaLoc);
}

void Snake::Segment::InitialHead(const Location& inputLoc)
{
	loc = inputLoc;
	c = headColor;
}

void Snake::Segment::InitialBody()
{
	c = bodyColor;
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::Draw(Board& board)
{
	board.DrawCell(loc, c);
}

Location Snake::Segment::GetLocation()
{
	return loc;
}

#pragma once

#include "Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		void MoveBy(const Location& deltaLoc);
		void InitialHead(const Location& inputLoc);
		void InitialBody();
		void Follow(const Segment& next);
		void Draw(Board& board);
		Location GetLocation();
	private:
		Location loc;
		Color c;
	};

public:
	Snake(const Location& loc);
	void MoveBy(const Location& deltaLoc);
	void Grow();
	void Draw(Board& board);
	Location NextLocationOfHead(const Location& deltaLoc);
	bool IsHittingItself(const Location& deltaLoc);

private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	static constexpr int maxOfSegments = 100;
	Segment segments[maxOfSegments];
	int lastUsedSegments = 1;
};
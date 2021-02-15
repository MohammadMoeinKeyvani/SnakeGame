#pragma once

class Location
{
public:
	void Add(const Location& value)
	{
		x += value.x;
		y += value.y;
	}
	bool operator==(const Location& rightHandSide)
	{
		return x == rightHandSide.x &&
			y == rightHandSide.y;
	}
	int x;
	int y;
};
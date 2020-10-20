#include "soccer.hpp"


int main()
{
	SoccerGame demo;
	if (demo.Construct(320, 640, 1, 1, false, false, true))
		demo.Start();
	return 0;
}
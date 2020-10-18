#include "soccer.hpp"


int main()
{
	SoccerGame demo;
	if (demo.Construct(720, 1024, 2, 2))
		demo.Start();
	return 0;
}
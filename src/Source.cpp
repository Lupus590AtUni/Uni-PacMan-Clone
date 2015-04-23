#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Level.h"
#include "Player.h"

using namespace std;

int main()
{
	Level L;
	Player P;

	char d;

	while (true)
	{
		cin >> d;
		if (d == 'a') P.Check(-1, 0);
		if (d == 'd') P.Check(1, 0);
		if (d == 'w') P.Check(0, -1);
		if (d == 's') P.Check(0, 1);

		
		//L.PrintFile();
		L.PrintMaze();
		
	}

	return 0;
}

/* SEP ASSIGNMENT 2
Programmed by James Cookson */

#pragma once

#include "Level.h"
#include "Node.h"

using namespace std;

class Player
{
private:
	Level L; //Pointer to Level class

public:
	Node playerPoint; //Local node variable created to contain startPoint data from level class

	Player(); //Constructor
	~Player(); //Deconstructor

	void Check(int, int); //Checks to see if player can move in the chosen direction
};
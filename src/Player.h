#pragma once
#include "Level.h"
#include "Node.h"

using namespace std;

enum move { NONE, UP, DOWN, LEFT, RIGHT };

class Player
{
private:
	Level F; //Pointer to FileHandler class
	Node S, startPoint; //Pointers to Node class
	int length; //Length of current path
	enum move myMove;

public:

	Player(); //Constructor
	~Player(); //Deconstructor

	void setMove(enum move);
	void Direction(); //Runs Check() function for each of the four directions
	void Check(int, int); //Checks to see next possible nodes to travel to
};

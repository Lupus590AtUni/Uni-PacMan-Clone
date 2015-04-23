#pragma once

#include "Node.h"

using namespace std; //Avoid problems with cin and cout

class Level
{
public:
	Node **Maze;
	int row; //Rows of maze
	int	col; //Columns of maze

	Level(); //Constructor
	~Level(); //Deconstructor

	void PrintFile(); //Prints file to screen
	void PrintMaze(); //Prints a more distinguishable maze using symbols
};

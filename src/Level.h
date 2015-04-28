/* SEP ASSIGNMENT 2
Programmed by James Cookson */

#pragma once

#include "Node.h"

using namespace std; //Avoid problems with cin and cout

class Level
{
public:
	Node **Maze; //The Game Maze
	Node S, startPoint, Enemy1; //Variables containing initialisation of node constructor, player co-ordinates and enemy co-ordinates respectively
	int row; //Rows of maze
	int	col; //Columns of maze

	Level(); //Constructor
	~Level(); //Deconstructor

	void PrintFile(); //Prints file to screen
	void PrintMaze(); //Prints visual representation of game to screen
};

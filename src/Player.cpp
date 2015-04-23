#include "Player.h"

Player::Player()
{
	//startPoint.x = 24;
	//startPoint.y = 14;

	Node N;
	Level L;

	for (int i = 0; i < L.row; i++)
	{
		for (int j = 0; j < L.col; j++)
		{
			if (L.Maze[i][j].value == 2)
			{
				L.Maze[startPoint.x][startPoint.y] = L.Maze[i][j];
			}
		}
	}

	//myMove = NONE;
}

Player::~Player()
{
}

void Player::setMove(enum move m)
{
	//myMove = m;
}
/*
void Player::Direction()
{
	//Checks all four directions to decide best path to take
	Check(1, 0); //Check right
	Check(-1, 0); //Check left
	Check(0, 1); //Check down
	Check(0, -1); //Check up
}
*/

void Player::Check(int a, int b)
{
	
	if (F.Maze[startPoint.x + a][startPoint.y + b].value == 0 /*&& F.Maze[startPoint.x + a][startPoint.y + b].visited == 0*/) //If the next node is empty and unvisited
	{
		//Node temp = F.Maze[startPoint.x + a][startPoint.y + b];
		//F.Maze[startPoint.x][startPoint.y] = F.Maze[startPoint.x + a][startPoint.y + b];
		//F.Maze[startPoint.x][startPoint.y] = temp;

		F.Maze[startPoint.x][startPoint.y] = F.Maze[startPoint.x + a][startPoint.y + b];

		//F.Maze[startPoint.x][startPoint.y].value = 2;
		/*
		startPoint.x = startPoint.x + a; //Check left/right
		startPoint.y = startPoint.y + b; //Check up/down
		*/
		// F.Maze[startPoint.x][startPoint.y].visited = 1; //Mark the node as visited

		//Direction(); //Recursion, check for next move

		//Return variables to initial values
		/*
		length--;
		F.Maze[startPoint.x][startPoint.y].visited = 0;
		startPoint.x = startPoint.x - a;
		startPoint.y = startPoint.y - b;
		*/
	}
	/*
	
F.Maze[startPoint.x][startPoint.y] = F.Maze[startPoint.x + a][startPoint.y + b];
F.Maze[startPoint.x][startPoint.y].value = 2;
*/
}

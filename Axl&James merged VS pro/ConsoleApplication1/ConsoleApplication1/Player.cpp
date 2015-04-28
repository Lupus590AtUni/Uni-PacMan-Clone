/* SEP ASSIGNMENT 2
Programmed by James Cookson */

#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Check(int a, int b)
{
	if (L.Maze[L.startPoint.x + a][L.startPoint.y + b].value == 0) //If the area is an open space
	{
		//Temporary storage of player co-ordinates
		int tempX = L.startPoint.x;
		int tempY = L.startPoint.y;
		
		//Move player to new co-ordinates
		L.startPoint.x += a;
		L.startPoint.y += b;
		
		for (int i = 0; i < L.row + 1; i++)
		{
			for (int j = 0; j < L.col + 1; j++)
			{
				if (i == tempX && j == tempY)
				{
					L.Maze[i][j].value = 0; //Set value of old position to 0 (Open space)
				}
				else
				{
					if (i == L.startPoint.x && j == L.startPoint.y)
					{
						L.Maze[i][j].value = 2; //Set value of new position to 2 (Player Occupied)
					}
				}
			}
		}

		//Store player co-ordinates inside local variable
		playerPoint.x = L.startPoint.x;
		playerPoint.y = L.startPoint.y;

		cout << "Player Movement: " << endl;
		L.PrintMaze(); //Prints out maze with new player position
	}
	
	else
	{
		cout << "Player Movement: " << endl;
		L.PrintMaze(); //Prints out maze with unadjusted player position
	}
}
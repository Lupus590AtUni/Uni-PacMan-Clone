/* SEP ASSIGNMENT 2
Programmed by James Cookson */

#include "Enemy.h"

Enemy::Enemy()
{
	reached = false;
	length = 0;
	//Allocate memory to variables
	shortestPath = (L.row - 1)*(L.col - 1); //Set to highest possible length currently, can only decrease
	currentPathTemp = new Node[(L.row - 1)*(L.col - 1)]; //Allocate memory for temporary current path variable
	currentPath = new Node[(L.row - 1)*(L.col - 1)];
}

Enemy::~Enemy()
{
	//Delete memory allocated to variables
	delete currentPathTemp; //Delete memory for temporary current path variable
	delete currentPath; //Delete memory for current path variable
}

void Enemy::recordPath()
{
	for (int i = 0; i<length; i++)
	{
		//Record current path
		currentPath[i].x = currentPathTemp[i].x;
		currentPath[i].y = currentPathTemp[i].y;
	}
	pathSize = length;
}

void Enemy::Direction(Node playerPoint)
{
	//Check player
	Check(0, -1, playerPoint);
	Check(0, 1, playerPoint);
	Check(-1, 0, playerPoint);
	Check(1, 0, playerPoint);
}

void Enemy::Check(int a, int b, Node playerPoint)
{
	if (L.Maze[L.Enemy1.x + a][L.Enemy1.y + b].value == 0 && L.Maze[L.Enemy1.x + a][L.Enemy1.y + b].visited == 0 && reached == false) //If the next space is open and the enemy hasn't been there before
	{
		//Update enemy position
		L.Enemy1.x = L.Enemy1.x + a;
		L.Enemy1.y = L.Enemy1.y + b;

		//Temporary variable to store current enemy co-ordinates
		currentPathTemp[length].x = L.Enemy1.x;
		currentPathTemp[length].y = L.Enemy1.y;
		
		//Change the current tile to visited
		L.Maze[L.Enemy1.x][L.Enemy1.y].visited = 1;

		//Add to length of path
		length++;
		
		if (L.Enemy1.x == L.startPoint.x - 1 && L.Enemy1.y == L.startPoint.y - 1 
			|| L.Enemy1.x == L.startPoint.x + 1 && L.Enemy1.y == L.startPoint.y + 1
			|| L.Enemy1.x == L.startPoint.x + 1 && L.Enemy1.y == L.startPoint.y - 1 
			|| L.Enemy1.x == L.startPoint.x - 1 && L.Enemy1.y == L.startPoint.y + 1) //If the enemy is in range of the player
		{
			reached = true;
			
				recordPath(); //Record path
				shortestPath = length; //Size of shortest path
		}

		if (reached == false) //If the enemy still hasn't reached the player, keep searching
		{
			Direction(playerPoint);
		}

		//Reset variables
		length--;
		L.Maze[L.Enemy1.x][L.Enemy1.y].visited = 0;
		L.Enemy1.x = L.Enemy1.x - a;
		L.Enemy1.y = L.Enemy1.y - b;
	}
}

void Enemy::PrintPathCoordinates()
{
	for (int i = 0; i < pathSize; i++)
	{
		cout << i + 1 << "(" << currentPath[i].y << "," << currentPath[i].x << ")" << endl; //Print co-ordinates of path
	}
}

void Enemy::setNewPos()
{
	//Temporarily store enemy co-ordinates
	int tempX = L.Enemy1.x;
	int tempY = L.Enemy1.y;

	//Enemy co-ordinates changed to first co-ordinates in path finding algorithm - moves towards player
	L.Enemy1.x = currentPath[0].x;
	L.Enemy1.y = currentPath[0].y;

	//Current tile marked as visited
	L.Maze[L.Enemy1.x][L.Enemy1.y].visited = 1;

	//Locally store enemy co-ordinates
	enemyPoint = L.Enemy1;
	
	for (int i = 0; i < L.row + 1; i++)
	{
		for (int j = 0; j < L.col + 1; j++)
		{
			if (i == tempX && j == tempY)
			{
				L.Maze[i][j].value = 0;
			}
			else
			{
				if (i == L.Enemy1.x && j == L.Enemy1.y)
				{
					L.Maze[i][j].value = 3;
				}
			}
		}
	}
	cout << "Enemy Movement: " << endl;

	L.PrintMaze();
	
}
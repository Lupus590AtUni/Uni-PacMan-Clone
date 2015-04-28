/* SEP ASSIGNMENT 2
Programmed by James Cookson */

#pragma once

#include "Level.h"
#include "Node.h"

class Enemy
{
private:
	Level L; //Pointer to Level class
	Node N, *currentPathTemp, *currentPath; //Initialise Node class, temporary path storage, path storage
	int length; //Length of current path to player; //Pointer to Level class
	int pathSize; //variable used to contain size of the final path

public:
	int shortestPath; //Shortest path to player
	bool reached; //Checks to see if the path will reach the player before it is stored
	Node enemyPoint; //Local variable to store enemy co-ordinates

	Enemy(); //Constructor
	~Enemy(); //Deconstructor

	void recordPath(); //Records the path the enemy has found to player
	void Direction(Node); //Checks the pathfinding algorithm in 4 directions to see which direction enemy should move next
	void Check(int, int, Node); //Pathfinding algorithm
	void PrintPathCoordinates(); //Prints the path co-ordinates the enemy found
	void setNewPos(); //Updates enemy position
};


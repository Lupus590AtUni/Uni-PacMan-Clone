#pragma once
#include <iostream>
#include <fstream>

#define INF 99999 //Pseudo-Infinity

class Node
{
public:
	int x; //x co-ordinate of node
	int y; //y co-ordinate of node
	int value; //Value of current node
	int visited; //Variable to track whether node has been visited, 1 means yes, 0 means no
	int path; //Range of possible pathfinding, a low number may prevent program from locating goal node

	Node()
	{
		x = 0;
		y = 0;
		value = 0;
		visited = 0; 
		path = INF;
	} 
};

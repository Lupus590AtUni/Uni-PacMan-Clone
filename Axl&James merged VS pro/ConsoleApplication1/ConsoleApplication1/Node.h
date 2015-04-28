/* SEP ASSIGNMENT 2
Programmed by James Cookson */

#pragma once

#include <iostream>
#include <fstream>

#define INF 99999 //Pseudo-Infinity

class Node
{
public:
	int x; //x co-ordinate of node
	int y; //y co-ordinate of node
	int value; //Value of each node determines what is drawn to screen in each tile
	int visited; //Variable to track whether node has been visited, 1 means yes, 0 means no
	int path; //Range of possible pathfinding, a low number may prevent the enemy from finding the player

	Node()
	{
		x = 0;
		y = 0;
		value = 0;
		visited = 0; 
		path = INF;
	} 
};

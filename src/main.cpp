/* SEP ASSIGNMENT 2
Programmed by James Cookson */

#include <cstdlib>
#include "Level.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

int main()
{
	//Pointers to classes
	Level L;
	Player P;
	Enemy E;
	
	char d; //User input variable
	bool flag = true; //Flag to trigger exiting of game loop
	int gameState = 0; //Depending on value will display winning or losing message

	while (flag == true) //While the loop is running
	{
		cin >> d; //Scan user input

		//Depending on what key the user presses the check function in the Player class is called with values that will cause the player to move in that direction
		if (d == 'a') P.Check(0, -1);
		if (d == 'd') P.Check(0, 1);
		if (d == 'w') P.Check(-1, 0);
		if (d == 's') P.Check(1, 0);
		if (d == 'q') flag = false; //If the user presses q the game will close
		
		E.reached = false; //Resets a variable in the Enemy class responsible for checking if the enemy pathfinding found the player
		E.Direction(P.playerPoint); //Triggers enemy pathfinding

		//E.PrintPathCoordinates(); //Print co-ordinates of path that enemy found to player

		E.setNewPos(); //Moves the enemy to its new position
		cout << endl;

		cout << "Player Position = (" << P.playerPoint.y << ", " << P.playerPoint.x << ")" << endl; //Prints out current player position
		cout << "Enemy Position = (" << E.enemyPoint.y << ", " << E.enemyPoint.x << ")" << endl; //Prints out current enemy position

			if (P.playerPoint.x == E.enemyPoint.x - 1 && P.playerPoint.y == E.enemyPoint.y - 1	//If the enemy is in range of the player
				|| P.playerPoint.x == E.enemyPoint.x - 1 && P.playerPoint.y == E.enemyPoint.y + 1 
				|| P.playerPoint.x == E.enemyPoint.x + 1 && P.playerPoint.y == E.enemyPoint.y - 1
				|| P.playerPoint.x == E.enemyPoint.x + 1 && P.playerPoint.y == E.enemyPoint.y + 1)
			{
				flag = false; //End game loop
				gameState = 1; //Lose state
			}
	}

	if (gameState == 1) //If player loses
	{
		cout << "You Lose" << endl;
	}
	
	return 0;
}

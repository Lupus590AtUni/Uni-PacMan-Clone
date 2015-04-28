#include <stdio.h>
#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
#include "Sound.h"
#include "Events.h"
#include "Menu.h"


#include <cstdlib>
#include "Level.h"
#include "Player.h"
#include "Enemy.h"

int main(int argc , char* argv[])
{
	Sound* sound = NULL ;
	Events* events = NULL ;
	Menu* menu = NULL ;

	if( SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        printf("Problem loading SDL\n") ;
        exit(1) ;
    }

	sound = new Sound() ;
	sound->init() ;

	events = new Events() ;
	
	//Sets up the screen
	SDL_Surface* screen ; //Creates a pointer to the screen

	//Screen constants
	static const int SCREEN_WIDTH = 800 ;
	static const int SCREEN_HIGHT = 600 ;
	static const int SCREEN_BPP = 32 ;

	screen = SDL_SetVideoMode(SCREEN_WIDTH , SCREEN_HIGHT , SCREEN_BPP , SDL_SWSURFACE) ;

	menu = new Menu() ;
	menu->init(screen , events , sound) ;

	if(menu->displayMenu() == true)
	{
		printf("Play game\n\n") ;

		//Pointers to classes
		Level L;
		Player P;
		Enemy E;
	
		char d; //User input variable
		bool flag = true; //Flag to trigger exiting of game loop
		int gameState = 0; //Depending on value will display winning or losing message

		while (flag == true) //While the loop is running
		{
			cout << "Please Enter wasd to move, q to quit: "; 
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
	}
	else
	{
		printf("Exit game\n\n") ;
	}

	SDL_Quit() ;

	return 0 ;
}
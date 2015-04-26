#include <stdio.h>
#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
#include "Sound.h"
#include "Events.h"
#include "Menu.h"

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
	}
	else
	{
		printf("Exit game\n\n") ;
	}

	return 0 ;
}
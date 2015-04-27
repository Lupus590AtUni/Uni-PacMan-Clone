#pragma once

#ifdef (WIN32)
  #include "SDL.h"
#else
  #include <SDL/SDL.h>
#end

class Events ;
class Button ;
class Sound ;
class MenuSetupClass ;
//class Highscore ;

class Menu
{
	private :

		static const int STRING_MAX = 254 ;
		static const int MAX_BUTTONS = 4 ;

		bool musicPlaying ;

		Uint8* keyStates ;

		SDL_Surface* screen ;
		SDL_Surface* backgroundImage ;

		Events* events ;
		Sound* sound ;
		MenuSetupClass* menuSetupClass ;
		//Highscore* highscore ;
		Button* buttons[MAX_BUTTONS] ;

		void draw() ;
		void toggleMusic() ;

	public :

		//Class creation
		Menu(void) ; //Constructor
		~Menu(void) ; //Destructor
		void init(SDL_Surface* screen , Events* events , Sound* sound) ;
		//void init(SDL_Surface* screen , Events* events , Sound* sound , Highscore highscore) ;

		bool displayMenu() ;
} ;

//NOTE: highscore elements and the correct init function commented out until the group has made the highscore class
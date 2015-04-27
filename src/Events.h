#pragma once

//Includes
#ifdef (WIN32)
  #include "SDL.h"
#else
  #include <SDL/SDL.h>
#end

class Events
{
	private :

		static const int MOUSE_STATE_MAX = 4 ; //The max amounts of ints the mouseStates int array can store

		int mouseStates[MOUSE_STATE_MAX] ; //In this order x pos , y pos , left mouse button , right mouse button

		Uint8* keyStates ; //Stores the keyStates

		SDL_Event event ; //the genral event structure

	public:

		//Class creation
		Events(void) ; //Constructor
		~Events(void) ; //Destructor

		bool PollEvent(void) ; //Polls for an SDL event

		Uint8* getKeyStates(void) ; //Returns the current keystates
		int* getMouseStates(void) ; //Returns the current keystates
} ;

#include "Events.h"

Events::Events(void)
{
	this->keyStates = NULL ;

	for(int i = 0 ; i < this->MOUSE_STATE_MAX ; i++)
	{
		this->mouseStates[i] = NULL ;
	}
}


Events::~Events(void)
{
	
}

bool Events::PollEvent(void)
{
	if( SDL_PollEvent( &event ) )
	{
		switch(event.type)
		{
			case SDL_QUIT : //If the user has closed(x) out the window

				//Quit the program
				return false ;

				break ;

				case SDL_MOUSEMOTION :

					this->mouseStates[0] = event.motion.x ;
					this->mouseStates[1] = event.motion.y ;

					break ;

				case SDL_MOUSEBUTTONDOWN :

					if(event.button.button == SDL_BUTTON_LEFT)
					{
						this->mouseStates[2] = 1 ;
					}
					if(event.button.button == SDL_BUTTON_RIGHT)
					{
						this->mouseStates[3] = 1 ;
					}

					break ;

				case SDL_MOUSEBUTTONUP :

					if(event.button.button == SDL_BUTTON_LEFT)
					{
						this->mouseStates[2] = 0 ;
					}
					if(event.button.button == SDL_BUTTON_RIGHT)
					{
						this->mouseStates[3] = 0 ;
					}

					break ;

			default :

				//No action
				break ;
		} 
	}

	return true ;
}

Uint8* Events::getKeyStates()
{
	this->keyStates = SDL_GetKeyState(NULL) ;

	return this->keyStates ;
}

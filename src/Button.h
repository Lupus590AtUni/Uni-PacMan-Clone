#pragma once

#include "SDL.h"

class Button
{
	private :

		static const int HIGHT = 50 ;
		static const int WIDTH = 50 ;

		SDL_Rect position ;
		SDL_Surface* image ;

	public :

		//Class creation
		Button(void) ;
		~Button(void) ;
		void init(SDL_Surface* image , SDL_Rect pos) ;

		SDL_Rect getPosition(void) ;
		void setPosition(SDL_Rect) ;
		void draw(SDL_Surface* screen) ;
} ;


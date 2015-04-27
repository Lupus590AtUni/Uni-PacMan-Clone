#pragma once

#ifdef (WIN32) 
  #include "SDL.h"
  #include "SDL_image.h"
#else
  #include <SDL.h>
  #include <SDL_image.h>
#endif

//Image handling functions
class Image
{
    public:

		static SDL_Surface* loadImage(const char* imagePath) ; //Loads the image
		static SDL_Surface* loadImage(const char* imagePath , Uint8 r , Uint8 g , Uint8 b) ; //Loads the image but removes the image background
} ;

//Refrence:Glenn Jenkins
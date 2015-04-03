#include "Image.h"


/* loadImage
 * This is one of a pair of overloaded functions, it assumes there is
 * no background colour as none was passed in
*/

SDL_Surface* Image::loadImage(const char* imagePath)
{
    SDL_Surface* rawImage ;
    SDL_Surface* optimisedImage ; //this pointer will be returned.

    rawImage = IMG_Load(imagePath) ;

    if(rawImage != NULL) //if the image is not null
    {
        //Optimise
        optimisedImage = SDL_DisplayFormat(rawImage) ;

        //Dispose of rawImage - we have our optimised copy
        SDL_FreeSurface(rawImage) ;
    }
    else
    {
        printf("Failed to load image") ;
        exit(1) ;
    }

    return optimisedImage ;
}

SDL_Surface* Image::loadImage(const char* imagePath, Uint8 r, Uint8 g, Uint8 b)
{
    SDL_Surface* rawImage ;
    SDL_Surface* optimisedImage ; //this pointer will be returned.

    rawImage = IMG_Load(imagePath) ;

    // if the image is not null
    if(rawImage != NULL)
    {
        // Optimise
        optimisedImage = SDL_DisplayFormat(rawImage) ;

        // Create an SDL unsigned integer to represent our colour

        // The format of the call is
        // Uint32 SDL_MapRGB(SDL_PixelFormat *fmt, Uint8 r, Uint8 g, Uint8 b);
        // I looked this up on the internet to get the parameters right for
        // the function.
        Uint32 colourkey = SDL_MapRGB(optimisedImage->format , r , g , b) ;

        //Set the colour key, this is part of the SDL_Surface structure
        SDL_SetColorKey(optimisedImage , SDL_SRCCOLORKEY , colourkey) ;

        //Dispose of rawImage - we have our optimised copy
        SDL_FreeSurface(rawImage) ;
    }
    else
    {
        printf("Failed to load image") ;
        exit(1) ;
    }

    return optimisedImage ;
}

//Refrence:Glenn Jenkins

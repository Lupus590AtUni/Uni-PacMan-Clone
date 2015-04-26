#include "Button.h"


Button::Button(void)
{
}


Button::~Button(void)
{
}

void Button::init(SDL_Surface* image , SDL_Rect pos)
{
	this->image = image ;
	this->position = pos ;
}

SDL_Rect Button::getPosition(void)
{
	return this->position ;
}

void Button::setPosition(SDL_Rect position)
{
	this->position = position ;
}

void Button::draw(SDL_Surface* screen)
{
	SDL_BlitSurface(this->image , NULL , screen , &this->position) ;
}
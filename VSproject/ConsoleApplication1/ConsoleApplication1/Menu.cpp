#include "Menu.h"
#include "Image.h"
#include "Button.h"
#include "Events.h"
#include "Sound.h"
//#include "Highscore"
#include "MenuSetupClass.h"

Menu::Menu(void)
{
	this->musicPlaying = false ;
}


Menu::~Menu(void)
{
	if(this->menuSetupClass != NULL)
	{
		delete this->menuSetupClass ;
		this->menuSetupClass = NULL ;
	}
}

void Menu::init(SDL_Surface* screen , Events* events , Sound* sound)
{
	this->screen = screen ;
	this->events = events ;
	this->sound = sound ;

	this->sound->playMusic() ;
	this->musicPlaying = true ;

	this->menuSetupClass = new MenuSetupClass() ;
	this->menuSetupClass->init() ;

	this->buttons[0] = new Button() ;
	SDL_Rect tempPlay ;
	tempPlay.x = this->menuSetupClass->playButtonRectX ;
	tempPlay.y = this->menuSetupClass->playButtonRectY ;
	this->buttons[0]->init(Image::loadImage(this->menuSetupClass->playButtonImagePath) , tempPlay) ;

	this->buttons[1] = new Button() ;
	SDL_Rect tempHighscore ;
	tempHighscore.x = this->menuSetupClass->highscoreButtonRectX ;
	tempHighscore.y = this->menuSetupClass->highscoreButtonRectY ;
	this->buttons[1]->init(Image::loadImage(this->menuSetupClass->highscoreButtonImagePath) , tempHighscore) ;

	this->buttons[2] = new Button() ;
	SDL_Rect tempSound ;
	tempSound.x = this->menuSetupClass->toggleMusicButtonRectX ;
	tempSound.y = this->menuSetupClass->toggleMusicButtonRectY ;
	this->buttons[2]->init(Image::loadImage(this->menuSetupClass->toggleMusicButtonImagePath) , tempSound) ;

	this->buttons[3] = new Button() ;
	SDL_Rect tempExit ;
	tempExit.x = this->menuSetupClass->exitButtonRectX ;
	tempExit.y = this->menuSetupClass->exitButtonRectY ;
	this->buttons[3]->init(Image::loadImage(this->menuSetupClass->exitButtonImagePath) , tempExit) ;

	this->backgroundImage = Image::loadImage(this->menuSetupClass->backgroundImagePath) ;

	delete this->menuSetupClass ;
	this->menuSetupClass = NULL ;
}

//void Menu::init(SDL_Surface* screen , Events* events , Sound* sound , Highscore* highscore)
//{
//	this->screen = screen ;
//	this->events = events ;
//	this->sound = sound ;
//
//	this->sound->playMusic() ;
//	this->musicPlaying = true ;
//
//	this->highscore = highscore ;	
//
//	this->menuSetupClass = new MenuSetupClass() ;
//	this->menuSetupClass->init() ;
//
//	this->buttons[0] = new Button() ;
//	SDL_Rect tempPlay ;
//	tempPlay.x = this->menuSetupClass->playButtonRectX ;
//	tempPlay.y = this->menuSetupClass->playButtonRectY ;
//	this->buttons[0]->init(Image::loadImage(this->menuSetupClass->playButtonImagePath) , tempPlay) ;
//
//	this->buttons[1] = new Button() ;
//	SDL_Rect tempHighscore ;
//	tempHighscore.x = this->menuSetupClass->highscoreButtonRectX ;
//	tempHighscore.y = this->menuSetupClass->highscoreButtonRectY ;
//	this->buttons[1]->init(Image::loadImage(this->menuSetupClass->highscoreButtonImagePath) , tempHighscore) ;
//
//	this->buttons[2] = new Button() ;
//	SDL_Rect tempSound ;
//	tempSound.x = this->menuSetupClass->toggleMusicButtonRectX ;
//	tempSound.y = this->menuSetupClass->toggleMusicButtonRectY ;
//	this->buttons[2]->init(Image::loadImage(this->menuSetupClass->toggleMusicButtonImagePath) , tempSound) ;
//
//	this->buttons[3] = new Button() ;
//	SDL_Rect tempExit ;
//	tempExit.x = this->menuSetupClass->exitButtonRectX ;
//	tempExit.y = this->menuSetupClass->exitButtonRectY ;
//	this->buttons[3]->init(Image::loadImage(this->menuSetupClass->exitButtonImagePath) , tempExit) ;
//
//	this->backgroundImage = Image::loadImage(this->menuSetupClass->backgroundImagePath) ;
//
//	delete this->menuSetupClass ;
//	this->menuSetupClass = NULL ;
//}

void Menu::draw()
{
	SDL_BlitSurface(this->backgroundImage , NULL , this->screen , NULL) ;

	for(int i = 0 ; i < this->MAX_BUTTONS ; i++)
	{
		this->buttons[i]->draw(this->screen) ;
	}

	SDL_Flip(this->screen) ;
}

void  Menu::toggleMusic(void)
{
	if(this->musicPlaying == false)
	{
		this->sound->playMusic() ;
		this->musicPlaying = true ;
	}
	else
	{
		this->sound->stopMusic() ;
		this->musicPlaying = false ;
	}
}

bool Menu::displayMenu()
{
	int* mouseStates ; //In this order x pos , y pos , left mouse button , right mouse button

	while(true)
	{
		this->draw() ;

		if(this->events->PollEvent() == true)
		{
			mouseStates = this->events->getMouseStates() ;

			if(mouseStates[0] > this->buttons[0]->getPosition().x && mouseStates[0] < (this->buttons[0]->getPosition().x + 50))
			{
				if(mouseStates[1] > this->buttons[0]->getPosition().y && mouseStates[1] < (this->buttons[0]->getPosition().y + 50))
				{
					if(mouseStates[2] == 1)
					{
						return true ;
					}
				}
			}

			if(mouseStates[0] > this->buttons[1]->getPosition().x && mouseStates[0] < (this->buttons[1]->getPosition().x + 50))
			{
				if(mouseStates[1] > this->buttons[1]->getPosition().y && mouseStates[1] < (this->buttons[1]->getPosition().y + 50))
				{
					if(mouseStates[2] == 1)
					{
						//this->highscore->displayHighscore(this->screen) ; 
						//Waiting for highscore class to be given to me by other member of my group
					}
				}
			}

			if(mouseStates[0] > this->buttons[2]->getPosition().x && mouseStates[0] < (this->buttons[2]->getPosition().x + 50))
			{
				if(mouseStates[1] > this->buttons[2]->getPosition().y && mouseStates[1] < (this->buttons[2]->getPosition().y + 50))
				{
					if(mouseStates[2] == 1)
					{
						if(this->musicPlaying == true)
						{
							this->sound->stopMusic() ;
							this->musicPlaying = false ;
						}
						else
						{
							this->sound->playMusic() ;
							this->musicPlaying = true ;
						}
						
						SDL_Delay(150) ;
					}
				}
			}

			if(mouseStates[0] > this->buttons[3]->getPosition().x && mouseStates[0] < (this->buttons[3]->getPosition().x + 50))
			{
				if(mouseStates[1] > this->buttons[3]->getPosition().y && mouseStates[1] < (this->buttons[3]->getPosition().y + 50))
				{
					if(mouseStates[2] == 1)
					{
						 return false ;
					}
				}
			}
		}
		else
		{
			return false ;
		}
	}
}
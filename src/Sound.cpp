#include "Sound.h"
#include <stdio.h>

Sound::Sound(void)
{
	this->music = NULL ;
}


Sound::~Sound(void)
{
	if(this->music != NULL)
	{
		Mix_FreeMusic(this->music) ;
		this->music = NULL ;
	}
}

void Sound::init(void)
{
	if( Mix_Init(MUS_MP3) == -1)
	{
		printf("Problem loading SDL_Mixer\n") ;
        exit(1) ;
	}

	Mix_OpenAudio(22050 , MIX_DEFAULT_FORMAT , 2 , 4096) ;
	
	this->music = Mix_LoadMUS("Music.mp3") ; //http://www.classicgaming.cc/classics/pacman/sounds.php

	if(this->music == NULL)
	{
		printf("Mix_LoadMUS(\"Music.mp3\"): %s\n", Mix_GetError()) ;
	}
}

void Sound::playMusic(void)
{
	Mix_PlayMusic(this->music , -1) ;
}

void Sound::stopMusic(void)
{
	Mix_HaltMusic() ;
}
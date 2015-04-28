#include <stdio.h>
#include "SDL.h"
#include "SDL_mixer.h"
#include "Sound.h"


#include <cstdlib>
#include <time.h>

class NA_Timer
{
private:
	int duration;
	int start;
public:
	NA_Timer(void);
	NA_Timer(int d);
	~NA_Timer(void);
	void setDuration(int d);
	bool hasElapsed();
	void restart();
};


NA_Timer::NA_Timer(void)
{
	duration = 0;
	start = time(NULL);
}

NA_Timer::NA_Timer(int d)
{
	duration = d;
	start = time(NULL);
}

NA_Timer::~NA_Timer(void)
{
}

void NA_Timer::setDuration(int d)
{
	duration = d;
}

bool NA_Timer::hasElapsed()
{
	if(duration < difftime(time(NULL),start))
		return true;
	//else
	return false;
}

void NA_Timer::restart()
{
	start = time(NULL);
}

int main(int argc , char* argv[])
{
	Sound* sound = NULL ;

	if( SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        printf("Problem loading SDL\n") ;
        exit(1) ;
    }

	sound = new Sound() ;
	sound->init() ;

	sound->playMusic();

	NA_Timer timer(3);

	while(!timer.hasElapsed())
	{
		//wait
	}

	sound->stopMusic();

	timer.restart();

	while(!timer.hasElapsed())
	{
		//wait
	}


	sound->playMusic();

	timer.restart();

	while(!timer.hasElapsed())
	{
		//wait
	}

	sound->stopMusic();
	delete sound;

	SDL_Quit() ;

	return 0 ;
}
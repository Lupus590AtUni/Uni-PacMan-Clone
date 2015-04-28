#include <SDL>

int main (int argc, char* argv[])
{
  if( SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        printf("Problem loading SDL\n") ;
        exit(1) ;
    }
    
    //Sets up the screen
	SDL_Surface* screen ; //Creates a pointer to the screen

	//Screen constants
	static const int SCREEN_WIDTH = 800 ;
	static const int SCREEN_HIGHT = 600 ;
	static const int SCREEN_BPP = 32 ;

	screen = SDL_SetVideoMode(SCREEN_WIDTH , SCREEN_HIGHT , SCREEN_BPP , SDL_SWSURFACE) ;
    
  SDL_Quit();
    
  return 0;
}
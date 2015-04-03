#include "MenuSetupClass.h"
#include <iostream>

using std::cout ;
using std::endl ;

int main(int* argc , char* argv[])
{
	MenuSetupClass* menuSetup ;
	menuSetup = new MenuSetupClass() ;

	menuSetup->init() ;
	
	cout << menuSetup->playButtonRectX << endl ;
	cout << menuSetup->playButtonRectY << endl ;
	
	cout << menuSetup->highscoreButtonRectX << endl ;
	cout << menuSetup->highscoreButtonRectY << endl ;
	
	cout << menuSetup->toggleMusicButtonRectX << endl ;
	cout << menuSetup->toggleMusicButtonRectY << endl ;
	
	cout << menuSetup->exitButtonRectX << endl ;
	cout << menuSetup->exitButtonRectY << endl ;
	
	cout << menuSetup->backgroundImagePath << endl ;
	cout << menuSetup->playButtonImagePath << endl ;
	cout << menuSetup->highscoreButtonImagePath << endl ;
	cout << menuSetup->toggleMusicButtonImagePath << endl ;
	cout << menuSetup->exitButtonImagePath << endl ;

	delete menuSetup ;	
	
	return 0 ;
}

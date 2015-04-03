#pragma once

class MenuSetupClass
{
	private :
	
		static const char FILE_NAME[] ;

	public :
	
		//Class creation
		MenuSetupClass(void) ; //Constructor
		~MenuSetupClass(void) ; //Destructor
		void init(void) ; //Init method reads in the classes attrabutes from its associated file
	
		//Const value for the number of chars in char* strings
		static const int STRING_MAX = 256 ;
		
		//Button rects
		int playButtonRectX ;
		int playButtonRectY ;
		
		int highscoreButtonRectX ;
		int highscoreButtonRectY ;
		
		int toggleMusicButtonRectX ;
		int toggleMusicButtonRectY ;
		
		int exitButtonRectX ;
		int exitButtonRectY ;
		
		//Button image pathways
		char backgroundImagePath[STRING_MAX] ;
		char playButtonImagePath[STRING_MAX] ;
		char highscoreButtonImagePath[STRING_MAX] ;
		char toggleMusicButtonImagePath[STRING_MAX] ;
		char exitButtonImagePath[STRING_MAX] ;		
} ;

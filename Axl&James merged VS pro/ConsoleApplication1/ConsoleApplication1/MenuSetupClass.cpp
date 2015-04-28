#include "MenuSetupClass.h"
/*#include <iostream>
#include <fstream>
using std::cout ;
using std::cin ;
using std::endl ;
using std::fstream ;
using std::getline ;*/
#include <stdio.h>

const char MenuSetupClass::FILE_NAME[] = "MenuSetupClassFile.txt" ;

MenuSetupClass::MenuSetupClass(void)
{

}

MenuSetupClass::~MenuSetupClass(void)
{

}

void MenuSetupClass::init(void)
{
	/*fstream setupFile ;
	//setupFile.open(FILE_NAME) ;
	setupFile.open("/MenuSetupClassFile.txt") ;
	
	if(setupFile.is_open() != 0) //Check that the file opened
	{
		cout << "File failed to open" << endl ;
	}
	else //It did
	{
		getline(setupFile , this->playButtonRectX) ;
		getline(setupFile , this->playButtonRectY) ;
		
		getline(setupFile , this->highscoreButtonRectX) ;
		getline(setupFile , this->highscoreButtonRectY) ;
		
		getline(setupFile , this->toggleMusicButtonRectX) ;
		getline(setupFile , this->toggleMusicButtonRectY) ;
		
		getline(setupFile , this->exitButtonRectX) ;
		getline(setupFile , this->exitButtonRectY) ;
		
		getline(setupFile , this->backgroundImagePath) ;
		getline(setupFile , this->playButtonImagePath) ;
		getline(setupFile , this->highscoreButtonImagePath) ;
		getline(setupFile , this->toggleMusicButtonImagePath) ;
		getline(setupFile , this->exitButtonImagePath) ;
	
		setupFile >> this->playButtonRectX ;
		setupFile >> this->playButtonRectY ;
		
		setupFile >> this->highscoreButtonRectX ;
		setupFile >> this->highscoreButtonRectY ;
		
		setupFile >> this->toggleMusicButtonRectX ;
		setupFile >> this->toggleMusicButtonRectY ;
		
		setupFile >> this->exitButtonRectX ;
		setupFile >> this->exitButtonRectY ;
		
		setupFile >> this->backgroundImagePath ;
		setupFile >> this->playButtonImagePath ;
		setupFile >> this->highscoreButtonImagePath ;
		setupFile >> this->toggleMusicButtonImagePath ;
		setupFile >> this->exitButtonImagePath ;
		
		setupFile.close() ;
	}
	*/
	
	FILE* setupFile = NULL ;
	
	setupFile = fopen(this->FILE_NAME , "r") ;
	
	if(setupFile == NULL)
	{
		printf("failed to open file") ;
	}
	else
	{
		fscanf(setupFile , "%d" , &this->playButtonRectX) ;
		fscanf(setupFile , "%d" , &this->playButtonRectY) ;
		fscanf(setupFile , "%d" , &this->highscoreButtonRectX) ;
		fscanf(setupFile , "%d" , &this->highscoreButtonRectY) ;
		fscanf(setupFile , "%d" , &this->toggleMusicButtonRectX) ;
		fscanf(setupFile , "%d" , &this->toggleMusicButtonRectY) ;
		fscanf(setupFile , "%d" , &this->exitButtonRectX) ;
		fscanf(setupFile , "%d" , &this->exitButtonRectY) ;
		
		fscanf(setupFile , "%s" , this->backgroundImagePath) ;
		fscanf(setupFile , "%s" , this->playButtonImagePath) ;
		fscanf(setupFile , "%s" , this->highscoreButtonImagePath) ;
		fscanf(setupFile , "%s" , this->toggleMusicButtonImagePath) ;
		fscanf(setupFile , "%s" , this->exitButtonImagePath) ;
		
		fclose(setupFile) ;
	}
	
}
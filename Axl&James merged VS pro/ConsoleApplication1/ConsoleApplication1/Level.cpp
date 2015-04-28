/* SEP ASSIGNMENT 2
Programmed by James Cookson */

#include "Level.h"

Level::Level()
{
	Node P;

	ifstream file; //Used for File IO, pointer to file did not work correctly so used this as alternative

	file.open("maze.txt"); //Open file

	file >> row >> col; //Retrieves row and column size data from file

	Maze = new Node *[row]; //Allocate memory for rows in file

	for (int i = 0; i < row; i++)
		Maze[i] = new Node[col]; //Allocate memory for columns in file

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			file >> Maze[i][j].value; //Retrieve maze data
			
			//Creates co-ordinates for Maze array, makes finding specific points easier
			Maze[i][j].y = j;
			Maze[i][j].x = i;

			if (Maze[i][j].value == 2) //If the number representing the player is found
			{
				startPoint.x = i;
				startPoint.y = j;
			}
			else
			{
				if (Maze[i][j].value == 3) //If the number representing the enemy is found
				{
					Enemy1.x = i;
					Enemy1.y = j;
				}
			}

		}
	}

	file.close(); //Close file
	
	PrintFile(); //Run PrintFile function
	PrintMaze(); //Run PrintMaze function
}

Level::~Level()
{
	for (int i = 0; i < row; i++)
	{
		delete Maze[i]; //Delete allocated memory
	}
	delete Maze; //Delete allocated memory
}

void Level::PrintFile()
{
	for (int i = 0; i < row; i++)
	{
		cout << "\t";
		for (int j = 0; j<col; j++)
		{
			cout << Maze[i][j].value << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void Level::PrintMaze()
{
	for (int i = 0; i<row; i++)
	{
		cout << "\t";
		//cout << i << "-> \t"; //Number rows for easier tracking

		for (int j = 0; j<col; j++)
		{
			if (Maze[i][j].value == 0)
			{
				cout << " "; //If there is an open space then a space is used to show it can be travelled through
			}
			else if (Maze[i][j].value == 2)
			{
				cout << char(80); //P character is drawn to represent player
			}
			else if (Maze[i][j].value == 3)
			{
				cout << char(69); //E character is drawn to represent enemy
			}
			else
			{
				cout << char(-37); //ASCII value 37 is a solid block, allows easy identification of maze walls
			}
		}
		cout << endl;
	}
	cout << endl << endl;
}
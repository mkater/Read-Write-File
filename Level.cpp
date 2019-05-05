#include"LevelDeclaration.h"


Level::Level(string fileName)	//constructor
{
	ifstream inputFile;
	inputFile.open(fileName, ios::in);	//opens inputted filename
	inputFile >> name;		//reads the string name of file...
	inputFile >> zSize;		//.. then takes in the z,x,y ints for size of 3d array.
	inputFile >> xSize;
	inputFile >> ySize;

	leveldata = new int**[zSize];		//creating level data of zsize

	for (int i = 0; i < zSize; i++)		//starting loop to dereference the 3d array
	{
		leveldata[i] = new int*[ySize];
		for (int j = 0; j < ySize; j++)		//next loop less than y size
		{
			leveldata[i][j] = new int[xSize];
			for (int k = 0; k < xSize; k++)	//final loop for last size variable.
			{
				inputFile >> leveldata[i][j][k]; //now the file reads in the variable of this position and loops.
			}
		}
	}
	inputFile >> zStart;	//takes in z start bottom of file
	inputFile.ignore(1);	//to ignore the . in the file.
	inputFile >> xStart;	//and it continues with last two start positions.
	inputFile >> yStart;



	inputFile.close();	//need to close file to end it.
	return;
}


void Level:: writeLevel(string filename)	//function to write to file
{
	ofstream fileOutput;	
	fileOutput.open(filename, ios::out|ios::trunc);	//opens the file, trunc to clear anything that was there before
	if (fileOutput.is_open() && fileOutput.good())	//while its good and there is data.
	{
		fileOutput << name << endl << endl;	//outputs name with two spaces.
		fileOutput << zSize << endl;		//outputs z,x,y sizes with appropriate spacing.
		fileOutput << xSize << endl;
		fileOutput << ySize << endl << endl;
	
			for (int i = 0; i < zSize; i++)	//triple nested loop to output each individual member of the maze.
			{
				for (int j = 0; j < ySize; j++)
				{
					for (int k = 0; k < xSize; k++)
					{
						fileOutput << leveldata[i][j][k] << " "; //outputs the members of the maze.
					}
					fileOutput << endl;
				}
				fileOutput << endl;
			}
			fileOutput << zStart << ". ";	//outputs the start variables with manual period.
			fileOutput << xStart << " ";
			fileOutput << yStart << " ";
		

	}
	fileOutput.close();
}
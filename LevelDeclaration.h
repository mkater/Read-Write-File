#pragma once
#include<string>
#include<fstream>
#include<iostream>
using namespace std;

class Level
{
public:

	Level(string filename);	//constructor for Level class
	void writeLevel(string fileName);	//takes in file to output content

private:
	string name;	//which will be filename
	int zSize;		//the sizes of 3d array
	int xSize;
	int ySize;
	int zStart;		//the start positions, used for end of array
	int xStart;
	int yStart;
	int ***leveldata;	//3d array pointer

};


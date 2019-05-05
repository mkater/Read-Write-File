#include"LevelDeclaration.h"
#include <iostream>
#include <string>
#include<fstream>
#include<vector>
#include<iterator>
#include<map>
using namespace std;


Level * readLevel(string filename)		//outside of Level class so it can return a Level.
{
	return new Level(filename);		//just returns a level with the string parameter filename
}

void writeLevel(string filename, Level * mazeLevel)	//outside of Level class to take a Level pointer
{
	mazeLevel->writeLevel(filename + "_Out");		//writes to filename + _out.
}
int main()
{
	
	string sLine;
	ifstream textFile;
	vector<string> fileList;
	fileList.push_back("level1.txt");	//filling string vector with the filenames
	fileList.push_back("level2.txt");
	fileList.push_back("level3.txt");
	for (int i = 0; i < fileList.size(); i++)	//looping through vector
	{
		textFile.open(fileList[i]);	//opening the file of each string
		textFile >> sLine;
		cout << sLine << endl;	//printing the first line
		textFile.close();		//closing the file
		//this is only printing the first line, the title of each of the levels.
	}
	
	map<string, Level*> mymap;		//creating map of string and level *
	for (int i = 0; i < fileList.size(); i++)	//looping through fileList vector
	{
		Level * mazeLevel = new Level(fileList[i]);	//creating a new Level out of each file.
		mymap.insert(pair<string, Level*>(fileList[i], mazeLevel));	//putting this level pointer into the map
	}
	
	map<string, Level*>::const_iterator itr;		//map iterator

	for (itr = mymap.begin(); itr != mymap.end(); itr++)
	{
		pair<string, Level*> p = *itr;	//iterating through the map
		writeLevel(p.first, p.second);	//writing out the file to the new file with writeLevel
	}
	
	cin.ignore();

}
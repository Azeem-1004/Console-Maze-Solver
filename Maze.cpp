#include "Maze.h"
#include<iostream>
#include<fstream>
#include<Windows.h>
#include"utility.h"
using namespace std;
Maze:: Maze()
{
	rows = 0;
	cols = 0;
}
int Maze::getRows()
{
	return rows;
}
int Maze::getCols()
{
	return cols;
}
int Maze::strlength(const char str[])
{
	int len = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		len++;
	}
	return len;
}
void Maze::printMaze()
{
	ifstream readfile;
	readfile.open("maze.txt");
	char read[50];
	//cin.ignore();
	bool firstline = true;

	while (readfile.getline(read, 50))
	{
		int len = strlength(read);
		if (firstline)
		{
			cols = len;
			firstline = false;
		}

		for (int i = 0; i < len; i++)
		{

			if (read[i] == '1')
			{
				SetColor(12, 12);
				cout << read[i];
				SetColor(0, 0);
			}
			else
			{
				cout << read[i];
			}
		}

		cout << endl;
		rows++;
	}
	readfile.close();
}

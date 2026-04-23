#pragma once
class Maze
{
private:
	int rows;
	int cols;
public:
	Maze();
	int getRows();
	int getCols();
	int strlength(const char str[]);
	void printMaze();
};


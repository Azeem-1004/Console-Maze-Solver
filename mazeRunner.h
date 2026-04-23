#pragma once
class mazeRunner
{
private:
	int prev_x, prev_y;
	int x, y;
	int color;
	int dir;
	int maze_rows, maze_cols;


public:
	static const int UP = 1;
	static const int RIGHT = 2;
	static const int DOWN = 3;
	static const int LEFT = 4;
	mazeRunner(int x, int y, int color, int maze_rows, int maze_cols);
	bool isMazeFinished();
	void printRunner();
	void updateDirection();
	void move();
};


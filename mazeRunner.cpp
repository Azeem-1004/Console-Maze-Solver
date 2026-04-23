#include "mazeRunner.h"
#include<iostream>
#include<fstream>
#include<Windows.h>
#include"utility.h"
using namespace std;

mazeRunner:: mazeRunner(int x, int y, int color, int maze_rows, int maze_cols)
	{
		this->x = x;
		this->y = y;
		this->color = color;
		dir = 1;
		this->maze_rows = maze_rows;
		this->maze_cols = maze_cols;
		prev_x = x;
		prev_y = y;

	}
	bool mazeRunner::isMazeFinished()
	{
		if (x == maze_cols || y == maze_rows)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void mazeRunner::printRunner()
	{
		setCursorAt(prev_x, prev_y);
		cout << " ";
		setCursorAt(x, y);
		SetColor(color, 0);
		cout << char(2);
		SetColor(7, 0);
		prev_x = x;
		prev_y = y;

	}
	void mazeRunner::updateDirection()
	{
		switch (dir)
		{
		case UP:
		{
			if (readFrom(x + 1, y) != '1')
			{
				dir = RIGHT;
			}
			else if (readFrom(x, y - 1) != '1')
			{
				dir = UP;
			}
			else if (readFrom(x - 1, y) != '1')
			{
				dir = LEFT;
			}
			else if (readFrom(x, y + 1) != '1')
			{
				dir = DOWN;
			}
			break;
		}
		case RIGHT:
		{
			if (readFrom(x, y + 1) != '1')
			{
				dir = DOWN;
			}
			else if (readFrom(x + 1, y) != '1')
			{
				dir = RIGHT;
			}
			else if (readFrom(x, y - 1) != '1')
			{
				dir = UP;
			}
			else if (readFrom(x - 1, y) != '1')
			{
				dir = LEFT;
			}
			break;
		}
		case DOWN:
		{
			if (readFrom(x - 1, y) != '1')
			{
				dir = LEFT;
			}
			else if (readFrom(x, y + 1) != '1')
			{
				dir = DOWN;
			}
			else if (readFrom(x + 1, y) != '1')
			{
				dir = RIGHT;
			}
			else if (readFrom(x, y - 1) != '1')
			{
				dir = UP;
			}
			break;
		}
		case LEFT:
		{
			if (readFrom(x, y - 1) != '1')
			{
				dir = UP;
			}
			else if (readFrom(x - 1, y) != '1')
			{
				dir = LEFT;
			}
			else if (readFrom(x, y + 1) != '1')
			{
				dir = DOWN;
			}
			else if (readFrom(x + 1, y) != '1')
			{
				dir = RIGHT;
			}
			break;
		}

		}
	}
	void mazeRunner::move()
	{
		updateDirection();
		switch (dir)
		{
		case UP:
		{
			y--;
			break;
		}
		case DOWN:
		{
			y++;
			break;
		}
		case LEFT:
		{
			x--;
			break;
		}
		case RIGHT:
		{
			x++;
			break;
		}
		}
	}

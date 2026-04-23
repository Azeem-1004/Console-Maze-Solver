#include<iostream>
#include<Windows.h>
#include"utility.h"
#include "Maze.h"
#include "mazeRunner.h"
using namespace std;



int main()
{
	Maze maze;
	maze.printMaze();
	int r = maze.getRows();
	int c = maze.getCols();

	mazeRunner runners[3] = { mazeRunner(1,1, 5, r, c), mazeRunner(21,8, 2, r, c), mazeRunner(14,8,11, r, c) };
	
	// --- NEW CODE: Variables to track the finish order ---
	int finishOrder[3]; // Stores the ID of the runners in the order they finish
	int finishedCount = 0; // Tracks how many runners have finished so far
	bool hasFinished[3] = {false, false, false}; // Keeps track of who has already crossed the line
	// -----------------------------------------------------

	while (1)
	{
		for (int i = 0; i < 3; i++)
		{
			if (!runners[i].isMazeFinished()) {
				runners[i].printRunner(); // Print runner at current position
				runners[i].move();        // Move to the next position	
			} 
			// --- NEW CODE: Check if a runner just crossed the finish line ---
			else if (!hasFinished[i]) { 
				finishOrder[finishedCount] = i; // Save the runner's index (0, 1, or 2)
				finishedCount++;                // Increment the total number of finishers
				hasFinished[i] = true;          // Mark this specific runner as finished so we don't count them again
			}
			// ----------------------------------------------------------------

			Sleep(50);           // Delay to visualize the movement
		}
		
		// --- UPDATED CODE: Break when all 3 have finished ---
		if (finishedCount == 3)
		{
			break;
		}
	}
	
	setCursorAt(0, r + 1); // Move the cursor below the maze after completion
	SetColor(15, 0);
	
	// --- NEW CODE: Print the final leaderboard ---
	cout << "--- RACE RESULTS ---" << endl;
	for(int i = 0; i < 3; i++) {
		// Adding +1 to the runner index so it prints "Runner 1, 2, 3" instead of "0, 1, 2"
		cout << "Position " << i + 1 << ": Runner " << finishOrder[i] + 1 << endl;
	}
	
	return 0;
}

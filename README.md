# Console-Maze-Solver

A C++ console-based application that simulates autonomous "runners" navigating and escaping a maze using the **Right-Hand Rule** pathfinding algorithm. 

## 🚀 Features
* **Algorithmic Pathfinding:** Implements the "Hand on the Wall" rule to guarantee an exit from the maze.
* **Concurrent Entity Movement:** Simulates three independent maze runners starting from different coordinates, navigating the maze simultaneously.
* **Direct Console Manipulation:** Utilizes the Windows API (`<windows.h>`) to directly modify console cursor positions (`SetConsoleCursorPosition`) for smooth, flicker-free rendering.
* **Object-Oriented Design:** Clean separation of concerns between grid management (`Maze` class) and entity logic (`mazeRunner` class).

## 🧠 How the Algorithm Works
The runners act completely autonomously without knowing the full map layout. They determine their next move by checking their immediate surroundings (top, bottom, left, right) and updating their direction based on the "Hand on the Wall" logic:
1. Prioritize keeping the wall to the "right".
2. If the path ahead is clear, move forward.
3. If there is a wall ahead, turn left.
4. If trapped in a dead end, turn around and backtrack.

## 💻 Tech Stack
* **Language:** C++
* **Libraries:** `<iostream>`, `<fstream>`, `<windows.h>`
* **Core Concepts:** Object-Oriented Programming (OOP), File I/O, Win32 API Console Output

👨‍💻 Author
Azeem Raza

#include<windows.h>
#include"utility.h"
void setCursorAt(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//https://learn.microsoft.com/en-us/windows/console/readconsoleoutputcharacter

char readFrom(int x, int y)
{
	char ch; // Use a simple local variable on the stack instead of dynamic memory
	COORD readCoord;
	readCoord.X = x; 
	readCoord.Y = y;
	DWORD num_read = 0;
	
	// Pass the address of 'ch' (&ch) to store the read character
	ReadConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), (LPTSTR)&ch, 1, readCoord, (LPDWORD)&num_read);
	
	return ch; // Return the character
}
//
//



void SetColor(int textcol, int backcol)
{
	bool textcolorprotect = false; //for future use
	/*doesn't let textcolor be the same as backgroung color if true*/
	/*if (textcolorprotect)
	{
		if ((textcol % 16) == (backcol % 16))
			textcol++;
	}*/
	textcol %= 16;
	backcol %= 16;
	unsigned short wAttributes = (unsigned)textcol | ((unsigned)backcol << 4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wAttributes);
}

void SetColor(ConsoleColor textcol, ConsoleColor backcol)
{
	SetColor(int(textcol), int(backcol));
}

int getTextColor()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	int a = csbi.wAttributes;
	return a % 16;
}

int getBackColor()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	int a = csbi.wAttributes;
	return (a / 16) % 16;
}
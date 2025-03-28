#include "ConsoleControl.h"

void ConsoleSetColor(ConsoleColor ForeColor, ConsoleColor BackColor){
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD color = (BackColor << 4) | ForeColor;
	SetConsoleTextAttribute(hstdout, color);
}

void ConsoleXY(short int x, short int y){
	COORD pos = { x, y };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(console, pos);
}
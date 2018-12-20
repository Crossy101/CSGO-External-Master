#include <iostream>
#include <Windows.h>

#include "cCheat.h"

using namespace std;

int main()
{
	cCheat* Cheat = new cCheat();
	HWND ConsoleWindow = GetConsoleWindow();
	ShowWindow(ConsoleWindow, SW_HIDE);
	Cheat->MainLoop();
}
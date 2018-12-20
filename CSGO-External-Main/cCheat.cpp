#include "cCheat.h"

cCheat::cCheat()
{
	
}

cCheat::~cCheat()
{
	delete ModuleFinder;
	delete ProcessFinder;
	delete EspCheat;
}

void cCheat::MainLoop()
{
	//If the console is open for 30 secs and game is not open, exit!
	this->startTimer = GetTickCount();
	while (!FindGameWindow())
	{
		Sleep(1000);
		this->endTimer = GetTickCount() - startTimer;

		if (this->endTimer >= 30000)
		{
			exit(EXIT_SUCCESS);
		}
	}
	//Check if user has quit
	while (!userQuit)
	{
		if (GetAsyncKeyState(VK_F4))
		{
			userQuit = true;
		}

		if (GetAsyncKeyState(VK_F1))
		{
			ESPEnabled = !ESPEnabled;
		}

		if (ESPEnabled)
		{
			EspCheat->EnableESP(ModuleFinder->GetClientAddress(), ModuleFinder, ProcessFinder);
		}
		Sleep(10);

		if (!FindGameWindow())
		{
			cout << "CSGO has been closed shutting down!" << endl;
			Sleep(1000);
			exit(EXIT_SUCCESS);
		}
	}
	exit(EXIT_SUCCESS);
}

//Finds Game Window
bool cCheat::FindGameWindow()
{
	if (FindWindow(NULL, this->WindowName) == NULL)
	{
		return false;
	}
	else
		return true;
}


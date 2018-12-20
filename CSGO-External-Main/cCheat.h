#pragma once

#include "cProcessFind.h"
#include "cModuleFind.h"
#include "cESP.h"

class cCheat
{
private:
	cProcessFind* ProcessFinder = new cProcessFind();
	cModuleFind* ModuleFinder = new cModuleFind(ProcessFinder->GetProcessID());
	cESP* EspCheat = new cESP();

	//Window Name
	const char* WindowName = "Counter-Strike: Global Offensive";

	//User Quit Check
	bool userQuit = false;
	
	//Game Hack Checks Enabled
	bool ESPEnabled = false;

	//Game Window Check
	bool FindGameWindow();

	//Timers
	int startTimer;
	int endTimer;

	//Debounce Timers
	int mainTimer = 1000;
	int ESPDebounceTimer = NULL;

	//Debounce bools
	bool ESPDebounce = false;
public:
	cCheat();
	~cCheat();
	
	void MainLoop();
};


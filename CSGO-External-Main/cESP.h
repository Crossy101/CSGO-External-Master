#pragma once

#include "cESP.h"
#include "cMemManager.h"
#include "cModuleFind.h"
#include "cProcessFind.h"

class cESP
{
private:
	cMemManager* MemoryManager = new cMemManager();

	//ESP Colours
	float r = 0;
	float g = 1;
	float b = 0;
	float a = 1;

	//ESP Checks
	bool visOne = true;
	bool visTwo = false;
public:
	cESP();

	void EnableESP(DWORD clientAddress, cModuleFind* ModuleFinder, cProcessFind* ProcessFinder);
};


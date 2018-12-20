#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

class cModuleFind
{
private:
	int processID;

	const char* ClientModule = "client_panorama.dll";
	const char* EngineModule = "engine.dll";

	DWORD ClientAddress;
	DWORD EngineAddress;

	DWORD FindModule(const char* moduleName);

	bool FindClientModule();
	bool FindEngineModule();
public:
	cModuleFind(int _processID);

	int GetProcessID();
	DWORD GetClientAddress();
	DWORD GetEngineAddress();
};


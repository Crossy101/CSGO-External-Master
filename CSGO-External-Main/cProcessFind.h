#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

class cProcessFind
{
private:
	const char* processName = "csgo.exe";

	DWORD processID;
	HANDLE hProc;

	bool FindProcessHandle();
	bool FindProcessID();

public:
	cProcessFind();

	int GetProcessID();
	HANDLE GetProcessHandle();
};


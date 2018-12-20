#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

#include "cModuleFind.h"

using namespace std;

cModuleFind::cModuleFind(int _processID)
{
	this->processID = _processID;
	this->FindClientModule();
	this->FindEngineModule();
}

bool cModuleFind::FindClientModule()
{
	this->ClientAddress = FindModule(this->ClientModule);

	if (this->ClientAddress == 1)
		return false;
	else
		return true;
}

bool cModuleFind::FindEngineModule()
{
	this->EngineAddress = FindModule(this->EngineModule);

	if (this->EngineAddress != NULL)
		return true;
	else
		return false;
}


DWORD cModuleFind::FindModule(const char* moduleName)
{
	HANDLE snapHandle = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, this->processID);
	if (snapHandle == INVALID_HANDLE_VALUE)
	{
		std::cout << "Could not grab Snapshot" << std::endl;
		CloseHandle(snapHandle);
		return 0;
	}

	MODULEENTRY32 CMC32;
	CMC32.dwSize = sizeof(MODULEENTRY32);

	if (!Module32First(snapHandle, &CMC32))
	{
		cout << "Cannot find the Module!" << std::endl;
		CloseHandle(snapHandle);
		return 0x0;
	}

	do
	{
		if (strcmp(CMC32.szModule, moduleName) == 0)
		{
			CloseHandle(snapHandle);
			cout << "Found Module! " << CMC32.szModule << std::endl;
			return (DWORD)CMC32.modBaseAddr;
		}
		cout << "Module: " << CMC32.szModule << " " << "Searching For: " << moduleName << endl;
		Sleep(10);
	} while (Module32Next(snapHandle, &CMC32));
	CloseHandle(snapHandle);
}

DWORD cModuleFind::GetClientAddress()
{
	return this->ClientAddress;
}

DWORD cModuleFind::GetEngineAddress()
{
	return this->EngineAddress;
}

int cModuleFind::GetProcessID()
{
	return this->processID;
}



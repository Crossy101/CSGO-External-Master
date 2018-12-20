#include <iostream>
#include <Windows.h>

#include "cMemManager.h"

using namespace std;

cMemManager::cMemManager()
{
}

//WRITE MEMORY
bool cMemManager::cWriteMem(HANDLE csWindow, DWORD addressToWrite, int addressValue)
{
	return WriteProcessMemory(csWindow, (LPVOID)addressToWrite, &addressValue, sizeof(addressValue), NULL);
}

bool cMemManager::cWriteMem(HANDLE csWindow, DWORD addressToWrite, bool addressValue)
{
	return WriteProcessMemory(csWindow, (LPVOID)addressToWrite, &addressValue, sizeof(addressValue), NULL);
}

bool cMemManager::cWriteMem(HANDLE csWindow, DWORD addressToWrite, float addressValue)
{
	return WriteProcessMemory(csWindow, (LPVOID)addressToWrite, &addressValue, sizeof(addressValue), NULL);
}

bool cMemManager::cWriteMem(HANDLE csWindow, DWORD addressToWrite, DWORD addressValue)
{
	return WriteProcessMemory(csWindow, (LPVOID)addressToWrite, &addressValue, sizeof(addressValue), NULL);
}

//READ MEMORY
int cMemManager::cReadMem(HANDLE csWindow, DWORD addressToCopy, int addressValue)
{
	int tempInt = addressValue;
	ReadProcessMemory(csWindow, (LPCVOID)addressToCopy, &tempInt, sizeof(tempInt), NULL);
	return tempInt;
}

bool cMemManager::cReadMem(HANDLE csWindow, DWORD addressToCopy, bool addressValue)
{
	bool tempBool = addressValue;
	ReadProcessMemory(csWindow, (LPCVOID)addressToCopy, &tempBool, sizeof(tempBool), NULL);
	return tempBool;
}

float cMemManager::cReadMem(HANDLE csWindow, DWORD addressToCopy, float addressValue)
{
	float tempFloat = addressValue;
	ReadProcessMemory(csWindow, (LPCVOID)addressToCopy, &tempFloat, sizeof(tempFloat), NULL);
	return tempFloat;
}

DWORD cMemManager::cReadMem(HANDLE csWindow, DWORD addressToCopy, DWORD addressValue)
{
	DWORD tempAddress = addressValue;
	ReadProcessMemory(csWindow, (LPCVOID)addressToCopy, &tempAddress, sizeof(tempAddress), NULL);
	return tempAddress;
}

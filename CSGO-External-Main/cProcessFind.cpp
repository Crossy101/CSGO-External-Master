#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <string>

#include "cProcessFind.h"

using namespace std;

cProcessFind::cProcessFind()
{
	this->FindProcessID();
	this->FindProcessHandle();
}

bool cProcessFind::FindProcessID()
{
	HANDLE procHandle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (procHandle == INVALID_HANDLE_VALUE)
	{
		std::cout << "Could not get Snapshot (Process)." << std::endl;
		this->processID = 0x0;
		return false;
	}

	PROCESSENTRY32 CMC32;
	CMC32.dwSize = sizeof(PROCESSENTRY32);

	if (!Process32First(procHandle, &CMC32))
	{
		std::cout << "Cannot find a process!" << std::endl;
		CloseHandle(procHandle);
		this->processID = 0x0;
		return false;
	}

	do {
		if (strcmp(CMC32.szExeFile, this->processName) == 0)
		{
			CloseHandle(procHandle);
			this->processID = CMC32.th32ProcessID;
			return true;
			cout << "Process: " << CMC32.szExeFile << "Checking: " << this->processName << endl;
		}
	} while (Process32Next(procHandle, &CMC32));
	CloseHandle(procHandle);
	return false;
}

bool cProcessFind::FindProcessHandle()
{
	this->hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
	if (hProc == NULL)
	{
		cout << "Process cannot be attached" << endl;
		return false;
	}
	else
		return true;
}

int cProcessFind::GetProcessID()
{
	return this->processID;
}

HANDLE cProcessFind::GetProcessHandle()
{
	return this->hProc;
}

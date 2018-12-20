#pragma once
class cMemManager
{
private:
public:
	cMemManager();

	//WriteToMemory Start
	bool cWriteMem(HANDLE csWindow, DWORD addressToWrite, int addressValue);
	bool cWriteMem(HANDLE csWindow, DWORD addressToWrite, bool addressValue);
	bool cWriteMem(HANDLE csWindow, DWORD addressToWrite, float addressValue);
	bool cWriteMem(HANDLE csWindow, DWORD addressToWrite, DWORD addressValue);
	

	//ReadMemory Start
	int cReadMem(HANDLE csWindow, DWORD addressToCopy, int addressValue);
	bool cReadMem(HANDLE csWindow, DWORD addressToCopy, bool addressValue);
	float cReadMem(HANDLE csWindow, DWORD addressToCopy, float addressValue);
	DWORD cReadMem(HANDLE csWindow, DWORD addressToCopy, DWORD addressValue);
};


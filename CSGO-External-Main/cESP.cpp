#include <iostream>
#include <Windows.h>

#include "cESP.h"
#include "cModuleFind.h"
#include "cProcessFind.h"
#include "Offsets.h"

using namespace std;

cESP::cESP()
{

}

void cESP::EnableESP(DWORD clientAddress, cModuleFind* ModuleFinder, cProcessFind* ProcessFinder)
{
	DWORD localPlayer = NULL;
	DWORD glowIndex = NULL;

	int mTeam = 0;

	localPlayer = MemoryManager->cReadMem(ProcessFinder->GetProcessHandle(), (clientAddress + hazedumper::dwLocalPlayer), localPlayer);
	mTeam = MemoryManager->cReadMem(ProcessFinder->GetProcessHandle(), (localPlayer + hazedumper::m_iTeamNum), mTeam);

	if (!localPlayer) return;

	//Might be wrong
	glowIndex = MemoryManager->cReadMem(ProcessFinder->GetProcessHandle(), (clientAddress + hazedumper::dwGlowObjectManager), glowIndex);

	for (int i = 0; i < 32; i++)
	{
		DWORD entity = NULL;
		DWORD playerGlow = NULL;
		int tNum = NULL;
		int health = NULL;

		entity = MemoryManager->cReadMem(ProcessFinder->GetProcessHandle(), (clientAddress + hazedumper::dwEntityList + (i * 0x10)), entity);
		playerGlow = MemoryManager->cReadMem(ProcessFinder->GetProcessHandle(), entity + hazedumper::m_iGlowIndex, playerGlow);
		tNum = MemoryManager->cReadMem(ProcessFinder->GetProcessHandle(), entity + hazedumper::m_iTeamNum, tNum);
		health = MemoryManager->cReadMem(ProcessFinder->GetProcessHandle(), entity + hazedumper::m_iHealth, health);

		if (mTeam != tNum && health >= 1)
		{
			MemoryManager->cWriteMem(ProcessFinder->GetProcessHandle(), (glowIndex + (playerGlow * 0x38 + 0x4)), this->r);
			MemoryManager->cWriteMem(ProcessFinder->GetProcessHandle(), (glowIndex + (playerGlow * 0x38 + 0x8)), this->g);
			MemoryManager->cWriteMem(ProcessFinder->GetProcessHandle(), (glowIndex + (playerGlow * 0x38 + 0xC)), this->b);

			MemoryManager->cWriteMem(ProcessFinder->GetProcessHandle(), (glowIndex + (playerGlow * 0x38 + 0x10)), this->a);

			MemoryManager->cWriteMem(ProcessFinder->GetProcessHandle(), (glowIndex + (playerGlow * 0x38 + 0x24)), this->visOne);
			MemoryManager->cWriteMem(ProcessFinder->GetProcessHandle(), (glowIndex + (playerGlow * 0x38 + 0x25)), this->visTwo);
		}
	}
}

// dllmain.cpp : DLL アプリケーションのエントリ ポイントを定義します。
#include "pch.h"
#include "dllmain.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

SIZE_T GetWorkingSet()
{
	PROCESS_MEMORY_COUNTERS info;
	if (!GetProcessMemoryInfo(GetCurrentProcess(), &info, sizeof(info)))
	{
		return 0;
	}
	return info.WorkingSetSize;
}

SIZE_T GetCommitSize()
{
	PROCESS_MEMORY_COUNTERS_EX info;
	if (!GetProcessMemoryInfo(
		GetCurrentProcess(),
		(PROCESS_MEMORY_COUNTERS*)&info,
		sizeof(info)
	))
	{
		return 0;
	}
	return info.PrivateUsage;
}

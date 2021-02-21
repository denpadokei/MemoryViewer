#pragma once

extern "C"
{
	__declspec(dllexport) unsigned long GetWorkingSet();
	__declspec(dllexport) unsigned long GetCommitSize();
}
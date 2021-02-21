#pragma once

extern "C"
{
	__declspec(dllexport) SIZE_T GetWorkingSet();
	__declspec(dllexport) SIZE_T GetCommitSize();
}
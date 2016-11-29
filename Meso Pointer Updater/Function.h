#pragma once

#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <Windows.h>
#include <dbghelp.h>
#include <psapi.h>

#pragma  comment(lib, "dbghelp")
#pragma  comment(lib, "psapi")

#define PFAPI __stdcall
#define MAX_PATTERN 255

#define PF_NONE 0
#define PF_INVALID 1
#define PF_NOT_FOUND 2
#define PF_OVERFLOW 3

class Function
{

public:

	struct PFSEARCH
	{
		DWORD dwLength;
		char szMask[MAX_PATTERN+1];
		BYTE lpbData[MAX_PATTERN];
		LPVOID lpvResult;
	};

	BOOL GetModuleSize(HMODULE hModule, LPVOID* lplpBase, LPDWORD lpdwSize);
	DWORD PFAPI GetPatternCB(char *szPattern);
	BOOL PFAPI GeneratePatternMask(char *szPattern, char *buffer);
	BOOL PFAPI GeneratePatternBytes(char *szPattern, LPBYTE buffer);
	VOID PFAPI SearchPattern(PFSEARCH *ppf, LPVOID lpvBase, DWORD dwSize);
	DWORD PFAPI FindPattern(char *szPattern, PFSEARCH *ppf, LPVOID lpvBase, DWORD dwSize);

};

extern Function* pFunction;

#endif
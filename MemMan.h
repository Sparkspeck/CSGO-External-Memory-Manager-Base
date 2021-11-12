#pragma once
#include <Windows.h>
#include <vector>
class MemMan
{
public:
	MemMan();
	~MemMan();
	template <class val>
	val readMem(DWORD addr)
	{
		val x;
		ReadProcessMemory(handle, (LPBYTE*)addr, &x, sizeof(x), NULL);
		return x;
	}
	template <class val>
	val writeMem(DWORD addr, val x)
	{
		WriteProcessMemory(handle, (LPBYTE*)addr, &x, sizeof(x), NULL);
		return x;
	}

	uintptr_t getProcess(const char*);
	uintptr_t getModule(DWORD, const char*);
	uintptr_t getAddress(DWORD, std::vector<DWORD>);
	HANDLE handle;

};
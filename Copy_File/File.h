#pragma once
#include <windows.h>
#include <string>
class File
{
public:
	
	void My_CreateFile();
	void My_WriteFile();
	void My_CopyFile();
	void SetPathFrom(LPCSTR);
	void SetPathTo(LPCSTR);
	//int CopyFile(L"linkFile.txt", L"File2.txt", false);
private:
	HANDLE m_hFile = 0;
	LPCSTR m_path_from;
	LPCSTR m_path_to;
};


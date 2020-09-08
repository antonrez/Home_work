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
	void checkFile(char* file_name);
	void New_CopyFile();

private:
	HANDLE m_hFile = 0;
	HANDLE m_cFile = 0;
	LPCSTR m_path_from;
	LPCSTR m_path_to;
	int open;
};


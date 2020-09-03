#include "File.h"
#include <windows.h>
#include <iostream>


void File::My_CreateFile()
{
    m_hFile = CreateFileA(
        m_path_from,
        //"greet.txt",LPCSTR
        GENERIC_WRITE | GENERIC_READ,
        0,
        NULL,
        OPEN_ALWAYS,
        //CREATE_NEW,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );
    if (m_hFile == INVALID_HANDLE_VALUE)
    {
        std::cout << "File not created"<< std::endl;
    }
    else
    {
        std::cout << "File created name: " << m_path_from << std::endl;
    }

}

void File::My_WriteFile()
{
    char DataBuffer[] = "This is some test data to write to the file2.";
    DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
    DWORD dwBytesWritten = 0;
    BOOL bErrorFlag = FALSE;

    bErrorFlag = WriteFile(
        m_hFile,
        &DataBuffer,      // start of data to write
        dwBytesToWrite,  // number of bytes to write
        &dwBytesWritten, // number of bytes that were written
        NULL
    );
    if (WriteFile) {
        std::cout << "Writing to file." << std::endl;
    }
    else
    {
        std::cout << "The file was not written" << std::endl;
    }
    CloseHandle(m_hFile);

}

void File::My_CopyFile()
{
    CopyFileA(
        m_path_from,
        m_path_to,
        false);

    if (CopyFileA) {
        std::cout << "File copy  name: " << m_path_to << std::endl;
    }
    else
    {
        std::cout << "File not copy" << std::endl;
    }
}

void File::SetPathFrom(LPCSTR data)
{
    m_path_from = data;
}

void File::SetPathTo(LPCSTR data)
{
    m_path_to = data;
}

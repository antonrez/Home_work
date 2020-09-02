// Copy_File.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>

int main()
{

    HANDLE hFile;
    char DataBuffer[] = "This is some test data to write to the file2.";
    DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
    DWORD dwBytesWritten = 0;
    BOOL bErrorFlag = FALSE;

   
   
    hFile = CreateFileA(
        "linkFile.txt",
        GENERIC_WRITE | GENERIC_READ,   
        0,                             
        NULL,                           
        OPEN_ALWAYS,    
        //CREATE_NEW,
        FILE_ATTRIBUTE_NORMAL,         
        NULL                           
    );                  
    if (hFile == INVALID_HANDLE_VALUE)
    {
        std::cout << "File not created" << std::endl;
        return 0;
    }
    else 
    {
        std::cout << "File created" << std::endl;
    }

    bErrorFlag = WriteFile(
        hFile,
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
    CloseHandle(hFile);


    CopyFile(L"linkFile.txt", L"File2.txt", false);
    
}


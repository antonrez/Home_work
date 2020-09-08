#include "File.h"
#include <windows.h>
#include <iostream>
#include <exception>
#include <io.h>
#include <stdlib.h>
bool FileExists(LPCSTR fname)
{
    _finddata_t data;
    long nFind = _findfirst(fname, &data);
    if (nFind != -1)
    {
        // Если этого не сделать, то произойдет утечка ресурсов
        _findclose(nFind);
        return true;
    }
    return false;
};

void File::My_CreateFile()
{
    if (FileExists(m_path_from))
    {
        int x;
        std::cout << "file exist. Overwrite?(1/0)" << std::endl;
        std::cin >> x;
        if (x==1)
            {
                m_hFile = CreateFileA(
                    m_path_from,
                    GENERIC_WRITE | GENERIC_READ,
                    0,
                    NULL,
                    OPEN_ALWAYS,
                    FILE_ATTRIBUTE_NORMAL,
                    NULL
                );
            }
       
        if (x != 1) {
            try
            {
                if (x!=1)
                    throw "File not created";
            }
            catch (const char* exception)
            {
                std::cerr << "Error: " << exception << '\n';
            }
            }
              
    }
    else {
        m_hFile = CreateFileA(
            m_path_from,
            GENERIC_WRITE | GENERIC_READ,
            0,
            NULL,
            CREATE_NEW,
            FILE_ATTRIBUTE_NORMAL,
            NULL
        );
    }
  
    try 
    {
        if (m_hFile == INVALID_HANDLE_VALUE)
            throw "File not created";
    }
    catch (const char* exception)
    {
        std::cerr << "Error: " << exception << '\n';
    }


}

void File::My_WriteFile()
{
    char DataBuffer[] = "This is some test data to write to the file. This is some test data to write to the file.";
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



    try
    {
        if (!bErrorFlag)
            throw "File not write";
    }
    catch (const char* exception)
    {
        std::cerr << "Error: " << exception << '\n';
    }
    CloseHandle(m_hFile);

}

void File::My_CopyFile()
{
   
    BOOL res = CopyFileA(
        m_path_from,
        m_path_to,
        false);
    if (!res)
        std::cerr <<"File not copy";

}

void File::SetPathFrom(LPCSTR data)
{
    m_path_from = data;
}

void File::SetPathTo(LPCSTR data)
{
    m_path_to = data;
}

void File::New_CopyFile()
{
    m_hFile = CreateFileA(
        m_path_from,
        GENERIC_READ,
        0,
        NULL,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );
    
   
    int lpBufer;
    DWORD BytesRead;
    BOOL bErrorFlag = FALSE;
    int  dwSize = GetFileSize(m_hFile, NULL);
    char* DataBuffer = new char[dwSize];
    //char DataBuffer[dwSize];

    ReadFile(
        m_hFile,            //дискриптор файла
        DataBuffer,           //адрес дуф файла
        //&DataBuffer,           //адрес дуф файла
        dwSize,    //количество читаемых байтов
        //sizeof(DataBuffer),    //количество читаемых байтов
        &BytesRead,
        NULL
    );
   
   
    CloseHandle(m_hFile);
    m_cFile = CreateFileA(
        m_path_to,
        GENERIC_WRITE | GENERIC_READ,
        FILE_SHARE_WRITE,
        NULL,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );
   
    
    DWORD dwBytesToWrite = dwSize;
    DWORD dwBytesWritten = 0;
   
    bErrorFlag = WriteFile(
        m_cFile,
        DataBuffer,
        dwBytesToWrite,  // number of bytes to write
        &dwBytesWritten, // number of bytes that were written
        NULL
    );
    CloseHandle(m_cFile);
    delete[] DataBuffer;

}

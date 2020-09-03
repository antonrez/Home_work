// Copy_File.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "File.h"
int main()
{
    File file;
    file.SetPathFrom("greetNew.txt");
    file.SetPathTo("greetCopy.txt");
    file.My_CreateFile();
    file.My_WriteFile();
    file.My_CopyFile();
}


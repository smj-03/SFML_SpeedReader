#pragma once
#include "API.h"
#include <windows.h>
#include <commdlg.h>   // For GetOpenFileName
#include <fstream>     // For std::ifstream
#include <sstream>     // For std::stringstream
#include <iostream>    // For std::cout
#include <tchar.h>     // For _T and TCHAR macros


class EXPORT_API FileExplorer {

public:

	std::wstring OpenTextFileDialog();

	std::wstring ReadFileContent(const std::wstring& filePath);

private:

};
#pragma once
#include "API.h"
#include <windows.h>
#include <commdlg.h>   // For GetOpenFileName
#include <fstream>     // For std::ifstream
#include <sstream>     // For std::stringstream
#include <iostream>    // For std::cout
#include <tchar.h>     // For _T and TCHAR macros
#include <locale.h>    // For Polish signs
#include <ctime>
#include <chrono>
#include <exception>

class EXPORT_API FileExplorer {

public:

	std::wstring OpenTextFileDialog();

	std::wstring ReadFileContent(const std::wstring& filePath);

	void SaveFileContent(const std::wstring& content);

private:

};
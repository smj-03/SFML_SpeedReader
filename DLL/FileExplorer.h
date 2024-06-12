#pragma once
#include "API.h"
#include <windows.h>
#include <commdlg.h>
#include <fstream>  
#include <sstream>     
#include <iostream>    
#include <tchar.h>  
#include <locale.h>  
#include <ctime>
#include <chrono>
#include <exception>
#include <direct.h>

class EXPORT_API FileExplorer {

public:

	std::wstring OpenTextFileDialog();

	std::wstring ReadFileContent(const std::wstring& filePath);

	void SaveFileContent(const std::wstring& content);

private:

};
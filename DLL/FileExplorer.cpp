#include "FileExplorer.h"
#include <iostream>

std::wstring FileExplorer::OpenTextFileDialog() {
    OPENFILENAME ofn;       // Common dialog box structure
    TCHAR szFile[260] = { 0 };       // Buffer for file name

    // Initialize OPENFILENAME
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile) / sizeof(TCHAR);
    ofn.lpstrFilter = _T("Text Files\0*.txt\0All Files\0*.*\0");
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;


    // Display the Open dialog box
    if (GetOpenFileName(&ofn) == TRUE) {
        std::wcout << ofn.lpstrFile;
        return std::wstring(ofn.lpstrFile);
    }

    return std::wstring();
}

std::wstring FileExplorer::ReadFileContent(const std::wstring& filePath) {

    std::wifstream file(filePath);
    if (!file.is_open()) {
        std::wcerr << _T("Could not open file: ") << filePath << std::endl;
        return std::wstring();
    }

    std::wstringstream wss;
    wss << file.rdbuf();
    std::wcout << wss.str();
    return wss.str();

}
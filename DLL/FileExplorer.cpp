#include "FileExplorer.h"
#include <iostream>

// UKRADZIONE Z INTERNETÓW
std::wstring FileExplorer::OpenTextFileDialog() {
    OPENFILENAME ofn;     
    TCHAR szFile[260] = { 0 };  

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

    file.imbue(std::locale("en_US.UTF-8"));

    std::wstringstream wss;
    wss << file.rdbuf();
    std::wcout << wss.str();
    return wss.str();
}

void FileExplorer::SaveFileContent(const std::wstring& content) {
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::tm timeinfo;
    localtime_s(&timeinfo, &time);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), ".\\texts\\output_%Y-%m-%d_%H-%M-%S.txt", &timeinfo);

    // Ensure the directory exists
    if (_mkdir(".\\texts") != 0 && errno != EEXIST) {
        std::wcerr << L"Could not create directory: .\\texts" << std::endl;
        return;
    }

    std::wofstream file(buffer);
    if (!file.is_open()) {
        std::wcerr << L"Could not create or open file: " << buffer << std::endl;
        return;
    }

    file.imbue(std::locale("en_US.UTF-8"));
    file << content;
    file.close();

    std::wcout << L"Content saved to file: " << buffer << std::endl;
}
#include "FileExplorer.h"

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
        m_lastOpenedFilePath = std::wstring(ofn.lpstrFile);
        std::wcout << m_lastOpenedFilePath << std::endl;
        return m_lastOpenedFilePath;
    }

    return std::wstring();
}

std::wstring FileExplorer::ReadFileContent(const std::wstring& filePath) {
    std::wifstream file(filePath);
    if (!file.is_open()) {
        std::wcerr << L"Could not open file: " << filePath << std::endl;
        return std::wstring();
    }

    file.imbue(std::locale("en_US.UTF-8"));

    std::wstringstream wss;
    wss << file.rdbuf();
    std::wcout << wss.str() << std::endl;
    return wss.str();
}

void FileExplorer::SaveFileContent(const std::wstring& content) {
    if (m_lastOpenedFilePath.empty()) {
        std::wcerr << L"No file has been opened for saving." << std::endl;
        return;
    }

    // Use the directory of the last opened file for saving
    size_t lastSlashIndex = m_lastOpenedFilePath.find_last_of(L"\\");
    std::wstring directory = m_lastOpenedFilePath.substr(0, lastSlashIndex + 1);

    // Generate filename with timestamp
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::tm timeinfo;
    localtime_s(&timeinfo, &time);

    // Format timestamp for the filename
    std::wstringstream filename;
    filename << directory
        << L"output_" << std::put_time(&timeinfo, L"%Y-%m-%d_%H-%M-%S") << L".txt";

    std::wstring filePathToSave = filename.str();

    // Open file for writing
    std::wofstream file(filePathToSave);
    if (!file.is_open()) {
        std::wcerr << L"Could not create or open file: " << filePathToSave << std::endl;
        return;
    }

    // Set UTF-8 encoding
    file.imbue(std::locale("en_US.UTF-8"));

    // Write content to file
    file << content;

    // Close file
    file.close();

    std::wcout << L"Content saved to file: " << filePathToSave << std::endl;
}
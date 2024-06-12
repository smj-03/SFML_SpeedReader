#include "SpeedReader.h"
#include <SFML/Graphics.hpp>
#include "TextSplitter.h"
#include <windows.h>

#define _WIN32_WINNT 0x0500


int main() {

	//HWND hWnd = GetConsoleWindow();
	//ShowWindow(hWnd, SW_HIDE);

	SpeedReader SR;
	SR.loadResources();
	SR.initialize();
	SR.loop();

	return 0;
};
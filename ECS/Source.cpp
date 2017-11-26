#include <iostream>
#include "MetroidGame.h"
#include "Define.h"
using namespace std;
#include <windows.h>



int WINAPI WinMain(
	HINSTANCE ins,
	HINSTANCE hPrevInstance,
	LPSTR lpStrCmdLine,
	int nShowCmd)
{

	MetroidGame *metroid=new MetroidGame (ins, L"Metroid", GAME_SCREEN_RESOLUTION_640_480_24, 0, 60);

	metroid->runGame();

	return 0;
}
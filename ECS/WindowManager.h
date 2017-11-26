#ifndef WINDOWMANAGER_H_
#define WINDOWMANAGER_H_

#include "WindowResolution.h"

class WindowManager
{
private:

	WindowResolution* windowResolution; // setting screen width and height

	HINSTANCE	hInstance;
	HWND		hWnd;
	LPWSTR		name;


	int			isFullScreen;	// Is running in fullscreen mode?

	int			mode;

	static LRESULT CALLBACK _WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
public:
	~WindowManager();
	WindowManager(HINSTANCE hInstance, LPWSTR Name, int Mode, int isFullScreen);

	void InitWindow();
	int CheckIsFullScreen();

	// getter - setter
	WindowResolution* getWindowResolution();
	HINSTANCE GetHInstance();
	HWND	GetHwnd();

	void release();
};

#endif // !WINDOWMANAGER_H_



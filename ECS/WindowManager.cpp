#include "WindowManager.h"

LRESULT WindowManager::_WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

WindowManager::~WindowManager()
{
}

WindowManager::WindowManager(HINSTANCE hInstance, LPWSTR name, int mode, int isFullScreen)
{
	this->hInstance = hInstance;
	this->name = name;
	this->mode = mode;
	this->isFullScreen = isFullScreen;
	this->windowResolution = new WindowResolution(mode);
}

void WindowManager::InitWindow()
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = this->hInstance;

	wc.lpfnWndProc = (WNDPROC)_WinProc;
	wc.cbWndExtra =0;
	wc.cbClsExtra =  0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = this->name;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	DWORD style;
	if (this->isFullScreen)
		style = WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP;
	else
		style = WS_OVERLAPPEDWINDOW;

	this->hWnd = CreateWindowEx(NULL,
		this->name,
		this->name,
		style,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		this->windowResolution->getScreenWidth(),
		this->windowResolution->getScreenHeight(),
		NULL,
		NULL,
		this->hInstance,
		NULL);

	if (!this->hWnd)
		DWORD ErrCode = GetLastError();

	ShowWindow(this->hWnd, SW_SHOWNORMAL);
	UpdateWindow(this->hWnd);

}

int WindowManager::CheckIsFullScreen() { return isFullScreen; }


WindowResolution*  WindowManager::getWindowResolution() { return windowResolution; }

HINSTANCE WindowManager::GetHInstance() { return hInstance; }

HWND WindowManager::GetHwnd() { return hWnd; }

void WindowManager::release()
{
	
}

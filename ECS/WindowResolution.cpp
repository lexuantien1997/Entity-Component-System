#include "WindowResolution.h"


WindowResolution::WindowResolution(int mode)
{
	
	switch (mode)
	{
	case GAME_SCREEN_RESOLUTION_640_480_24:
		screenWidth = 640;
		screenHeight = 480;
		depth = 24;
		backBufferFormat = D3DFMT_X8R8G8B8;
		break;

	case GAME_SCREEN_RESOLUTION_800_600_24:
		screenWidth = 800;
		screenHeight = 600;
		depth = 24;
		backBufferFormat = D3DFMT_X8R8G8B8;
		break;

	case GAME_SCREEN_RESOLUTION_1024_768_24:
		screenWidth = 1024;
		screenHeight = 768;
		depth = 24;
		backBufferFormat = D3DFMT_X8R8G8B8;
		break;

	default:
		break;
	}
}


WindowResolution::~WindowResolution() {}

int WindowResolution::getScreenWidth()
{
	return screenWidth;
}

int WindowResolution::getScreenHeight()
{
	return screenHeight;
}

int WindowResolution::getDepth()
{
	return depth;
}

D3DFORMAT WindowResolution::getBackBufferFormat()
{
	return backBufferFormat;
}

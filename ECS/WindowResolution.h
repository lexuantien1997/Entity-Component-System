#ifndef WINDOWRESOLUTION_H_
#define WINDOWRESOLUTION_H_

#include <d3d9.h>
#include "Define.h"

class WindowResolution
{
private:
	D3DFORMAT	backBufferFormat;

	int			screenWidth;
	int			screenHeight;
	int			depth;
public:
	WindowResolution(int);
	~WindowResolution();

	// getter - setter
	int getScreenWidth();
	int getScreenHeight();
	int getDepth();
	D3DFORMAT getBackBufferFormat();
};

#endif

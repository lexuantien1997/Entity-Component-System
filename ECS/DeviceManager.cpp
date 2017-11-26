#include "DeviceManager.h"



DeviceManager::DeviceManager()
{
	direct3d = NULL;
	direct3ddv = NULL;
	backBuffer = NULL;
}


DeviceManager::~DeviceManager()
{
	if (direct3d != NULL)
		direct3d->Release();
	if (direct3ddv != NULL)
		direct3ddv->Release();
	if (backBuffer != NULL)
		backBuffer->Release();
}

void DeviceManager::clearScreen() { direct3ddv->ColorFill(backBuffer, NULL, D3DCOLOR_XRGB(0, 0, 0)); }

void DeviceManager::draw() { direct3ddv->Present(NULL, NULL, NULL, NULL); }

void DeviceManager::InitDirectX(WindowManager* _window)
{
	direct3d = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = _window->CheckIsFullScreen() ? FALSE : TRUE;

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;

	d3dpp.BackBufferFormat = _window->getWindowResolution()->getBackBufferFormat();
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferHeight = _window->getWindowResolution()->getScreenHeight();
	d3dpp.BackBufferWidth = _window->getWindowResolution()->getScreenWidth();

	direct3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		_window->GetHwnd(),
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&direct3ddv);

	if (direct3ddv == NULL)
		return;

	direct3ddv->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffer);

}


LPDIRECT3DDEVICE9 DeviceManager::getDevice() { return direct3ddv; }

LPDIRECT3DSURFACE9 DeviceManager::getBackBuffer() { return backBuffer; }

void DeviceManager::release()
{
	if (direct3d != NULL)
		direct3d->Release();
	if (direct3ddv != NULL)
		direct3ddv->Release();
	if (backBuffer != NULL)
		backBuffer->Release();
}

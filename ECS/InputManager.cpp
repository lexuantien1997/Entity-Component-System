#include "InputManager.h"



void InputManager::init(HWND hWnd, HINSTANCE hInstance)
{
	HRESULT hr = DirectInput8Create
		(
			hInstance,
			DIRECTINPUT_VERSION,
			IID_IDirectInput8, (VOID**)&dInput, NULL
		);

	if (hr != DI_OK) return;

	hr = dInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);

	if (hr != DI_OK) return;

	hr = keyboard->SetDataFormat(&c_dfDIKeyboard);

	hr = keyboard->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

	DIPROPDWORD dipdw;
	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = KEYBOARD_BUFFER_SIZE; // KEYBOARD_BUFFER_SIZE

	hr = keyboard->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);
	
	if (hr != DI_OK) return;

	hr = keyboard->Acquire();

	if (hr != DI_OK) return;

}

void InputManager::update(HWND hWnd)
{
	// Transfering current state into previous state
	std::copy(currentKeyStates, currentKeyStates + 256, previousKeyStates);

	// Collect all key states first
	keyboard->GetDeviceState(sizeof(currentKeyStates), currentKeyStates);

	if (isKeyDown(DIK_ESCAPE,KeyState::current))
		PostMessage(hWnd, WM_QUIT, 0, 0);

	DWORD dwElements = KEYBOARD_BUFFER_SIZE; 
	HRESULT hr = keyboard->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), keyEvents, &dwElements, 0);
}

void InputManager::release()
{
	if (keyboard != NULL)
	{
		keyboard->Unacquire();
		keyboard->Release();
	}

	if (dInput != NULL)
		dInput->Release();

}


bool InputManager::getKey(const int key)
{
	return key;
}

bool InputManager::getKeyDown(const int key)
{
	return isKeyDown(key, KeyState::current) && !isKeyDown(key, KeyState::previous);
}

bool InputManager::getKeyUp(const int key)
{
	return isKeyDown(key, KeyState::previous) && !isKeyDown(key, KeyState::current);
}

bool InputManager::isKeyDown(const int key, KeyState keyState)
{
	BYTE k = (keyState == KeyState::current) ? currentKeyStates[key] & 0x80 : previousKeyStates[key] & 0x80;
	return k != 0;
}

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
	release();
}

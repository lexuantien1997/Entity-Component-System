#ifndef GAME_H
#define GAME_H

#include <d3d9.h>
#include <dinput.h>

#include "DeviceManager.h"
#include "InputManager.h"
#include "WindowManager.h"

#include "SceneManager.h"

class Game
{
protected:

	DWORD deltatime;

	int fps;

	WindowManager* window;

public:

	virtual void init();

	void runGame();

	void release();

	void render();

	void update();

	Game(HINSTANCE, LPWSTR, int, int, int);

	~Game();
};


#endif // !GAME_H



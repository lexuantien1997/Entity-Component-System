#ifndef METROIDGAME_H_
#define METROIDGAME_H_

#include "SceneManager.h"

#include "PlayingScene.h"

#include "Game.h"

class MetroidGame:public Game
{
public:
	MetroidGame(HINSTANCE hInstance, LPWSTR name, int mode, int isFulllScreen, int fps);
	~MetroidGame();

	void init();

};


#endif // !METROIDGAME_H_



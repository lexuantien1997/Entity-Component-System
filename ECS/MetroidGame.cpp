#include "MetroidGame.h"



MetroidGame::MetroidGame(HINSTANCE hInstance, LPWSTR name, int mode, int isFulllScreen, int fps): 
	Game(hInstance,  name,  mode,  isFulllScreen,  fps)
{

}


MetroidGame::~MetroidGame()
{
}

void MetroidGame::init()
{
	Game::init();
	 SceneManager::getInstance()->addScene(new PlayingScene());
}

#ifndef PLAYINGSCENE_H_
#define PLAYINGSCENE_H_

#include "Scene.h"

#include "RenderingSystem.h"
#include "InputSystem.h"
#include "InputManager.h"
#include "MovementSystem.h"

class PlayingScene:public Scene
{
private:
	RenderingSystem renderSystem;
	InputSystem inputSystem;
	MovementSystem movementSystem;
public:
	PlayingScene();
	~PlayingScene();

	void update(float dt);

	void init();

	void render() ;

	void release(){ }

	void onkeyUp(int key);

	void onkeyDown(int key);
};


#endif // !PLAYINGSCENE_H_



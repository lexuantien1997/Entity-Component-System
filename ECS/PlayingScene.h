#ifndef PLAYINGSCENE_H_
#define PLAYINGSCENE_H_

#include "Scene.h"

#include "RenderingSystem.h"
#include "InputSystem.h"
#include "InputManager.h"
#include "MovementSystem.h"
#include "AnimationSystem.h"

class PlayingScene:public Scene
{
private:
	RenderingSystem renderSystem;
	InputSystem inputSystem;
	MovementSystem movementSystem;
	AnimationSystem animationSystem;
public:
	PlayingScene();
	~PlayingScene();

	void update(float dt);

	void init();

	void render() ;

	void release(){ }
};


#endif // !PLAYINGSCENE_H_



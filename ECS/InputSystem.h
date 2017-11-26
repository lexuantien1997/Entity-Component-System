#ifndef INPUTSYSTEM_H_
#define INPUTSYSTEM_H_

#include "System.h"
#include "Base.h"
#include "PlayerControllable.h"
#include "Velocity.h"
#include "InputManager.h"

using namespace FILTER;

class InputSystem:public Base,public System<Require<PlayerControllable,Velocity>,Exclude<>>
{
public:

	void update(float dt);

	void render();

	void init();

	void loadResource();

	InputSystem();

	~InputSystem();
};
	

#endif // !INPUTSYSTEM_H_



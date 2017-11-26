#include "InputSystem.h"



void InputSystem::update(float dt)
{
	for (auto entity : getEntities())
	{
		// 2 component of the system:
		auto playerContr = entity->getComponent<PlayerControllable>("player controllable 1");
		auto velocity = entity->getComponent<Velocity>("velocity 1");

		// Get the input class
		auto input = InputManager::getInstance();

		// Check jump action is pressed or not
		bool checkJump = input->isKeyDown(playerContr->actions.jumping, KeyState::current);

		if (input->isKeyDown(playerContr->directions.right,KeyState::current))
		{
			velocity->getVelocity(VelocityType::normal).x = playerContr->velocity;
		}
		else if (input->isKeyDown(playerContr->directions.left, KeyState::current))
		{
			velocity->getVelocity(VelocityType::normal).x = -playerContr->velocity;
		}

		// if (checkJump)
			// velocity->getVelocity(VelocityType::normal).y = playerContr->gravity;
	}
}

void InputSystem::render()
{

}

void InputSystem::init()
{

}

void InputSystem::loadResource()
{

}

InputSystem::InputSystem()
{

}


InputSystem::~InputSystem()
{
}

#include "InputSystem.h"
#include "EventManager.h"


void InputSystem::update(float dt)
{
	for (auto entity : getEntities())
	{
		// 2 component of the system:
		auto playerContr = entity->getComponent<PlayerControllable>("player controllable 1");
		auto velocity = entity->getComponent<Velocity>("velocity 1");

		velocity->initVelocity(Vector2f(0, 0), Vector2f(0, 0));

		// Get the input class
		auto input = InputManager::getInstance();


		if (input->isKeyDown(playerContr->directions.right, KeyState::current))
		{
			velocity->getVelocity(VelocityType::normal).x = velocity->speed;
		}		
		else if (input->isKeyDown(playerContr->directions.left, KeyState::current))
		{
			velocity->getVelocity(VelocityType::normal).x = -velocity->speed;
			EventManager::getInstance()->sendEvent(EventId::MOVE_LEFT,"Normal");
		}


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

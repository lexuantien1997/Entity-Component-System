#include "MovementSystem.h"
#include "Transform.h"
#include "Velocity.h"
#include "InputManager.h"

void MovementSystem::update(float dt)
{
	for (auto entity : getEntities())
	{
		auto velocity = entity->getComponent<Velocity>("velocity 1");
		auto transform = entity->getComponent<Transform>("transform 1");

		if (InputManager::getInstance()->isKeyDown(0x2D, KeyState::current))
		{
			velocity->getVelocity(VelocityType::normal) = Vector2f(0.f, -50.f)*0.01f + velocity->getVelocity(VelocityType::normal);
		}
		else
			velocity->getVelocity(VelocityType::normal)= velocity->getVelocity(VelocityType::normal)*0.01f;
		
		
		velocity->getVelocity(VelocityType::plus)*=0.01f;

		transform->moving(velocity->getVelocity(VelocityType::normal));
		transform->moving(velocity->getVelocity(VelocityType::plus));

	}
}

void MovementSystem::render()
{

}

void MovementSystem::init()
{

}

void MovementSystem::loadResource()
{

}

MovementSystem::MovementSystem()
{

}


MovementSystem::~MovementSystem()
{
}

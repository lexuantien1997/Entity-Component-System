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

		transform->moving(velocity->getVelocity(VelocityType::normal)*0.01f);
		transform->moving(velocity->getVelocity(VelocityType::plus)*0.01f);
	
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

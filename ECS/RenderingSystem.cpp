#include "RenderingSystem.h"
#include "Sprite.h"
#include "Transform.h"

void RenderingSystem::update(float dt)
{

}

void RenderingSystem::render()
{

	for (auto entity :getEntities())
	{
		auto sprite = entity->getComponent<Sprite>("sprite 1");
		
		auto transform = entity->getComponent<Transform>("transform 1");
		
		auto batch = SpriteManager::getInstance();
		
		batch->draw(sprite, transform, false, false);

	}

}

void RenderingSystem::init()
{

}

void RenderingSystem::loadResource()
{

}

RenderingSystem::RenderingSystem()
{

}


RenderingSystem::~RenderingSystem()
{

}

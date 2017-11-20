#include "System.h"

void ISystem::addEntity(Entity* entity)
{
	v_entities.push_back(entity);
}

void ISystem::removeEntity(Entity * entity)
{
	v_entities.erase(std::remove(v_entities.begin(), v_entities.end(), entity), v_entities.end());
}

#include "Entity.h"

#include "GameWorld.h"




Entity::Entity(string _name,GameWorld* s)
{
	name = _name;
	gameWorld = s;
	id = s->getId();
	s->increaseid();
	alive = true;
	//systems.resize(maxComponents);
}

Entity::~Entity()
{
}

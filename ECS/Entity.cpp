#include "Entity.h"
#include "Scene.h"




Entity::Entity(string _name,Scene* s)
{
	name = _name;
	scene = s;
	id = s->getId();
	s->increaseid();
	alive = true;
	//systems.resize(maxComponents);
}

Entity::~Entity()
{
}

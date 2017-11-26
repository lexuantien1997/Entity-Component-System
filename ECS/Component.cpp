#include "Component.h"



Component::Component(string _name):name(_name)
{

}


void Component::release()
{

	// step: Entity removes component
	entity = NULL;
	// delete class
	delete this;
}

Component::~Component()
{
	
}

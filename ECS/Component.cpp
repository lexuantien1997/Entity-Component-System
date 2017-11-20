#include "Component.h"



Component::Component(string _name):name(_name)
{

}


void Component::release()
{
	// step: call onRelease in sub class
	onRelease();
	// step: Entity removes component
	entity = NULL;
	// delete class
	delete this;
}

void Component::init()
{
}

void Component::update(float dt)
{
}

void Component::draw()
{
}

Component::~Component()
{
	release();
}

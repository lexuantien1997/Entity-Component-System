#include "PlayerControllable.h"



PlayerControllable::PlayerControllable(string name):
	Component(name),
	state(SamusState::no_state)
{

}


PlayerControllable::~PlayerControllable()
{
}

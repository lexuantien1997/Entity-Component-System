#include "PlayerControllable.h"



PlayerControllable::PlayerControllable(string name):
	Component(name),
	state(SamusState::NO_STATE)
{

}


PlayerControllable::~PlayerControllable()
{
}

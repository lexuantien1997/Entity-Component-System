#ifndef COMPONENT
#define COMPONENT
#include <iostream>
using namespace std;

class Entity;

// ================================================== Brief ==================================================
//
// - Component is used to describe data for an Entity
// - All components are inherited from the Component class
// - NOTE: Component only storage data (attributes)
// Example about compnent:
//		+ Transform Component : specific position of object in game world
//		+ Physic Component : velocity, movement,... 
//		+ Collsion Component : collider
//		+ Animation Component : sprite, image, gif,...
//		+ Health Component : blood, mana,...
//		+ AI Component : the AI brain
//		+ Camera Component: view, window, ...
//
// ===========================================================================================================
class Component
{
private:

	// Name of component -> unique name
	// Example: We have an Entity is Samus
	// Samus has velocity, movement, acceleration and they all have the same type: Transform Component
	// => We must have something like the ID to specify it in the game world => That's why `Name` was generated 
	string name; 
	
	// Now component is active or not (don't care now)
	bool active;

	// The parent `entity` that the component belongs to
	Entity* entity; 

public:

	// Constructor pass unique name
	Component(string name);

	string getName() { return name; } // get name

	bool isActive() { return active; } // get current state

	void setActive(bool c) { active = c; } // make it active or deactive

	void setEntity(Entity *entity) { this->entity = entity; } // pass the parent entity

	void release(); // don't care

	~Component();

	virtual void init(){ }

protected:
	virtual void onRelease() { } // don't care 

};

#endif // !COMPONENT




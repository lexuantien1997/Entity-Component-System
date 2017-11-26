#ifndef MOVEMENTSYSTEM_H_
#define MOVEMENTSYSTEM_H_

#include "Base.h"
#include "System.h"	

class Transform;
class Velocity;

using namespace FILTER;

class MovementSystem:public System<Require<Transform,Velocity>,Exclude<>>,public Base
{
public:

	void update(float dt);

	void render();

	void init();

	void loadResource();

	MovementSystem();

	~MovementSystem();
};


#endif // !MOVEMENTSYSTEM_H_


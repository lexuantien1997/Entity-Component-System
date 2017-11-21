#ifndef SCENE_H_
#define SCENE_H_
#include "Base.h"
#include "GameWorld.h"

class Scene
{

private:
	GameWorld *world;

	string name;

public:

	Scene(string _name) :name(_name), world(new GameWorld()) {  }

	~Scene() { }

	virtual void update(float dt) = 0;
	
	virtual void init() = 0;

	virtual void render() = 0;

};

#endif // !SCENE_H_



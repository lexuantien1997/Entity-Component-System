#ifndef RENDERINGSYSTEM_H_
#define RENDERINGSYSTEM_H_

#include "System.h"
#include "SpriteManager.h"
#include "Base.h"

using namespace FILTER;

class Sprite;
class Transform;


class RenderingSystem:public System<Require<Sprite,Transform>,Exclude<>>,public Base
{
public:

	void update(float dt);

	void render();

	void init();

	void loadResource();

	RenderingSystem();
	~RenderingSystem();
};

#endif // !RENDERINGSYSTEM_H_




#ifndef ANIMATIONSYSTEM_H_
#define ANIMATIONSYSTEM_H_

#include "System.h"
#include "Base.h"

#include "Sprite.h"
#include "Animation.h"

#include "EventHandler.h"

using namespace FILTER;


class AnimationSystem: public System<Require<Sprite,Animation>,Exclude<>>,
					   public Base,
	                   public EventHandler
{
private:
	float stateTime,frameDuration;
public:

	void update(float dt);

	void render();

	void init();

	void loadResource();

	AnimationSystem();

	~AnimationSystem();

	void HandleEvent(Event* pEvent);
};

#endif // !ANIMATIONSYSTEM_H_




#include "AnimationSystem.h"



void AnimationSystem::update(float dt)
{
	for (auto entity : getEntities())
	{
		auto animation = entity->getComponent<Animation>("animation 1");
	
		stateTime += dt;

		if (stateTime >= frameDuration)
		{
			//currentFrame++;
			stateTime = 0;
		}
	}
	

	
//	if (_currentFrame >= _maxFrame)
		//_currentFrame = 0;
}

void AnimationSystem::render()
{
}

void AnimationSystem::init()
{
	stateTime = 0;
	frameDuration = 0.15;
}

void AnimationSystem::loadResource()
{
}

AnimationSystem::AnimationSystem()
{
}


AnimationSystem::~AnimationSystem()
{
}

void AnimationSystem::HandleEvent(Event * pEvent,string func)
{

}

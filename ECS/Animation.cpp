#include "Animation.h"



void Animation::loadAnimation(WorldID Id)
{
	map<string, vector<EntityInfo>> Object = SpriteManager::getInstance()->getentityResource(Id);
	for (auto it = Object.begin(); it != Object.end(); ++it)
	{
		string name = it->first;

		vector<EntityInfo> info = Object[name];

		State *state = new State(info, info.size());
		
		frames.insert(pair<string, State*>(name, state));

	}

}

Animation::Animation(string name):Component(name)
{

}


Animation::~Animation()
{

}

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "Component.h"
#include <vector>
#include "State.h"
#include "SpriteManager.h"
using namespace std;

struct State
{

	vector<EntityInfo> info;

	int frameCount;

	State(vector<EntityInfo> _info, int _frameCount) :info(_info), frameCount(_frameCount){ }

	State(){}
};

class Animation:public Component
{
public:
	
	map<string, State*> frames;
	
	string currentStateName;
	State currentState;

	bool isPlaying;

	void play(string currentStateName)
	{
		this->currentStateName = currentStateName;
		isPlaying = true;
	}

	void pause()
	{
		isPlaying = false;
	}

	void loadAnimation(WorldID Id);

	Animation(string name);

	~Animation();
};


#endif // !ANIMATION_H_



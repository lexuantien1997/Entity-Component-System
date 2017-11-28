#ifndef SPRITEMANAGER_H_
#define SPRITEMANAGER_H_
#include <d3dx9.h>
#include "Singleton.h"
#include "Vector2.h"
#include "Transform.h"
#include "GameObjectId.h"
#include <map>

#include "rapidxml.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_print.hpp"
#include "rapidxml_utils.hpp"


using namespace std;
using namespace rapidxml;

class Sprite;


struct EntityInfo
{
public:
	RECT rect;
	float width;
	float height;
};

class SpriteManager:public Singleton<SpriteManager>
{
private:
	LPD3DXSPRITE spriteHandler;

	/*
	SAMUS   ---> run-right ----> RECT: 5  20 45 180 width: height: 
						   ----> RECT: 45 16 71 81

			     run-left  ----> RECT:45 16 71 81
						   ----> RECT:45 16 71 82

			     rolling   ----> RECT: 100 100 110 112

	ENEMY   ---> move-left ----> ....
	*/
	map<WorldID, map<string, vector<EntityInfo>>> entityResource;

public:

	map<string, vector<EntityInfo>> getentityResource(WorldID Id);

	LPD3DXSPRITE getSpriteHandler();
	SpriteManager();
	~SpriteManager();

	void draw(Sprite*, Transform*, bool isCenterSprite=false, bool fx = false, bool fy = false);

	void loadResource(string imageSource,WorldID Id);

	vector<EntityInfo> getEntityInfo(WorldID Id,string state);

	void begin();
	void end();
};


#endif // !SPRITEMANAGER_H_




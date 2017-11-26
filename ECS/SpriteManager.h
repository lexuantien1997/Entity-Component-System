#ifndef SPRITEMANAGER_H_
#define SPRITEMANAGER_H_
#include <d3dx9.h>
#include "Singleton.h"
#include "Vector2.h"
#include "Transform.h"

class Sprite;

class SpriteManager:public Singleton<SpriteManager>
{
private:
	LPD3DXSPRITE spriteHandler;
public:
	LPD3DXSPRITE getSpriteHandler();
	SpriteManager();
	~SpriteManager();

	void draw(Sprite*, Transform*, bool isCenterSprite=false, bool fx = false, bool fy = false);

	void begin();
	void end();
};


#endif // !SPRITEMANAGER_H_




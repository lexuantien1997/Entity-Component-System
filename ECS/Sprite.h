#ifndef SPRITE_H_
#define SPRITE_H_

#include <d3d9.h>
#include "Component.h"
#include "Texture.h"

class Sprite:public Component
{
private:
	Texture texture;
	RECT rect;

public:
	~Sprite();

	Sprite(string sourceFile,string name):Component(name)
	{
		rect.top = 0;
		rect.left = 0;
		rect.right = 385;
		rect.bottom = 38;

		 texture.loadFromFile(sourceFile.c_str());
	}

	Texture getTexture() { return texture; }

	RECT getRect() { return rect; }

};

#endif // !SPRITE_H_




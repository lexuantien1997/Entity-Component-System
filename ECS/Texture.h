#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <d3dx9.h>
#include <iostream>
#include "DeviceManager.h"
#include "SpriteManager.h"

class Texture
{
private:
	LPDIRECT3DTEXTURE9 texture;
	D3DXCOLOR transparentColor;
	D3DXIMAGE_INFO info;
public:
	Texture();

	LPDIRECT3DTEXTURE9 getTexture();

	D3DXCOLOR getColor();

	HRESULT loadFromFile(const char* source, D3DXCOLOR color= D3DCOLOR_ARGB(255, 255, 255, 255));

	void release();

	float getWidth();

	float getHeight();

	~Texture();

};


#endif // !TEXTURE_H_



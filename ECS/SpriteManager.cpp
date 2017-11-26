﻿#include "SpriteManager.h"
#include "Sprite.h"


LPD3DXSPRITE SpriteManager::getSpriteHandler()
{
	return spriteHandler;
}

SpriteManager::SpriteManager()
{
	LPDIRECT3DDEVICE9 d3ddv = DeviceManager::getInstance()->getDevice();

	D3DXCreateSprite(d3ddv, &spriteHandler);

	HRESULT res = D3DXCreateSprite(d3ddv, &spriteHandler);

}


SpriteManager::~SpriteManager()
{
}

// full parameters about drawing
void SpriteManager::draw(Sprite *ss, Transform* t,bool isCenterSprite,bool flipX,bool flipY)
{
	// set position:
	// vị trí của bức hình từ transform
	D3DXVECTOR3 position = D3DXVECTOR3(t->getPosition().x, t->getPosition().y, 0);

	// set source rect:
	// Trong bức hình chính lấy ra bao nhiêu phần
	RECT sourceRect = ss->getRect();

	// set rotation:
	// Lấy góc xoay của hình từ transform
	float rotation = t->getRotation();

	// set translation: NULL

	// set origin:
	// Lấy tâm xoay từ transform 
	Vector2f ori = t->getOrigin();
	D3DXVECTOR2 rotationCenter = D3DXVECTOR2(ori.x, ori.y);

	// set scale:
	// Lấy độ co dãn của hình, phóng to hay thu nhỏ từ transform
	Vector2f sca = t->getScale();
	D3DXVECTOR2 scaling = D3DXVECTOR2(sca.x, sca.y);
	
	// set fliping
	// kiểm tra có lật bức hình lại không
	if (flipX)
	{
		scaling = D3DXVECTOR2(scaling.x, -scaling.y);
		t->setScale(scaling.x, -scaling.y);
	}
	if (flipY)
	{
		scaling = D3DXVECTOR2(-scaling.x, scaling.y);
		t->setScale(-scaling.x, scaling.y);
	}
	

	// scaling center:
	D3DXVECTOR2 scalingScenter = D3DXVECTOR2(t->getPosition().x, t->getPosition().y);
	
	D3DXMATRIX matrix;

	D3DXMatrixTransformation2D(
		&matrix,
		&scalingScenter,
		0,
		&scaling,
		&rotationCenter,
		D3DXToRadian(rotation),
		0
	);

	D3DXMATRIX oldMatrix;
	spriteHandler->GetTransform(&oldMatrix);
	spriteHandler->SetTransform(&matrix);

	// vị trí vẽ sẽ là giữa bức hình hay không
	D3DXVECTOR3* isCenter = NULL;
	if (isCenterSprite)
		isCenter = new D3DXVECTOR3(ss->getTexture().getWidth() / 2, ss->getTexture().getHeight() / 2,0);
	
	begin(); // start drawing

	spriteHandler->Draw(
		ss->getTexture().getTexture(), // image
		&sourceRect, // rect
		isCenter,
		&position, // position
		ss->getTexture().getColor() // transparent color
	);

	spriteHandler->SetTransform(&oldMatrix);

	end(); // finish
}

void SpriteManager::begin()
{
	spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
}

void SpriteManager::end()
{
	spriteHandler->End();
}

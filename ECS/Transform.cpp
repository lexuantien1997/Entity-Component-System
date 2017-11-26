#include "Transform.h"


// ============================================================

Vector2f Transform::getPosition()
{
	return position;
}

void Transform::setPosition(Vector2f & pos)
{
	setPosition(pos.x, pos.y);
}

void Transform::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}

// ============================================================

Vector2f Transform::getScale()
{
	return scale;
}

void Transform::setScale(Vector2f & s)
{
	setScale(s.x, s.y);
}

void Transform::setScale(float x, float y)
{
	scale.x = x;
	scale.y = y;
}

void Transform::scaling(float scaX, float scaY)
{
	setScale(scale.x*scaX, scale.y*scaY);
}

void Transform::scaling(Vector2f & sca)
{
	setScale(scale.x*sca.x, scale.y*sca.y);
}

// ============================================================

Vector2f Transform::getOrigin()
{
	return origin;
}

void Transform::setOrigin(Vector2f & o)
{
	setOrigin(o.x, o.y);
}

void Transform::setOrigin(float x, float y)
{
	origin.x = x;
	origin.y = y;
}

// ============================================================

void Transform::moving(float offx, float offy)
{
	setPosition(position.x + offx, position.y + offy);
}
				   
void Transform::moving(Vector2f & offset)
{
	setPosition(position.x + offset.x, position.y + offset.y);
}

// ============================================================

Vector2f Transform::getAnchorPoint()
{
	return anchorPoint;
}

void Transform::setAnchorPoint( Vector2f &f)
{
	anchorPoint = f;
}

// ============================================================

void Transform::setRotation( float f)
{
	rotation = f;
}

float Transform::getRotation()
{
	return rotation;
}

void Transform::rotating(float angle)
{
	setRotation(rotation + angle);
}

// ============================================================

void Transform::initTransform(Vector2f position,Vector2f origin,Vector2f scale,float  rotation)
{
	this->position = position;
	this->origin = origin;
	this->rotation = rotation;
	this->scale = scale;
}









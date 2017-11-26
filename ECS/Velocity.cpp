#include "Velocity.h"


// =============================================================

void Velocity::setVelocity(Vector2f & vel, VelocityType type)
{
	setVelocity(vel.x, vel.y, type);
}

void Velocity::setVelocity(float offx,float offy, VelocityType type)
{
	if (type==VelocityType::normal)
	{
		vNormal.x = offx;
		vNormal.y = offy;
	}
	else if (type == VelocityType::plus)
	{
		vPlus.x = offx;
		vPlus.y = offy;
	}
}

void Velocity::translating(Vector2f & vel, VelocityType type)
{
	if (type == VelocityType::normal)
		setVelocity(vNormal.x + vel.x, vNormal.y + vel.y, VelocityType::normal);
	else if (type == VelocityType::plus)
		setVelocity(vPlus.x + vel.x, vPlus.y + vel.y, VelocityType::plus);
}

void Velocity::translating(float vx, float vy, VelocityType type)
{
	if (type == VelocityType::normal)
		setVelocity(vNormal.x + vx, vNormal.y + vy, VelocityType::normal);
	else if (type == VelocityType::plus)
		setVelocity(vPlus.x + vx, vPlus.y + vy, VelocityType::plus);
}

Vector2f& Velocity::getVelocity(VelocityType type)
{
	return (type == VelocityType::normal) ? vNormal : vPlus;
}

Velocity::~Velocity()
{
}

void Velocity::initVelocity(Vector2f vNormal, Vector2f vPlus)
{
	this->vNormal = vNormal;
	this->vPlus = vPlus;
}

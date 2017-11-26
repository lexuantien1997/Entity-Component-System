#ifndef VELOCITY_H_
#define VELOCITY_H_

#include "Component.h"
#include "Vector2.h"

enum VelocityType
{
	normal=0,
	plus=1
};

class Velocity:public Component
{
private:
	Vector2f vNormal;

	Vector2f vPlus;
public:

	// ============ get - set velocity ==================
	void setVelocity(Vector2f &v,VelocityType t);
	void setVelocity(float offx, float offy, VelocityType t);

	void translating(Vector2f &v, VelocityType t);
	void translating(float vx,float vy, VelocityType t);

	Vector2f& getVelocity(VelocityType t);

	~Velocity();

	Velocity(string name):Component(name){ }

	void initVelocity(Vector2f vNormal,Vector2f	vPlus);
};

#endif // !VELOCITY_H_




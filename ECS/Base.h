#ifndef BASEOBJECT_H_
#define BASEOBJECT_H_


/*
*@brief  This class just an interface, hold some virtual function
*/
class Base
{
public:
	virtual void update(float dt) = 0;

	virtual void render() = 0;

	virtual void init() = 0;

	virtual void loadResource() = 0;
};

#endif // BASEOBJECT_H

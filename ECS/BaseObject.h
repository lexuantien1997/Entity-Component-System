#ifndef BASEOBJECT_H_
#define BASEOBJECT_H_

class BaseObject
{
public:
	virtual void update(float dt) = 0;

	virtual void render() = 0;

	virtual void init() = 0;

	virtual void loadResource() = 0;
};

#endif // BASEOBJECT_H

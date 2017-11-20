#ifndef COMPONENT
#define COMPONENT
#include <iostream>
using namespace std;

class Entity;

/**
*@brief   Theo Entity-Component-System thì:
+ Component chỉ là nơi lưu trữ dữ liệu, không làm gì hơn nữa
+ System là nơi thực hiện các nhiệm vụ logic của game như init, update cho các entity
+ 1 Entity chứa nhiều component=> là nơi thực hiện nhiệm vụ init , update các component
+ Scene (bối cảnh) là nơi chứa các Entity và System cần thiết cho 1 cảnh trong game
+ Scene Manager là nơi quản lý các scene, vì 1 game sẽ só nhiều cảnh như cảnh đánh boss, cảnh kết thúc game, ... => Đây là nơi quản lý, update, init cho các scene
**/
class Component
{
private:
	string name; // name of component -> unique name
	bool active; // active or deactive
	Entity* entity; // the parent entity that the component belongs to

public:
	Component(string name);

	string getName() { return name; }

	bool isActive() { return active; }

	void setActive(bool c) { active = c; }

	void setEntity(Entity *entity) { this->entity = entity; }

	void release();

	void init();

	void update(float dt);

	void draw();

	~Component();

protected:
	virtual void onRelease() { }

	virtual void onInit(){ }

	virtual void onUpdate(float dt){ }

	virtual void onDraw(){ }
};

#endif // !COMPONENT




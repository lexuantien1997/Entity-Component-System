#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "Vector2.h"
#include "Component.h"

/*
* The Transform class in Vector2
*/
class Transform:public Component
{
private:

	Vector2f position; // vị trí của bức hình

	// độ phóng đại của bức hình, mặc định là (1,1)
	// giá trị âm sẽ lật bức hình lại
	Vector2f scale; 

	// góc xoay từ 0-360
	float rotation; 

	Vector2f origin; // tâm xoay, co dãn

	// điểm neo, dùng để có định 1 vật ở vị trí nào đó như: 
	// cố định score, mana, máu ở góc trên màn hình (chưa làm)
	Vector2f anchorPoint; 
	
public:
	~Transform() {}

	Transform(string name) :Component(name) { }

	// ============= position + move (translate) Position ===============
	void moving(float offx, float offy);
	void moving(Vector2f& offset);
	Vector2f getPosition();
	void setPosition(Vector2f &v);
	void setPosition(float x,float y);

	// ============= set rotation ===============
	void setRotation(float angle);
	float getRotation();
	void rotating(float angle);

	// ============= set scale + scaling ===============
	Vector2f getScale();
	void setScale(Vector2f &s);
	void setScale(float x, float y);
	void scaling(float scaX, float scaY);
	void scaling(Vector2f &sca);

	// ============= set origin ===============
	Vector2f getOrigin();
	void setOrigin(Vector2f &o);
	void setOrigin(float x, float y);

	
	// ============= AnchorPoint ===============

	void setAnchorPoint( Vector2f& );
	Vector2f getAnchorPoint();

	// =============== init all data =======================================================
	
	/**
	* + Position : the position of entity
	* + Origin : origin of scale, position
	* + Scale : zoom (-) or (+)
	* + Rotation : the angle
	**/
	void initTransform(Vector2f position, Vector2f origin, Vector2f scale, float  rotation);

};



#endif // !TRANSFORM


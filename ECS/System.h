#ifndef SYSTEM_H_
#define SYSTEM_H_
#include "SystemStoreID.h"
#include <vector>
#include "Entity.h"


class Scene;

/*
* Why we must use class `ISystem` ?
* This is just a trick. Because `System` has a template in front of 
* => You can't use it to count id or use std::is_base_of
*/
class ISystem
{
private:

	FILTER::Filter filter; // each system will have an array about require and exclude component

						   // Base Scene:
	Scene* scene;
	// 1 system may be represent for more than 1 entity:
	vector<Entity*> v_entities;
public:
	// ========================================================================
	//  Getter - Setter method 
	// ========================================================================

	ISystem(FILTER::Filter _filter) : filter(_filter) { }

	void setScene(Scene* s) { scene = s; }

	Scene* getScene() { return scene; }

	FILTER::Filter getFilter() { return filter; }

	vector<Entity*> getEntities() { return v_entities; }

	// =======================================================================
	//  Data structure
	// =======================================================================


	// =======================================================================
	// Base method
	// =======================================================================

	void addEntity(Entity* entity);

	void removeEntity(Entity* entity);

	// =======================================================================
	~ISystem() { }
};

/**
*@brief   Theo Entity-Component-System thì:
	+ Component chỉ là nơi lưu trữ dữ liệu, không làm gì hơn nữa
	+ System là nơi thực hiện các nhiệm vụ logic của game như init, update cho các entity
	+ 1 Entity chứa nhiều component=> là nơi thực hiện nhiệm vụ init , update các component
	+ Scene (bối cảnh) là nơi chứa các Entity và System cần thiết cho 1 cảnh trong game
	+ Scene Manager là nơi quản lý các scene, vì 1 game sẽ só nhiều cảnh như cảnh đánh boss, cảnh kết thúc game, ... => Đây là nơi quản lý, update, init cho các scene  
**/
template <class Requires,class Exclude>
class System : public ISystem
{
public:

	System():ISystem{ MakeFilter <Requires,Exclude>() }
	{
		
	}

	~System(){ }
};


#endif // !SYSTEM_H_

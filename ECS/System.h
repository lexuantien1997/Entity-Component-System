#ifndef SYSTEM_H_
#define SYSTEM_H_
#include "SystemStoreID.h"
#include <vector>


class GameWorld;
class Entity;
/*
* Why we must use class `ISystem` ?
* This is just a trick. Because `System` has a template in front of 
* => You can't use it to count id or use std::is_base_of
*/

// =================================================== Brief ====================================================
//	- System is where defides the logic for particular parts (components) of your game
//	- Example
//
//

class ISystem
{
private:

	FILTER::Filter filter; // each system will have an array about require and exclude component

						   // Base GameWorld:
	GameWorld* gameWorld;
	// 1 system may be represent for more than 1 entity:
	std::vector<Entity*> v_entities;
public:
	// ========================================================================
	//  Getter - Setter method 
	// ========================================================================

	ISystem(FILTER::Filter _filter) : filter(_filter) { }

	void setGameWorld(GameWorld* s) { gameWorld = s; }

	GameWorld* getGameWorld() { return gameWorld; }

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
	+ GameWorld (bối cảnh) là nơi chứa các Entity và System cần thiết cho 1 cảnh trong game
	+ GameWorld Manager là nơi quản lý các GameWorld, vì 1 game sẽ só nhiều cảnh như cảnh đánh boss, cảnh kết thúc game, ... => Đây là nơi quản lý, update, init cho các GameWorld  
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

#ifndef ENTITY_H
#define ENTITY_H
#include <vector>
#include <algorithm>
#include <map>
#include "BaseID.h"
#include <array>
#include <cassert>


class GameWorld;
class Component;


// ============================================================================
// Define some thing
// ============================================================================

// max components type Entity can have -> can resize if it not enough
// 2^n (n>=5)
// std::size_t means BaseID can be a big number or small number
constexpr std::size_t maxComponents{ 64 };

// See the picture `ComponentArray`
// Array of Component type, Each Component type has many `Component` that is defined by a `String`
using ComponentArray = array<map<string, Component*>, maxComponents>;

// Set component Array has element or not
// std::bitset is an array of Boolean that have 2 value 0|1 (false|true)
using ComponentBitset = bitset<maxComponents>;

// ============================================================================
// End define
// ============================================================================


// ================================================= Brief ======================================================
//
// - Entity is a object that resembles something inside your game
// - Example:
//		+ Character: rockman, samus, naruto, songoku,...
//		+ NPCs: enemy, army-ship,...
//		+ Weapons: bullet, gun, sword, archery,...
//		+ Map, bike, ....
// - NOTE: Entity constain 1 or many Component(s)
//		+ Character: velocity, movement, sprite, camera
// - Entity still storage the location of `System`
//
// ==============================================================================================================

class Entity
{
private:
	
	// ============================================================================
	//  Basic variable Entity need
	// ============================================================================

	// Name of entity -> unique name
	// Just like `Component`: we can have more Entity with same type such as 100 Enemy, 2 Player, ...
	string name; 

	// The unique id for the entity (use that)
	long id; 

	GameWorld* gameWorld;

	bool alive; // Entity active or not
	bool init; // Can component init data ? 

	map<string, Component*> components; // Entity have many components like sprite, animation, camera, ... 
	
	// an `Array` hold specific `Component Type`. Each `Array element` has many `Conponent Type` with a a `Key - Value`
	ComponentArray componentArray; 
	ComponentBitset componentBitSet;

public:
	Entity(string name,GameWorld* s);

	string getName() { return name; }
	bool isAlive() { return alive; }
	long getId() { return id; }
	void active() { alive = true; }
	void deActive() { alive = false; }
	void setGameWorld(GameWorld* s) { gameWorld = s; }
	ComponentBitset getComponentBitset() { return componentBitSet; }

	/**
	*@brief     Add component into entity
	*@param     Args: parameter of component
	*@typename  T: component
	*@return	T*: may be we can use the component to do sth
	*/
	template <typename T, typename ... Args>
	T* addComponent(Args&&...arg);

	/**
	*@brief   Check entity has component with specific `name` or not
	*@param   componentName: name of Component
	*@return  True: found | False: not found
	*/
	template <typename T>
	bool hasComponent(string componentName);

	/**
	*@brief   Check entity has component type or not
	*@return  True: found | False: not found
	*/
	template <typename T>
	bool hasComponent();

	/**
	*@brief   Get component with specific name and component type
	* Should use when we have multi component with same type in entity
	*@return  T*: found | NULL: not found
	*/
	template<typename T>
	T* getComponent(string name);

	/**
	*@brief   Get all component type 
	* Should use when you know this component is unique
	*@return  map<string,T*>: all data in specific component type  | NULL: not found
	*/
	template<typename T>
	map<string,T*> getComponentType();

	/**
	*@brief   remove 1 component tin component type
	*@return  True: success | false: not success
	*/
	template<typename T>
	bool removeComponent(string name);

	/**
	*@brief   remove 1 component type
	*@return  True: success | false: not success
	*/
	template<typename T>
	bool removeComponentType();

	void clear(); // clear all component, lười làm

	~Entity();

	virtual void initialize() = 0;

	// ============================================================================
	// Just Advance variable
	// ============================================================================
	vector<bool> systems;
};


template<typename T, typename ...Args>
inline T* Entity::addComponent(Args && ...arg)
{
	// Check `T` is `Component` or not 
	 static_assert(std::is_base_of<Component, T>(), "T is not a component");

	//T* component(new T(std::forward<Args>(arg)...));
	auto component = new T{ std::forward<Args>(arg)... }; // add all  args into constructor


	// Get unique name of component
	string componentName = component->getName();

	// Check type and name exist in entity or not:
	assert(!hasComponent<T>(componentName) && "existed in this component type");
	/*if (hasComponent<T>(componentName))
	{
		throw std::invalid_argument(componentName + "existed in this component type");
		return NULL;
	}*/

	// make component active
	component->setActive(true);

	// Pass the entity into component
	component->setEntity(this);

	// add into map
	int index = ID::ClassID<Component>::getBaseTypeID<T>(); //ID::getComponentTypeID<T>(); // Get position of component type
	
	// want to insert into map, we must use std::make_pair
	componentArray[index].insert(std::pair<string, Component*>(componentName, component)); // insert

	componentBitSet[index] = true; // mean this position has component(s) ?

	// call `init` method of component
	// component->init();

	return component; // may be we can use component
}
template<typename T>
inline bool Entity::hasComponent(string componentName)
{
	// Check component type esist or not 
	//int index = ID::getComponentTypeID<T>();

	int index = ID::ClassID<Component>::getBaseTypeID<T>(); // Check component type esist or not 


	bool check=componentBitSet[index];
	// may be not a good way to find map
	if (check) // if Component type exists
		return componentArray[index].find(componentName) != componentArray[index].end() ? true : false;	
	return false;
}

template<typename T>
inline bool Entity::hasComponent()
{
	// return componentBitSet[ID::getComponentTypeID<T>()];
	return componentBitSet[ID::ClassID<Component>::getBaseTypeID<T>()];
}
template<typename T>
inline T * Entity::getComponent(string name)
{	
	// Check type and name exist in entity or not:
	assert(hasComponent<T>(name) && "not exists in this component type");
	/*if (!hasComponent<T>(name))
	{
		throw std::invalid_argument(name + "not exists in this component type");
		return NULL;
	}*/

	// int index = ID::getComponentTypeID<T>(); // Get position of component type
	int index = ID::ClassID<Component>::getBaseTypeID<T>();


	// ép kiểu
	return dynamic_cast<T*>(componentArray[index].at(name));
}

template<typename T>
inline bool Entity::removeComponent(string name)
{
	// Check type and name exist in entity or not:
	assert(hasComponent<T>(name) && "not exists in this component type");
	/*if (!hasComponent<T>(name))
	{
		throw std::invalid_argument(name + "not exists in this component type");
		return false;
	}*/

	// int index = ID::getComponentTypeID<T>(); // Get position of component type

	int index = ID::ClassID<Component>::getBaseTypeID<T>(); // Get position of component type

	// dynamic_cast<T*>(componentArray[index].at(name))->release(); // release component

	return componentArray[index].erase(name);
}

template<typename T>
inline bool Entity::removeComponentType()
{
	// Check type and name exist in entity or not:
	assert(hasComponent<T>(name) && "not exists in this component type");

	/*if (!hasComponent<T>())
	{
		throw std::invalid_argument("not exists in this component type");
		return false;
	}*/

	// int index = ID::getComponentTypeID<T>(); // Get position of component type

	int index = ID::ClassID<Component>::getBaseTypeID<T>(); // Get position of component type

	componentArray[index].clear(); // clear all data

	componentBitSet[index] = false; // mean this position has component(s) ?

	return componentArray[index].size() == 0;
}

#endif
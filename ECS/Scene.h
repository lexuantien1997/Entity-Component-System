#ifndef SCENE_H_
#define SCENE_H_
#include <type_traits>
#include <vector>
#include "BaseID.h"
#include <map>
#include "System.h"
#include <cassert>
#include <memory>

using namespace std;
using namespace ID;


class Entity;
class ISystem;

class Scene
{
public:

	// ==========================================================================================================
	//												System method
	// ==========================================================================================================

	/**
	*@brief  Add system into the `Scene`
	* T : Type of System 
	**/
	template<class T>
	void addSystem(T& t);

	/**
	*@brief  Remove system out of the `Scene`
	* T : Type of System
	**/
	template<class T>
	void removeSystem();


	/**
	*@brief  Check system exist or not in the `Scene`
	* T : Type of System
	**/
	template<class T>
	bool hasSystem(BaseID index);


	/**
	*@brief  Remove all system in the `Scene`
	* T : Type of System
	**/
	void clearSystem();

	// ==========================================================================================================
	//												Entity method
	// ==========================================================================================================

	/**
	*@brief  Create an entity and match it into `Scene`
	*@return : Entity if use
	**/
	template<class T>
	T* createEntity(string);

	/**
	*@brief  Remove an entity out of `Scene`
	* + Step 1: Find entity want to remove
	* + Step 2: Destroy links between `System` and `Entity`
	* + Step 3: Release cache (cái này khó làm vl)
	**/
	void removeEntity(Entity* entity);


	/**
	*@brief  When kill an Entity. 
	*		 The `Entity` and it's `Component` will not be destroyed 
	*		 until `Update` method in the `Scene` is called 
	**/
	void killEntity();

	/**
	*@brief  Make Entity active or not
	**/
	void setActiveEntity(Entity* entity, bool value);

	bool isActiveEntity(Entity* entity);

	/**
	*@brief  Get specific Entity with index
	**/
	Entity* getEntity(std::size_t index);

	// ==========================================================================================================
	//												Scene method
	// ==========================================================================================================

	/**
	*@brief  Refresh game 
	* When you call this method. Scene will automatically specify where `Entity` belong to `System`
	* Call it before update to refresh game
	**/
	void refresh();

	/**
	*@brief  Init something like create entity, component, system ....
	**/
	virtual void init() = 0;

	/**
	*@brief  Load resource
	**/
	virtual void loadResource() = 0;

	/**
	*@brief  Render the game
	**/
	virtual void render() = 0;

	/**
	*@brief  Important method, update data with delta time
	**/
	virtual void update(float dt) = 0;

	/**
	*@brief  Remove all Entities and Systems 
	**/
	void clear();

	/**
	*@brief  Generate id for the Entity
	**/
	long getId() { return id; }

	void increaseid() { id++; }

	// ==========================================================================================================
	//													Constructor
	// ==========================================================================================================
	Scene(string name);
	~Scene();
protected:
	
	// maybe sence have name
	string name;

	// 1 scene has many Systems like MovementSystem, AnimationSystem, CollisionSystem, ... 
	map <BaseID,ISystem>  systems; 

	// 1 scene has many Entity like Samus, Enemy, Background, Grass, ... 
	// Use map because we have many entity which same type such as:
	// If we create 2 players Samus 1 and Samus 2 
	// It still a Samus class but we must create twice
	// Another example : more enemies in your game
	map <long, Entity*> entities; 

	long id; // The id for entity

	// =============== Add entity =====================

	void addEntity();

};


#endif // !SCENE_H_

template<class T>
inline void Scene::addSystem(T& t)
{
	// static_assert(is_base_of<ISystem, T>, "T is not inherit from ISystem");

	// ?Kiểm tra 2 lần liên tiếp:

	// Lần 1 nếu scene của nó != NULL nghĩa al2 nó có thể chưa trong cái sence nào hết
	// Chỉ là có thể thôi vì mình có thể cái scene của nó bằng hàm `setScene` thay đổi	

	// hàm assert :
	// Ví dụ muốn tất cả các chuỗi phái có chiều dài  lớn hơn 10
	// Nếu nhỏ hơn 10 in ra lỗi "SAi độ dài chuỗi"
	// assert(strlen(string) > 10, "SAi độ dài chuỗi"); 

	assert(!t.getScene() && "This system has existed");

	// Get the index of system
	BaseID index = ID::ClassID<ISystem>::getBaseTypeID<T>();

	// Lần 2 kiểm tra bằng cách tìm kiếm nó theo BaseID
	// Nếu đếm nó khác 0 nghĩa là nó đã tồn tại rồi
	// systems.count() : đếm số lần cái giá trị đó có
	assert(systems.count(index) == 0 , "This system has existed");

	// set scene
	t.setScene(this);

	// insert it into map
	systems.insert(pair<BaseID, ISystem>(index, t));
	

}

template<class T>
inline void Scene::removeSystem()
{
	// Get the index of system
	BaseID index = ID::ClassID<ISystem>::getBaseTypeID<T>();
	assert( hasSystem<T>(index) , "This system not exist in scene");

	systems.erase(index);

}

template<class T>
inline bool Scene::hasSystem(BaseID index)
{
	return systems.find(index) != systems.end();
}

template<class T>
inline T * Scene::createEntity(string name)
{
	static_assert(std::is_base_of<Entity, T>::value, "T not a Entity");

	T *e = new T(name, this); // create an entity
	entities.insert(pair<long, Entity*>(e->getId(), e)); // insert it into map

	return dynamic_cast<T*>(e); // return entity if use
}

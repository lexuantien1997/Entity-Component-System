#ifndef BASEID_H_
#define BASEID_H_



#include <iostream>
using namespace std;
#include <bitset>


/**
*@brief  create an id for each component type
*Example: + First if you add SpriteComponent into Entity  -> calculate sth => id=0
*		  + Second if you add CameraComponent into Entity -> calculate sth => id=1
*		  + Third if you add Transform into Entity 		  -> calculate sth => id=2
*		  + if continue add another Sprite Component	  -> calculate sth => id still = 0
*		  + if you add  Transform into Entity			  -> calculate sth => id still = 2
**/
namespace ID
{

	using BaseID = std::size_t;

	template<typename Base>
	class ClassID
	{
	public:

		/*
		*@brief  Increasing id for each `Base` type
		*/
		static BaseID getUniqueBaseID()
		{
			static BaseID lastID{ 0u };
			return lastID++; // count
		}


		template<typename T>
		static BaseID getBaseTypeID()
		{
			// Check if `T` is not a `Base`
			static_assert(std::is_base_of<Base, T>::value, "T is not inherit from truth Base");

			static BaseID typeID{ getUniqueBaseID() }; // call function get id
			return typeID; // return the id 
		}

	};


//	using ComponentID = std::size_t;
//
//	/*
//	*@brief  Increasing id for each component type
//	*/
//	inline ComponentID getUniqueComponentID()
//	{
//		static ComponentID lastID{ 0u }; // just create id=0 when entity meets component type for the first time
//		return lastID++; // count
//	}
//
//
//	/*
//	*@brief  Increasing id for specific component type
//	*@param  T : Component Type
//	*/
//	template<typename T>
//	inline ComponentID getComponentTypeID()
//	{
//		// Check if T is not a component
////		static_assert(std::is_base_of<Component, T>::value, "T is not a component");
//
//		static ComponentID typeID{ getUniqueComponentID() }; // call function get id
//		return typeID; // return the id 
//	}

}

#endif // !BASEID_H_
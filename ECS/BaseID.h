#ifndef BASEID_H_
#define BASEID_H_
#include <iostream>
using namespace std;
#include <bitset>


// ==================================================== Brief ===================================================
//
// - Create an id for each component/system type 
// - Example: 
//        + First if you add SpriteComponent into Entity  -> calculate sth => id=0
//		  + Second if you add CameraComponent into Entity -> calculate sth => id=1
//		  + Third if you add Transform into Entity 		  -> calculate sth => id=2
//		  + if continue add another Sprite Component	  -> calculate sth => id still = 0
//		  + if you add  Transform into Entity			  -> calculate sth => id still = 2
//
// ==============================================================================================================
namespace ID
{
	// Just define
	// std::size_t means BaseID can be a big number or small number
	using BaseID = std::size_t;

	// Base can be: `Component` or `ISystem`
	template<typename Base>
	class ClassID
	{
	public:

		/*
		*@brief  Increasing id for each `Base` type
		*/
		static BaseID getUniqueBaseID()
		{
			// If template appear first time -> initial value is 0 (0u mean unsigned) 
			static BaseID lastID{ 0u }; 

			// If template doesn't appear first time 
			// increasing the ID
			return lastID++; 
		}


		/*
		*@brief  Get the id of T
		* `T` : sub class of `Base`
		*/
		template<typename T>
		static BaseID getBaseTypeID()
		{
			// Check if `T` is not a `Base` 
			static_assert(std::is_base_of<Base, T>::value, "T is not inherit from truth Base");

			// call function get id
			static BaseID typeID{ getUniqueBaseID() }; 
		
			return typeID; // return the id 
		}

	};
}

#endif // !BASEID_H_
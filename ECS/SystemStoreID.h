#ifndef BASESYSTEMCOM_H_
#define BASESYSTEMCOM_H_

#include <iostream>
using namespace std;
#include <bitset>
#include "Component.h"
#include "BaseID.h"
#include "Entity.h"
class Component;


/**
*@brief  see here: https://github.com/miguelmartin75/anax/blob/master/include/anax/detail/Filter.hpp
*@todo   + find component system requires-> add into a biset(list)
*		 + find component system not requires-> add into a biset(list)
*/
namespace FILTER
{
	// base class for every thing down here
	template <class ... Arg>
	struct TypeList { };

	// ==================================================
	// Call later
	template <class ... Args>
	struct Require :TypeList<Args...>{ };
	template <class ... Args>
	struct Exclude :TypeList<Args...> { };
	// ==================================================

	// using bitset because we need to store component exist or not -> use true or false 
	using ComponentTypeList = std::bitset<maxComponents>; // just define, `maxComponents` can change, should be 1024 or 2^n (n>=5) 

	struct Filter
	{
		private:
		ComponentTypeList _requires; //  each array have `maxComponents` element -> each element have 2 values (0|1)
		ComponentTypeList _excludes;
	public:
		Filter(ComponentTypeList requires, ComponentTypeList excludes) :_requires(requires), _excludes(excludes) { }

		/*
		*@brief  Hàm kiểm tra Entity có những thứ mà System yêu cầu phải và không có  không ?
		*/
		bool doesPassFilter(Entity* entity)
		{
			// Kiểm tra những thứ mà `System` yêu cầu có `Entity` nó có không
			for (size_t i = 0; i < _requires.size(); i++)
			{
				// Nếu trong những thứ mà `System` bắt buộc có mà `Entity` không có thì return false luôn
				if (_requires[i] && !entity->getComponentBitset()[i])
					return false;
			}

			// Nếu như Entity có những thứ mà System cần thì tiếp tục kiểm tra những thứ
			// system yêu cầu không được có
			for (size_t i = 0; i < _excludes.size(); i++)
			{
				// Nếu có bất cứ component nào mà cả 2 đều có thì return false luôn
				if (_excludes[i] && entity->getComponentBitset()[i])
					return false;
			}

			// Thỏa hết tất cả điều kiện
			return true;
		}

	};

	/*
	*@brief   Class nào không còn (không có) parameter thì sẽ thực hiện hàm này
	*        Trả về mảng bit set để dùng
	*/
	template <class ... Args>
	static ComponentTypeList types(TypeList<Args ... > typeList)
	{
		return ComponentTypeList();
		//return std::bitset<maxComponents>();
	}


	/*
	*@brief   Class nào còn parameter thì sẽ thực hiện hàm này
	*         Dùng đệ quy để thực hiện việc cắt từng parameter ra
	*		  Mỗi lần cắt lại lấy cái id của component đó
	*/
	template <class T, class ... Args>
	static ComponentTypeList types(TypeList<T, Args ... > typeList)
	{
		static_assert(std::is_base_of<Component, T>::value, "T is not a component");

		// types(TypeList<Args ... >() : dùng đệ quy duyệt từng Args. Mỗi Arg mình lại tìm vị trí của nó trong cái ClassID
		return ComponentTypeList().set(ID::ClassID<Component>::getBaseTypeID<T>()) | types(TypeList<Args ... >());
	}

	/*
	* Gọi hàm này để tìm kiếm và add component vào bitset
	*/
	template<class RequireList, class ExcludeList>
	Filter MakeFilter()
	{
		return Filter
		{
			types(RequireList{}), types(ExcludeList{})
		};
	}
}
#endif // !BASESYSTEM_H_
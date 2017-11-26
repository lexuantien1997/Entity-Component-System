#ifndef SINGLETON_H
#define SINGLETON_H

/**
*@brief  Just a base class about Singleton pattern
**/

template<class T>
class Singleton
{
public:
	static  T* getInstance()
	{
		if (!instance)
			instance = new T();
		return instance;
	} 
private:
	static T* instance;
protected:
	Singleton(){}
	~Singleton(){ }
};

template <class T>
T* Singleton<T>::instance = nullptr;


#endif // !SINGLETON_H

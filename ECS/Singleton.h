#ifndef SINGLETON_H
#define SINGLETON_H

/**
*@brief  Just a base class about Singleton pattern
**/
template<class T>
class Singleton
{
public:
	static T* getInstance()
	{
		if (instance == nullptr)
			instance = new T();
		return instance;
	}
private:
	static constexpr T* instance = nullptr;
protected:
	~Singleton(){ }
};

#endif // !SINGLETON_H

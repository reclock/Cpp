#ifndef __SINGLETON__H
#define __SINGLETON__H
#include <stdio.h>

class Singleton{
private:
	Singleton()
	{
		printf("hello\n");
	};
	static Singleton* single;

public:
	static Singleton* GetInstance()
	{
		if(single == nullptr)
		{
			single = new Singleton();
		}
		return single;
	}
};

Singleton* Singleton::single = nullptr;


#endif
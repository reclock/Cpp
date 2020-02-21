#include "Singleton.hpp"

class Test{
private:
	Singleton *s1;
	Singleton *s2;

public:
	void td()
	{
		s1 = Singleton::GetInstance();
		s1 = Singleton::GetInstance();
	}


	void mtd()
	{

	}
};
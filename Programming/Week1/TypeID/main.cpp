#include <iostream>

class Cat
{
public:
	virtual ~Cat()
	{
	
	}
};

class Sziami : public Cat
{

};


class Dog
{

};

class Leonberger : public Dog
{

};

int main()
{
	Sziami sziamiObject;
	Cat * catPointer = &sziamiObject;
	Cat& catReference = sziamiObject;

	std::cout << "catPointer " << typeid(*catPointer).name() << std::endl;
	std::cout << "catReference " << typeid(catReference).name() << std::endl;

	Leonberger leonbergerObject;
	Dog* dogPointer = &leonbergerObject;
	Dog& dogReference = leonbergerObject;

	std::cout << "dogPointer " << typeid(*dogPointer).name() << std::endl;
	std::cout << "dogReference " << typeid(dogReference).name() << std::endl;

	int wait;
	std::cin >> wait;

	return 0;
}
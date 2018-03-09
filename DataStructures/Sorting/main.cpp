#include <iostream>

#include "LinkedList.h"


int main()
{
	LinkedList list;
	int randomNumber = 10;

	for (int i = 0; i < 10; i++)
	{
		list.SetData(randomNumber, i);
		randomNumber--;
	}

	list.DisplayData();
	std::cout << std::endl;
	std::cout << "Sorting ready!";
	std::cout << std::endl;
	system("pause");
	system("cls");


	list.InsertionSort();

	system("pause");
	

	return 0;
}
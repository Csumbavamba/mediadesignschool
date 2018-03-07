#include "SingleLinkedList.h"
#include "CNode.h"
#include <iostream>

int main()
{
	SingleLinkedList list;


	// Insert at the first place than show the first value
	list.InsertAtTheFront(1);
	list.InsertAtTheEnd(2);
	list.InsertInTheMiddle(3, 2);
	list.Display();

	system("pause");
	list.Delete(1);
	list.Display();

	int temp;
	std::cin >> temp;



	return 0;
}
#include <iostream>

#include "CNode.h"
#include "DoubleLinkedList.h"

int main()
{
	DoubleLinkedList list;


	list.InsertAtTheFront(1);
	list.InsertAtTheEnd(3);
	list.InsertInTheMiddle(2, 2);
	list.Display();

	system("pause");

	list.Search(4);

	list.Delete(1);
	list.Display();

	int wait;
	std::cin >> wait;

	return 0;
}
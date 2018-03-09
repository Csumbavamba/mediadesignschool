#include <iostream>

#include "CNode.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"

void TestHarness()
{
	// Stack tests
	std::cout << "Stack Tests" << std::endl;
	Stack stack;

	stack.Push(1);
	stack.Push(2);
	stack.Push(3);

	stack.PrintStackMembers();

	stack.Peek();

	system("pause");

	stack.Pop();
	std::cout << "Popping." << std::endl;
	stack.PrintStackMembers();

	system("pause");
	system("cls");

	

	// Queue tests
	std::cout << "Queue Tests" << std::endl;
	Queue queue;

	queue.Enqueue(1);
	queue.Enqueue(2);
	queue.Enqueue(3);

	queue.PrintQueueMembers();
	system("pause");

	queue.Peek();

	system("pause");

	queue.Dequeue();
	std::cout << "Dequeueing." << std::endl;
	queue.PrintQueueMembers();

	system("pause");
	system("cls");
	

	// Deque test
	std::cout << "Queue Tests" << std::endl;
	Deque deque;

	deque.EnqueueAtEnd(1);
	deque.EnqueueAtEnd(2);
	deque.EnqueueAtEnd(3);
	deque.EnqueueAtFront(4);

	deque.PrintQueueMembers();

	int peek = deque.PeekAtEnd();
	std::cout << "Peek at End: " << peek << std::endl;

	peek = deque.PeekAtFront();
	std::cout << "Peek at Front: " << peek << std::endl;

	system("pause");

	deque.DequeueAtEnd();
	std::cout << "Deleting at End." << std::endl;

	deque.PrintQueueMembers();

	system("pause");
	system("cls");

}

int main()
{
	TestHarness();


	return 0;
}
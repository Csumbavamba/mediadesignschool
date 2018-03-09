#include <iostream>

#include "Deque.h"



Deque::Deque()
{
	end = nullptr;
	front = nullptr;
}


Deque::~Deque()
{
}

void Deque::EnqueueAtFront(int data)
{
	CNode * currentNode = front;

	// Create node for insertion
	CNode * newNode = new CNode();
	newNode->SetData(data);

	newNode->SetPreviousNode(currentNode);

	// If this is the first item to join the queue
	if (currentNode == nullptr)
	{
		end = newNode;
	}

	newNode->SetNextNode(nullptr);
	front = newNode;
}

void Deque::EnqueueAtEnd(int data)
{
	CNode * currentNode = end;

	// Create node for insertion
	CNode * newNode = new CNode();
	newNode->SetData(data);

	// Insert node at the end of the queue
	newNode->SetNextNode(currentNode);

	// If this is the first item to join the queue
	if (currentNode == nullptr)
	{
		front = newNode;
	}

	newNode->SetPreviousNode(nullptr);
	end = newNode;
}

void Deque::DequeueAtFront()
{
	// If list has members
	if (!IsEmpty())
	{
		CNode * currentNode = front;

		front = currentNode->GetPreviousNode();
		end->SetNextNode(nullptr);

		delete currentNode;
	}
	// If there is nothing in the list
	return;
}

void Deque::DequeueAtEnd()
{
	// If list has members
	if (!IsEmpty())
	{
		CNode * currentNode = end;

		end = currentNode->GetNextNode();
		end->SetPreviousNode(nullptr);

		delete currentNode;
	}
	// If there is nothing in the list
	return;
}

int Deque::PeekAtFront()
{
	// If the list has members
	if (!IsEmpty())
	{
		return front->GetData();
	}

	return -1;
}

int Deque::PeekAtEnd()
{
	// If the list has members
	if (!IsEmpty())
	{
		return end->GetData();
	}

	return -1;
}

bool Deque::IsEmpty()
{
	if (end == nullptr && front == nullptr)
	{
		std::cout << "The queue is empty" << std::endl;
		return true;
	}
	return false;
}

void Deque::PrintQueueMembers()
{
	CNode * currentNode = front;
	int memberCounter = 1;

	// iterate through the list members and write them on the screen
	while (currentNode != nullptr)
	{
		std::cout << memberCounter << ". in queue: " << currentNode->GetData() << std::endl;

		currentNode = currentNode->GetPreviousNode();
		memberCounter++;
	}
}

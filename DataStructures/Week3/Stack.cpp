#include <iostream>

#include "Stack.h"



Stack::Stack()
{
	root = nullptr;
}


Stack::~Stack()
{
}

void Stack::Push(int data)
{
	CNode * currentNode = root;

	// Create node for insertion
	CNode * newNode = new CNode();
	newNode->SetData(data);

	// Insert node before the root
	newNode->SetNextNode(currentNode);
	root = newNode;
}

void Stack::Pop()
{
	if (!IsEmpty())
	{
		CNode * currentNode = root;

		// Remove the first node
		root = currentNode->GetNextNode();
		delete currentNode;
	}
	return;
}

int Stack::Peek()
{
	if (!IsEmpty())
	{
		// Get the data from root
		std::cout << "The data on the top of the stack: " << root->GetData() << std::endl;

		return root->GetData();
	}
	return -1;
}

bool Stack::IsEmpty()
{
	if (root == nullptr)
	{
		std::cout << "The stack is empty" << std::endl;
		return true;
	}
	return false;
}



void Stack::PrintStackMembers()
{
	CNode * currentNode = root;
	int memberCounter = 1;

	// iterate through the list members and write them on the screen
	while (currentNode != nullptr)
	{
		std::cout << memberCounter << ". stack member value: " << currentNode->GetData() << std::endl;
		currentNode = currentNode->GetNextNode();
		memberCounter++;
	}
}
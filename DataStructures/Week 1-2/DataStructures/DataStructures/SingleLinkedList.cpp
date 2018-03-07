#include "SingleLinkedList.h"

#include <iostream>



SingleLinkedList::SingleLinkedList()
{
	root = nullptr;
}

SingleLinkedList::~SingleLinkedList()
{
}


void SingleLinkedList::InsertAtTheFront(int value)
{
	CNode * tempNode = root;

	CNode * newNode = new CNode();
	newNode->SetData(value);
	newNode->SetNextNode(tempNode);
	root = newNode;

}

/// Position starts from ONE
void SingleLinkedList::InsertInTheMiddle(int value, int position)
{
	// if insertion happens at the first position
	if (position == 1)
	{
		InsertAtTheFront(value);
		return;
	}
	else
	{
		CNode * tempNode = root;
		CNode * newNode = new CNode();
		CNode * previousNode = root;
		newNode->SetData(value);

		int oneBeforeTargetNode = position - 1;
		int counter = 1;

		while (counter != position)
		{
			tempNode = tempNode->GetNextNode();

			// If the insertion happens at the end
			if (tempNode->GetNextNode() == nullptr)
			{
				InsertAtTheEnd(value);
				return;
			}

			// Move the "previousNode" with one loop delay
			if (counter > 1)
			{
				previousNode = previousNode->GetNextNode();
			}

			if (counter == oneBeforeTargetNode)
			{
				previousNode->SetNextNode(newNode);
			}

			counter++;
		}

		newNode->SetNextNode(tempNode);
	}
}

void SingleLinkedList::InsertAtTheEnd(int value)
{
	CNode * tempNode = root;

	while (tempNode->GetNextNode() != nullptr)
	{
		tempNode = tempNode->GetNextNode();
	}

	CNode * newNode = new CNode();
	newNode->SetData(value);
	newNode->SetNextNode(nullptr);

	tempNode->SetNextNode(newNode);
	

}

void SingleLinkedList::Delete(int value)
{
	CNode * tempNode = root;
	CNode * nextNode = nullptr;
	CNode * previousNode = nullptr;

	if (Search(value)) // if the value exists
	{
		while (tempNode != nullptr)
		{
			// if it`s the first we delete
			if (root->GetData() == value)
			{
				root = tempNode->GetNextNode();
				delete tempNode;
				return;
			}

			// if it`s the previous before the value
			if (tempNode->GetNextNode()->GetData() == value)
			{
				previousNode = tempNode;
			}
			else if (tempNode->GetData() == value)
			{
				nextNode = tempNode->GetNextNode();
				previousNode->SetNextNode(nextNode);
				delete tempNode;
				return;
			}

			tempNode = tempNode->GetNextNode();
		}
	}
}

bool SingleLinkedList::Search(int value)
{
	CNode * tempNode = root;

	while (tempNode->GetNextNode() != nullptr)
	{
		if (tempNode->GetData() == value)
		{
			return true;
		}
		tempNode = tempNode->GetNextNode();
	}

	return false;
}

// loop through the elements of the list
void SingleLinkedList::Display()
{
	CNode * tempNode = root;
	int counter = 1;
	while (tempNode != nullptr)
	{
		std::cout << counter << ". list member value: " << tempNode->GetData() << std::endl;
		tempNode = tempNode->GetNextNode();
		counter++;
	}
}



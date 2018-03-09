#include <iostream>
#include <windows.h>

#include "LinkedList.h"




LinkedList::LinkedList()
{
	// Set every element to 0
	for (int i = 0; i < 10; i++)
	{
		SetData(0, i);
	}
}

LinkedList::~LinkedList()
{
}

int LinkedList::GetData(int position)
{
	return list[position];
}

void LinkedList::SetData(int data, int position)
{
	list[position] = data;
}


void LinkedList::SwapData(int position1, int position2)
{
	int temp = list[position1];
	list[position1] = list[position2];
	list[position2] = temp;

	return;

}

bool LinkedList::IsListAscending()
{
	for (int i = 0; i < 9; i++)
	{
		// if the list is ascending
		if (list[i] < list[i + 1])
		{
			return false;
		}
	}
	return true;
}



void LinkedList::BubbleSort()
{
	while (!IsListAscending())
	{	
		// iterate through the list
		for (int element = 0; element < 9; element++)
		{
			// if the one on the right is smaller - swap them
			if (list[element] < list[element + 1])
			{
				SwapData(element, element + 1);
				system("cls");
				DisplayData();
			}
		}
	}
}

void LinkedList::SelectionSort()
{
	int unsortedData = 10; // TODO, get list length instead of using magic number
	int currentLargest = 0;


	while (!IsListAscending())
	{

		// Find the largest element
		for (int listElement = 1; listElement < unsortedData; listElement++)
		{
			// if left side is smaller (right is larger)
			if ((list[currentLargest] < list[listElement]))
			{
				// set right side to be the largest
				currentLargest = listElement;
			}	
		}

		// Move largest data, to the end of the list
		SwapData(currentLargest, unsortedData - 1);

		unsortedData--;
		
		
		system("cls"); // TODO, Remove after testing
		DisplayData(); // TODO, Remove after testing
	}
}

/// SELECTION SORT VERSION 2
/*
void LinkedList::SelectionSort2()
{
	int unsortedData = 10; // TODO, get list length instead of using magic number
	int currentLargest = 0;

	bool sorted;

	do
	{
		sorted = true;
		// Find the largest element
		for (int i = 1; i < unsortedData; i++)
		{
			if (list[currentLargest] < list[i])
			{
				currentLargest = i;
			}
		}

		if (currentLargest < unsortedData - 1)
		{
			// swap
			int temp = list[unsortedData - 1];
			list[unsortedData - 1] = list[currentLargest];
			list[currentLargest] = temp;
			unsortedData--;
			sorted = false;
		}

		system("cls"); // TODO, Remove after testing
		DisplayData(); // TODO, Remove after testing

	} while (!sorted);
}

*/

void LinkedList::InsertionSort()
{
	bool isElementInserted;
	int inspectedElement;
	int lastSortedElement;
	int elementsSorted = 0;

	while (!IsListAscending())
	{
		isElementInserted = false;

		inspectedElement = elementsSorted + 1;
		lastSortedElement = elementsSorted;

		// until the inspected element is inserted at the right position
		while (!isElementInserted)
		{
			// If the element is being inserted at the first position 
			// OR the element has been sorted
			if (inspectedElement == 0 && list[inspectedElement] > list[lastSortedElement])
			{
				isElementInserted = true;
				elementsSorted++;
				system("cls"); // TODO, Remove after testing
				DisplayData(); // TODO, Remove after testing
			}

			// If the inspected element is larger than the last sorted
			else
			{
				// move the inspected element to the left
				SwapData(inspectedElement, lastSortedElement);
				inspectedElement--;
				lastSortedElement--;
			}
		}
		
	}
}


void LinkedList::DisplayData()
{
	// print out the elements of the array
	for (int i = 0; i < 10; i++)
	{
		std::cout << list[i] << " ";
	}
	std::cout << std::endl;
	Sleep(200);

}

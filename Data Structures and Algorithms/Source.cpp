#include "Sorting Algorithms\InsertionSort.h"
#include "Search Algorithms\BinarySearch.h"
#include "Data Structures\SinglyLinkedList.h"
#include "Data Structures\DoublyLinkedList.h"
#include "Data Structures\Stack.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
	// Insertion Sort

	// Test with int
	std::vector<int> testVectorInt;

	testVectorInt.push_back(1);
	testVectorInt.push_back(22);
	testVectorInt.push_back(43);
	testVectorInt.push_back(17);
	testVectorInt.push_back(0);
	testVectorInt.push_back(19);

	testVectorInt = insertionSort(testVectorInt);

	// Test with double
	std::vector<double> testVectorDouble;

	testVectorDouble.push_back(1.001);
	testVectorDouble.push_back(22.22);
	testVectorDouble.push_back(43.123);
	testVectorDouble.push_back(17.532);
	testVectorDouble.push_back(0.0);
	testVectorDouble.push_back(19.12);

	testVectorDouble = insertionSort(testVectorDouble);

	// Binary Search

	// Test with int
	std::vector<int> testBinarySearchInt;

	testBinarySearchInt.push_back(1);
	testBinarySearchInt.push_back(3);
	testBinarySearchInt.push_back(5);
	testBinarySearchInt.push_back(7);
	testBinarySearchInt.push_back(9);
	testBinarySearchInt.push_back(11);
	testBinarySearchInt.push_back(13);

	int needleInt = 9;

	int searchResultInt = 0;

	searchResultInt = binarySearch(needleInt, testBinarySearchInt);

	if (searchResultInt == -1)
	{
		std::cout << "Didn't find it" << std::endl;
	}
	else
	{
		std::cout << "Found it at index " << searchResultInt << " (" << testBinarySearchInt[searchResultInt] << ")" << std::endl;
	}

	// Test with string
	std::vector<std::string> testBinarySearchString;

	// Have to add a leading 0 to make sure the ordering is as expected
	testBinarySearchString.push_back("test01");
	testBinarySearchString.push_back("test03");
	testBinarySearchString.push_back("test05");
	testBinarySearchString.push_back("test07");
	testBinarySearchString.push_back("test09");
	testBinarySearchString.push_back("test11");
	testBinarySearchString.push_back("test13");

	std::string needleString = "test09";

	int searchResultString = 0;

	searchResultString = binarySearch(needleString, testBinarySearchString);

	if (searchResultString == -1)
	{
		std::cout << "Didn't find it" << std::endl;
	}
	else
	{
		std::cout << "Found it at index " << searchResultString << " (" << testBinarySearchString[searchResultString] << ")" << std::endl;
	}

	// Test singly linked list
	SinglyLinkedList::SinglyLinkedList singlyLinkedList;

	singlyLinkedList.push(1);

	// See if an item is in the linked list
	int searchResultSingle = singlyLinkedList.find(1);

	if (searchResultSingle == -1)
	{
		std::cout << "Not found" << std::endl;
	}
	else
	{
		std::cout << "Found at position " << searchResultSingle << std::endl;
	}

	try
	{
		// Remove a node
		singlyLinkedList.remove(0);
	}
	catch (std::out_of_range exception)
	{
		std::cout << exception.what() << std::endl;
	}

	singlyLinkedList.push(1);
	singlyLinkedList.push(2);
	singlyLinkedList.push(3);

	// Test doubly linked list
	DoublyLinkedList::DoublyLinkedList doublyLinkedList;

	doublyLinkedList.push(1);
	doublyLinkedList.push(2);
	doublyLinkedList.push(3);

	// See if an item is in the linked list
	int searchResultDouble = doublyLinkedList.find(1);

	if (searchResultDouble == -1)
	{
		std::cout << "Not found" << std::endl;
	}
	else
	{
		std::cout << "Found at position " << searchResultDouble << std::endl;
	}

	try
	{
		// Remove a node
		doublyLinkedList.remove(0);
	}
	catch (std::out_of_range exception)
	{
		std::cout << exception.what() << std::endl;
	}

	doublyLinkedList.push(1);
	doublyLinkedList.push(2);
	doublyLinkedList.push(3);

	// Test the stack
	Stack::Stack stack;

	stack.push(5);
	stack.push(3);
	std::cout << stack.pop() << std::endl;
	stack.push(7);
	std::cout << stack.pop() << std::endl;
	std::cout << stack.top() << std::endl;
	std::cout << stack.pop() << std::endl;
	// Would error, stack is empty
	// std::cout << stack.pop() << std::endl;
	// Would error, stack is empty
	// std::cout << stack.top() << std::endl;
	std::cout << stack.empty() << std::endl;
	stack.push(9);
	stack.push(7);
	stack.push(3);
	stack.push(5);
	std::cout << stack.size() << std::endl;
	std::cout << stack.pop() << std::endl;
	stack.push(8);
	std::cout << stack.pop() << std::endl;
	std::cout << stack.top() << std::endl;

	return 0;
}
#include "Sorting Algorithms\InsertionSort.h"
#include "Search Algorithms\BinarySearch.h"
#include "Data Structures\SinglyLinkedList.h"
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

	SinglyLinkedList singlyLinkedList;

	singlyLinkedList.push(1);

	// See if an item is in the linked list
	int searchResult = singlyLinkedList.find(1);

	if (searchResult == -1)
	{
		std::cout << "Not found" << std::endl;
	}
	else
	{
		std::cout << "Found at position " << searchResult << std::endl;
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

	return 0;
}
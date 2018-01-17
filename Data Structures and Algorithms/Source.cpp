#include "InsertionSort.h"
#include "BinarySearch.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
	// Test insertion sort with int/double
	InsertionSort<int> insertionSortInt;

	std::vector<int> testVectorInt;

	testVectorInt.push_back(1);
	testVectorInt.push_back(22);
	testVectorInt.push_back(43);
	testVectorInt.push_back(17);
	testVectorInt.push_back(0);
	testVectorInt.push_back(19);

	testVectorInt = insertionSortInt.sort(testVectorInt);


	InsertionSort<double> insertionSortDouble;

	std::vector<double> testVectorDouble;

	testVectorDouble.push_back(1.001);
	testVectorDouble.push_back(22.22);
	testVectorDouble.push_back(43.123);
	testVectorDouble.push_back(17.532);
	testVectorDouble.push_back(0.0);
	testVectorDouble.push_back(19.12);

	testVectorDouble = insertionSortDouble.sort(testVectorDouble);

	BinarySearch binarySearch;

	std::vector<int> testBinarySearch;

	testBinarySearch.push_back(1);
	testBinarySearch.push_back(3);
	testBinarySearch.push_back(5);
	testBinarySearch.push_back(7);
	testBinarySearch.push_back(9);
	testBinarySearch.push_back(11);
	testBinarySearch.push_back(13);

	int needle = 1;
	
	int searchResult = 0;
	
	searchResult = binarySearch.binarySearch(needle, testBinarySearch);

	if (searchResult == -1)
	{
		std::cout << "Didn't find it!" << std::endl;
	}
	else
	{
		std::cout << "Found it at index " << searchResult << " (" << testBinarySearch[searchResult] << ")" << std::endl;
	}

	return 0;
}
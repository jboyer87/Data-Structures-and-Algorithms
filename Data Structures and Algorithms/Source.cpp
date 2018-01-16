#include "InsertionSort.h"
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

	return 0;
}
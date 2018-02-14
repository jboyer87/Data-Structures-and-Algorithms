#pragma once
#include <vector>

// Insertion sort is a sorting algorithm that works by sorting the elements in an array
// the same way you might sort playing cards - by comparing cards to the left to each
// card on the right, and inserting the unsorted cards into the sorted cards. It 
// provides O(n^2) sorting performance, because each element must be compared to each
// other element.

template <typename T>
std::vector<T> insertionSort(std::vector<T> listToSort)
{
	for (int i = 1; i < listToSort.size(); i++)
	{
		T current = listToSort[i];
		int previous = i - 1;
		
		while (previous >= 0 && listToSort[previous] > current)
		{
			listToSort[previous + 1] = listToSort[previous];
			previous = previous - 1;
		}

		listToSort[previous + 1] = current;
	}

	return listToSort;
}
#pragma once

#include <vector>

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
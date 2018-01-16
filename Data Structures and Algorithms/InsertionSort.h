#pragma once

#include <vector>

template <typename T>
class InsertionSort
{
public:
	InsertionSort();
	~InsertionSort();
	std::vector<T> sort(std::vector<T> listToSort);

private:
	
};

template <typename T>
InsertionSort<T>::InsertionSort()
{

}

template <typename T>
InsertionSort<T>::~InsertionSort()
{

}

template <typename T>
std::vector<T> InsertionSort<T>::sort(std::vector<T> listToSort)
{
	for (int i = 1; i < listToSort.size(); i++)
	{
		int current = listToSort[i];
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
#pragma once
#include <vector>
#include <iterator>

template <typename T>
class BinarySearch
{
public:
	BinarySearch();
	~BinarySearch();
	int binarySearch(T needle, std::vector<T> haystack);
private:
};

template <typename T>
BinarySearch<T>::BinarySearch()
{

}

template <typename T>
BinarySearch<T>::~BinarySearch()
{

}

template <typename T>
int BinarySearch<T>::binarySearch(T needle, std::vector<T> haystack)
{
	int start = 0;
	int end = haystack.size() - 1;
	int midpoint = 0;

	while (start <= end)
	{
		midpoint = ((start + end) / 2);
		
		if (haystack[midpoint] == needle)
		{
			return midpoint;
		}
		else if (needle < haystack[midpoint])
		{
			end = midpoint - 1;
		}
		else
		{
			start = midpoint + 1;
		}
	}

	// Return -1 if not found
	return -1;
}
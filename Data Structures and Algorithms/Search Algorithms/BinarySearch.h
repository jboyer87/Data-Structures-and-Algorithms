#pragma once
#include <vector>
#include <iterator>

// Binary search works by taking a sorted data structure (vector in this case), and 
// constantly dividing the structure in half by comparing the searched-for element to
// the center element in the list. By dividing in half, binary search will be able to
// tell whether the element can be found in the left or right side of the list, which
// avoids having to compare each element. This provides O(logn) search time.

template <typename T>
int binarySearch(const T needle, const std::vector<T> haystack)
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
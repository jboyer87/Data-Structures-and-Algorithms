#pragma once
#include <vector>
#include <iterator>


class BinarySearch
{
public:
	BinarySearch();
	~BinarySearch();
	int binarySearch(int needle, std::vector<int> haystack);
private:
};

BinarySearch::BinarySearch()
{

}

BinarySearch::~BinarySearch()
{

}

int BinarySearch::binarySearch(int needle, std::vector<int> haystack)
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

	return -1;
}
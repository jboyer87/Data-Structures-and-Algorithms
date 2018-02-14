#pragma once
#include <list>
#include <iterator>

// A priority queue is a structure that maintains sorted order of the elements, keeping
// the highest priority element at the front of the list which provides O(1) retrieval.

namespace PriorityQueue {
	class PriorityQueue {
	public:
		PriorityQueue();
		~PriorityQueue();
		void insert(const int element);
		int min();
		void removeMin();
	private:
		std::list<int> data;
	};

	PriorityQueue::PriorityQueue()
	{
		std::list<int> data;
	}

	PriorityQueue::~PriorityQueue()
	{

	}

	void PriorityQueue::insert(const int element)
	{
		std::list<int>::iterator iterator = data.begin();

		if (data.size() == 0)
		{
			data.push_front(element);
		}
		else
		{	
			for (std::list<int>::iterator iterator = data.begin(); iterator != data.end(); iterator++)
			{
				if (element > *iterator)
				{
					data.insert(iterator, element);
					break;
				}
				else if(*iterator == data.back())
				{
					data.push_back(element);
					break;
				}
			}
		}
	}

	int PriorityQueue::min()
	{
		return data.front();
	}

	void PriorityQueue::removeMin()
	{
		data.pop_front();
	}
}
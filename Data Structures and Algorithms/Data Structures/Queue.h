#pragma once
#include <list>

namespace Queue {
	class Queue {
	public:
		Queue();
		~Queue();
		void enqueue(int element);
		void dequeue();
		int front();
		int size();
		bool empty();

	private:
		std::list<int> data;
		int queueSize;
	};

	Queue::Queue()
	{
		std::list<int> data;
		int queueSize = 0;
	}

	Queue::~Queue()
	{

	}

	void Queue::enqueue(int element)
	{
		data.push_back(element);

		// Increment the size
		queueSize++;
	}

	void Queue::dequeue()
	{
		data.pop_front();

		// Decrement the size
		queueSize--;
	}

	int Queue::front()
	{
		return data.front();
	}

	int Queue::size()
	{
		return queueSize;
	}
	
	bool Queue::empty()
	{
		if (queueSize == 0)
		{
			return true;
		}

		return false;
	}
}
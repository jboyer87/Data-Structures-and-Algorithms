#pragma once
#include <list>

// A deque or double-ended queue is a structure that allows insert/delete operations
// at either end.

namespace Deque {
	class Deque {
	public:
		Deque();
		~Deque();
		void insertFront(int element);
		void insertBack(int element);
		void eraseFront();
		void eraseBack();
		int front();
		int back();
		int size();
		bool empty();

	private:
		int dequeSize;
		std::list<int> data;
	};

	Deque::Deque()
	{
		dequeSize = 0;
		std::list<int> data;
	}

	Deque::~Deque()
	{

	}

	void Deque::insertFront(int element)
	{
		data.push_front(element);
		dequeSize++;
	}

	void Deque::insertBack(int element)
	{
		data.push_back(element);
		dequeSize++;
	}

	void Deque::eraseFront()
	{
		data.pop_front();
		dequeSize--;
	}

	void Deque::eraseBack()
	{
		data.pop_back();
		dequeSize--;
	}

	int Deque::front()
	{
		return data.front();
	}

	int Deque::back()
	{
		return data.back();
	}

	bool Deque::empty()
	{
		if (dequeSize == 0)
		{
			return true;
		}

		return false;
	}

	int Deque::size()
	{
		return dequeSize;
	}
}
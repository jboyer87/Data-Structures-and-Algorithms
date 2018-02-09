#pragma once
#include <list>
#include <stdexcept>

namespace Stack {
	class Stack {
	public:
		Stack();
		~Stack();
		void push(int element);
		int pop();
		int top();
		int size();
		bool empty();
	private:
		int stackSize;
		std::list<int> data;
	};

	Stack::Stack()
	{
		stackSize = 0;
		std::list<int> data;
	}

	Stack::~Stack()
	{

	}

	void Stack::push(int element)
	{
		// Insert the element at the front of the list
		data.push_front(element);

		// Increase the stack size
		stackSize++;
	}

	int Stack::pop()
	{
		// Grab the top element and store temporarily
		int temp = data.front();

		// Remove the top element
		data.pop_front();

		// Decrement the size
		stackSize--;

		// Return the popped element (now removed from the stack)
		return temp;
	}

	int Stack::top()
	{
		if (stackSize == 0)
		{
			throw "Error: Stack is empty!";
		}

		// Return the top element
		return data.front();
	}

	int Stack::size()
	{
		return stackSize;
	}

	bool Stack::empty()
	{
		// If the size is 0, it's empty
		if (stackSize == 0)
		{
			return true;
		}

		// If not, it has elements and is not empty
		return false;
	}
}
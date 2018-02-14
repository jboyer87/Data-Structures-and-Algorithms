#pragma once
#include <forward_list>
#include <stdexcept>

// A stack is a structure that provides first-in last-out access to elements, allowing
// O(1) insertion and O(1) retrieval.

namespace Stack {
	class Stack {
	public:
		Stack();
		~Stack();
		void push(const int element);
		int pop();
		int top();
		int size();
		bool empty();
	private:
		int stackSize;
		std::forward_list<int> data;
	};

	Stack::Stack()
	{
		stackSize = 0;
		std::forward_list<int> data;
	}

	Stack::~Stack()
	{

	}

	// Add element to the top of the stack 
	// O(1)
	void Stack::push(const int element)
	{
		// Insert the element at the front of the list
		data.push_front(element);

		// Increase the stack size
		stackSize++;
	}

	// Remove and return the element at the top of the stack
	// O(1)
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

	// Peek at the element at the top of the stack
	// O(1)
	int Stack::top()
	{
		if (stackSize == 0)
		{
			throw "Error: Stack is empty!";
		}

		// Return the top element
		return data.front();
	}

	// Return the stored interal size variable
	// O(1)
	int Stack::size()
	{
		return stackSize;
	}

	// Return true if empty, false if not empty
	// O(1)
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
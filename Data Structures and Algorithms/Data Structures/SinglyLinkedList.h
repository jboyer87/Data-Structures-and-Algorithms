#pragma once
#include <stdexcept>

// A singly linked list is a structure where nodes have pointers to the next node in
// the list, allowing forward node traversal.

namespace SinglyLinkedList {

	struct Node
	{
		int data;
		Node *next;
	};

	//template <typename T>
	class SinglyLinkedList
	{
	public:
		SinglyLinkedList();
		~SinglyLinkedList();
		Node *getHead();
		void push(int toInsert);
		int getSize();
		int find(int toFind);
		void remove(int atIndex);

	private:
		Node *head;
		Node *tail;
		int size;
	};

	SinglyLinkedList::SinglyLinkedList()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	SinglyLinkedList::~SinglyLinkedList()
	{
	}

	Node* SinglyLinkedList::getHead()
	{
		return head;
	}

	void SinglyLinkedList::push(int toInsert)
	{
		Node *temp = new Node;

		temp->data = toInsert;

		// If list is empty
		if (head == nullptr)
		{
			// Insert node at front, setting head/tail to node
			head = temp;
			tail = temp;
		}
		// If not
		else
		{
			// Insert at the end and update tail pointer
			tail->next = temp;
			tail = temp;
		}
	
		// Increment the list size
		size++;
	}

	int SinglyLinkedList::getSize()
	{
		return size;
	}

	int SinglyLinkedList::find(int toFind)
	{
		Node* front = head;
		Node* current = front;

		// Iterate through the list
		for (int i = 0; i < size; i++)
		{
			// Return the position if found
			if (current->data == toFind)
			{
				return i;
			} 
			else
			{
				current = current->next;
			}
		}

		// Return -1 if not found
		return -1;
	}

	void SinglyLinkedList::remove(int atIndex)
	{
		Node *current = head;

		// If deleting a node that does not exist
		if (atIndex > size - 1 || atIndex < 0)
		{
			// Throw an out of range exception
			throw std::out_of_range("Index is out of range");
		}

		// If deleting head
		if (atIndex == 0)
		{
			Node *temp = head;

			head = head->next;

			delete temp;

			size--;

			// If we have just emptied the list, null out the head/tail
			if (size == 0)
			{
				head = nullptr;
				tail = nullptr;
			}
		}
		else
		{
			int i = 0;

			// While we haven't fallen off the edge
			while (current != tail)
			{
				// If the next node is the node to delete
				if (i == atIndex - 1)
				{
					Node *temp = current->next;

					// If we're deleting the tail
					if (temp == tail)
					{
						// Current is the new tail
						tail = current;
					}

					current->next = current->next->next;

					delete temp;

					size--;

					break;
				}

				current = current->next;
				i++;
			}
		}
	}
}
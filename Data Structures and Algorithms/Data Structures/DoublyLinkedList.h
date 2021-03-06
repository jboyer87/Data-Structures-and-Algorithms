#pragma once
#include <stdexcept>

// A doubly linked list is a structure where nodes have pointers to the previous and
// next nodes in the list, allowing list traversal in both directions.

namespace DoublyLinkedList {
	struct Node
	{
		int data;
		Node *next;
		Node *prev;
	};

	//template <typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		~DoublyLinkedList();
		Node *getHead();
		void push(const int toInsert);
		int getSize();
		int find(const int toFind);
		void remove(const int atIndex);

	private:
		Node *head;
		Node *tail;
		int size;
	};

	DoublyLinkedList::DoublyLinkedList()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	DoublyLinkedList::~DoublyLinkedList()
	{

	}

	Node* DoublyLinkedList::getHead()
	{
		return head;
	}

	void DoublyLinkedList::push(const int toInsert)
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
			temp->prev = tail;
			tail = temp;
		}

		// Increment the list size
		size++;
	}

	int DoublyLinkedList::getSize()
	{
		return size;
	}

	int DoublyLinkedList::find(const int toFind)
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

	void DoublyLinkedList::remove(const int atIndex)
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

			if (size > 1)
			{
				head = head->next;

				head->prev = nullptr;
			}

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

					current->next->prev = current;

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
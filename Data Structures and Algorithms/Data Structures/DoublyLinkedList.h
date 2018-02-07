#pragma once
#include <stdexcept>

struct DoubleNode
{
	int data;
	DoubleNode *next;
	DoubleNode *prev;
};

//template <typename T>
class DoublyLinkedList
{
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	DoubleNode *getHead();
	void push(int toInsert);
	int getSize();
	int find(int toFind);
	void remove(int atIndex);

private:
	DoubleNode *head;
	DoubleNode *tail;
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

DoubleNode* DoublyLinkedList::getHead()
{
	return head;
}

void DoublyLinkedList::push(int toInsert)
{
	DoubleNode *temp = new DoubleNode;

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

int DoublyLinkedList::find(int toFind)
{
	DoubleNode* front = head;
	DoubleNode* current = front;

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

void DoublyLinkedList::remove(int atIndex)
{
	DoubleNode *current = head;

	// If deleting a node that does not exist
	if (atIndex > size - 1 || atIndex < 0)
	{
		// Throw an out of range exception
		throw std::out_of_range("Index is out of range");
	}

	// If deleting head
	if (atIndex == 0)
	{
		DoubleNode *temp = head;

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
				DoubleNode *temp = current->next;

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
#include "Sorting Algorithms\InsertionSort.h"
#include "Search Algorithms\BinarySearch.h"
#include "Data Structures\SinglyLinkedList.h"
#include "Data Structures\DoublyLinkedList.h"
#include "Data Structures\Stack.h"
#include "Data Structures\Queue.h"
#include "Data Structures\Deque.h"
#include "Data Structures\BinaryTree.h"
#include "Data Structures\PriorityQueue.h"
#include "Utilities\String.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
	#pragma region InsertionSort

	// Insertion Sort

	std::cout << "** Insertion Sort **" << std::endl;

	// Test with int
	std::vector<int> testVectorInt;

	testVectorInt.push_back(1);
	testVectorInt.push_back(22);
	testVectorInt.push_back(43);
	testVectorInt.push_back(17);
	testVectorInt.push_back(0);
	testVectorInt.push_back(19);

	testVectorInt = insertionSort(testVectorInt);

	// Test with double
	std::vector<double> testVectorDouble;

	testVectorDouble.push_back(1.001);
	testVectorDouble.push_back(22.22);
	testVectorDouble.push_back(43.123);
	testVectorDouble.push_back(17.532);
	testVectorDouble.push_back(0.0);
	testVectorDouble.push_back(19.12);

	testVectorDouble = insertionSort(testVectorDouble);

	#pragma endregion

	#pragma region BinarySearch

	// Binary Search

	std::cout << "** Binary Search **" << std::endl;

	// Test with int
	std::vector<int> testBinarySearchInt;

	testBinarySearchInt.push_back(1);
	testBinarySearchInt.push_back(3);
	testBinarySearchInt.push_back(5);
	testBinarySearchInt.push_back(7);
	testBinarySearchInt.push_back(9);
	testBinarySearchInt.push_back(11);
	testBinarySearchInt.push_back(13);

	int needleInt = 9;

	int searchResultInt = 0;

	searchResultInt = binarySearch(needleInt, testBinarySearchInt);

	if (searchResultInt == -1)
	{
		std::cout << "Didn't find it" << std::endl;
	}
	else
	{
		std::cout << "Found it at index " << searchResultInt << " (" << testBinarySearchInt[searchResultInt] << ")" << std::endl;
	}

	// Test with string
	std::vector<std::string> testBinarySearchString;

	// Have to add a leading 0 to make sure the ordering is as expected
	testBinarySearchString.push_back("test01");
	testBinarySearchString.push_back("test03");
	testBinarySearchString.push_back("test05");
	testBinarySearchString.push_back("test07");
	testBinarySearchString.push_back("test09");
	testBinarySearchString.push_back("test11");
	testBinarySearchString.push_back("test13");

	std::string needleString = "test09";

	int searchResultString = 0;

	searchResultString = binarySearch(needleString, testBinarySearchString);

	if (searchResultString == -1)
	{
		std::cout << "Didn't find it" << std::endl;
	}
	else
	{
		std::cout << "Found it at index " << searchResultString << " (" << testBinarySearchString[searchResultString] << ")" << std::endl;
	}

	#pragma endregion

	#pragma region SinglyLinkedList

	// Test singly linked list

	std::cout << "** Singly Linked List **" << std::endl;

	SinglyLinkedList::SinglyLinkedList singlyLinkedList;

	singlyLinkedList.push(1);

	// See if an item is in the linked list
	int searchResultSingle = singlyLinkedList.find(1);

	if (searchResultSingle == -1)
	{
		std::cout << "Not found" << std::endl;
	}
	else
	{
		std::cout << "Found at position " << searchResultSingle << std::endl;
	}

	try
	{
		// Remove a node
		singlyLinkedList.remove(0);
	}
	catch (std::out_of_range exception)
	{
		std::cout << exception.what() << std::endl;
	}

	singlyLinkedList.push(1);
	singlyLinkedList.push(2);
	singlyLinkedList.push(3);

	#pragma endregion

	#pragma region DoublyLinkedList

	// Test doubly linked list

	std::cout << "** Doubly Linked List **" << std::endl;

	DoublyLinkedList::DoublyLinkedList doublyLinkedList;

	doublyLinkedList.push(1);
	doublyLinkedList.push(2);
	doublyLinkedList.push(3);

	// See if an item is in the linked list
	int searchResultDouble = doublyLinkedList.find(1);

	if (searchResultDouble == -1)
	{
		std::cout << "Not found" << std::endl;
	}
	else
	{
		std::cout << "Found at position " << searchResultDouble << std::endl;
	}

	try
	{
		// Remove a node
		doublyLinkedList.remove(0);
	}
	catch (std::out_of_range exception)
	{
		std::cout << exception.what() << std::endl;
	}

	doublyLinkedList.push(1);
	doublyLinkedList.push(2);
	doublyLinkedList.push(3);

	#pragma endregion

	#pragma region Stack

	// Test the stack

	std::cout << "** Stack **" << std::endl;

	Stack::Stack stack;

	stack.push(5);
	stack.push(3);
	std::cout << stack.pop() << std::endl;
	stack.push(7);
	std::cout << stack.pop() << std::endl;
	std::cout << stack.top() << std::endl;
	std::cout << stack.pop() << std::endl;
	// Would error, stack is empty
	// std::cout << stack.pop() << std::endl;
	// Would error, stack is empty
	// std::cout << stack.top() << std::endl;
	std::cout << stack.empty() << std::endl;
	stack.push(9);
	stack.push(7);
	stack.push(3);
	stack.push(5);
	std::cout << stack.size() << std::endl;
	std::cout << stack.pop() << std::endl;
	stack.push(8);
	std::cout << stack.pop() << std::endl;
	std::cout << stack.top() << std::endl;

	#pragma endregion

	#pragma region Queue

	// Test the queue

	std::cout << "** Queue **" << std::endl;

	Queue::Queue queue;

	queue.enqueue(5);
	queue.enqueue(3);
	std::cout << queue.front() << std::endl;
	std::cout << queue.size() << std::endl;
	queue.dequeue();
	queue.enqueue(7);
	queue.dequeue();
	std::cout << queue.front() << std::endl;
	queue.dequeue();
	// Would error, queue is empty
	// queue.dequeue();
	std::cout << queue.empty() << std::endl;

	#pragma endregion

	#pragma region Deque

	// Test the deque

	std::cout << "** Deque **" << std::endl;

	Deque::Deque deque;

	deque.insertFront(3);
	deque.insertFront(5);
	std::cout << deque.front() << std::endl;
	std::cout << deque.size() << std::endl;
	deque.eraseFront();
	deque.insertBack(7);
	std::cout << deque.back() << std::endl;
	deque.eraseFront();
	deque.eraseBack();
	std::cout << deque.empty() << std::endl; 
	std::cout << deque.size() << std::endl;

	#pragma endregion

	#pragma region BinaryTree

	// Test the binary tree structure

	std::cout << "** Binary Tree **" << std::endl;

	BinaryTree::BinaryTree binaryTree;

	binaryTree.setRoot(BinaryTree::newNode(1));
	
	// 1

	binaryTree.root()->left = BinaryTree::newNode(2);
	
	//   1
	//  / \
	// 2

	binaryTree.root()->right = BinaryTree::newNode(3);

	//   1
	//  / \
	// 2   3

	binaryTree.root()->left->left = BinaryTree::newNode(4);

	//     1
	//    / \
	//   2   3
	//  / \
	// 4

	binaryTree.root()->left->right = BinaryTree::newNode(5);

	//     1
	//    / \
	//   2   3
	//  / \
	// 4   5

	#pragma endregion

	#pragma region PriorityQueue

	// Test the priority queue structure

	std::cout << "** Priority Queue **" << std::endl;

	PriorityQueue::PriorityQueue priorityQueue;

	priorityQueue.insert(3);
	priorityQueue.insert(2);
	priorityQueue.insert(0);
	priorityQueue.insert(1);
	priorityQueue.insert(5);
	priorityQueue.insert(4);

	std::cout << priorityQueue.min() << std::endl;

	priorityQueue.removeMin();

	#pragma endregion

	#pragma region StringUtilities

	// Test various string utilities

	std::cout << "** String Utilities **" << std::endl;

	// Test reversal on even/odd number of characters
	std::string testString1 = "12345678";
	std::string testString2 = "123456789";

	std::cout << testString1 << std::endl;
	std::cout << testString2 << std::endl;

	testString1 = Utilities::String::reverse(testString1);
	testString2 = Utilities::String::reverse(testString2);

	std::cout << testString1 << std::endl;
	std::cout << testString2 << std::endl;

	#pragma endregion

	return 0;
}
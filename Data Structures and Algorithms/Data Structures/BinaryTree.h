#pragma once

// A binary tree is a tree structure such that each node has two child nodes, a left
// node, and a right node.

namespace BinaryTree {
	struct Node {
		Node();
		~Node();
		int data;
		bool isExternal();
		bool isRoot();
		Node* parent;
		Node* left;
		Node* right;
	};

	struct Node *newNode(const int data)
	{
		struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = data;
		temp->left = nullptr;
		temp->right = nullptr;

		return temp;
	}

	Node::Node()
	{
		left = nullptr;
		right = nullptr;
	}

	bool Node::isExternal()
	{
		if (this->left == nullptr && this->right == nullptr)
		{
			return true;
		}

		return false;
	}

	bool Node::isRoot()
	{
		if (this->parent == nullptr)
		{
			return true;
		}

		return false;
	}

	class BinaryTree {
	public:
		BinaryTree();
		~BinaryTree();
		int size();
		bool empty();
		Node* root();
		Node* insert(const Node* root, const int toInsert);
		void remove(const int key);
		Node* find(const int data);
		void setRoot(Node* newRoot);
	private:
		Node* rootNode;
		int treeSize;
	};

	BinaryTree::BinaryTree()
	{
		// Default size is 0 (only the root node)
		treeSize = 0;

		// Root is initially null
		this->rootNode = nullptr;
	}

	BinaryTree::~BinaryTree()
	{

	}

	int BinaryTree::size()
	{
		return treeSize;
	}

	bool BinaryTree::empty()
	{
		if (treeSize == 0)
		{
			return true;
		}

		return false;
	}

	Node* BinaryTree::root()
	{
		return rootNode;
	}

	Node* BinaryTree::insert(const Node* root, const int toInsert)
	{
		// TODO
		return NULL;
	}

	void BinaryTree::remove(const int key)
	{
		// TODO
	}

	Node* BinaryTree::find(const int data)
	{
		// TODO
		return NULL;
	}

	void BinaryTree::setRoot(Node* newRoot)
	{
		if (this->rootNode == nullptr)
		{
			this->rootNode = newRoot;
		}
		// Otherwise throw an exception so we don't lose the old tree

	}
}
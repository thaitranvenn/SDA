#include <iostream>
#include "BinaryTreeNode.h"
#include "BinaryTree.h"

using namespace std;

void BinaryTree::Create()
{
	Root = nullptr;
	IsCreated = true;
}

BinaryTreeNode* BinaryTree::Find(BinaryTreeNode* node, int key)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (node->data == key)
	{
		return node;
	}
	if (key < node->data)
	{
		return Find(node->pLeft, key);
	}
	else
	{
		return Find(node->pRight, key);
	}
}

BinaryTreeNode* BinaryTree::FindMax(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	while (node->pRight != nullptr)
	{
		node = node->pRight;
	}
	return node;
}

BinaryTreeNode* BinaryTree::FindMin(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	while (node->pLeft != nullptr)
	{
		node = node->pLeft;
	}
	return node;
}

bool BinaryTree::Insert(BinaryTreeNode* node, int key)
{
	if (node == nullptr)
	{
		node = new BinaryTreeNode;
		node->Init(key);
		Root = node;
		return true;
	}
	if (key < node->data && node->pLeft == nullptr)
	{
		node->pLeft = new BinaryTreeNode;
		node->pLeft->Init(key);
		node->pLeft->pParent = node;
		return true;
	}
	else if (key < node->data)
	{
		Insert(node->pLeft, key);
	}
	if (key > node->data && node->pRight == nullptr)
	{
		node->pRight = new BinaryTreeNode;
		node->pRight->Init(key);
		node->pRight->pParent = node;
		return true;
	}
	else if (key > node->data)
	{
		Insert(node->pRight, key);
	}
	else
	{
		return false;
	}
}

bool BinaryTree::Remove(BinaryTreeNode* node, int key)
{
	if (node == nullptr)
	{
		return false;
	}
	if (key < node->data)
	{
		Remove(node->pLeft, key);
	}
	else if (key > node->data)
	{
		Remove(node->pRight, key);
	}
	else
	{
		if (node->pLeft == nullptr && node->pRight == nullptr)
		{
			if (node->pParent != nullptr)
			{
				node->pParent->pLeft == node ? node->pParent->pLeft = nullptr :
					node->pParent->pRight = nullptr;
			}
			else
			{
				Root = nullptr;
			}
			delete node;
		}
		else if (node->pLeft != nullptr && node->pRight == nullptr)
		{
			BinaryTreeNode* oldNode = node;
			node = node->pLeft;
			node->pParent = oldNode->pParent;
			if (oldNode->pParent != nullptr)
			{
				oldNode->pParent->pLeft == oldNode ?
					oldNode->pParent->pLeft = node :
					oldNode->pParent->pRight = node;
			}
			else
			{
				Root = node;
			}
			delete oldNode;
		}
		else if (node->pRight != nullptr && node->pLeft == nullptr)
		{
			BinaryTreeNode* oldNode = node;
			node = node->pRight;
			node->pParent = oldNode->pParent;
			if (oldNode->pParent != nullptr)
			{
				oldNode->pParent->pLeft == oldNode ?
					oldNode->pParent->pLeft = node :
					oldNode->pParent->pRight = node;
			}
			else
			{
				Root = node;
			}
			delete oldNode;
		}
		else
		{
			BinaryTreeNode* oldNode = node;
			node = FindMin(oldNode->pRight);
			int min = node->data;
			Remove(node, min);
			oldNode->data = min;
		}
		return true;
	}
}

void BinaryTree::Clear(BinaryTreeNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	Clear(node->pLeft);
	Clear(node->pRight);
	delete node;
}

bool BinaryTree::IsEmpty()
{
	return Root == nullptr;
}

void PrintBinaryTree(BinaryTreeNode* node, int level)
{
	if (node != nullptr)
	{
		PrintBinaryTree(node->pRight, level + 1);
		for (int i = 0; i < level; i++)
		{
			cout << "\t";
		}
		cout << node->data << "\n";
		PrintBinaryTree(node->pLeft, level + 1);
	}
}
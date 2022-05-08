#include "TreapNode.h"
#include "Treap.h"

using namespace std;

void Treap::Create()
{
	Root = nullptr;
	IsCreated = true;
}

TreapNode* Treap::Find(TreapNode* node, int key)
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

void Treap::Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right)
{
	if (node == nullptr)
	{
		left = right = nullptr;
	}
	else if (node->data <= key)
	{
		Split(node->pRight, key, node->pRight, right);
		left = node;
	}
	else if (node->data >= key)
	{
		Split(node->pLeft, key, left, node->pLeft);
		right = node;
	}
}

TreapNode* Treap::Merge(TreapNode* left, TreapNode* right)
{
	if (left == nullptr || right == nullptr)
	{
		return left == nullptr ? right : left;
	}
	if (left->Priority > right->Priority)
	{
		left->pRight = Merge(left->pRight, right);
		return left;
	}
	right->pLeft = Merge(left, right->pLeft);
	return right;
}

void Treap::SlowInsert(int key)
{
	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	Split(Root, key, left, right);
	TreapNode* node = new TreapNode;
	node->Init(key);
	left = Merge(left, node);
	Root = Merge(left, right);
}

void Treap::FastInsert(int key, int priority)
{
	TreapNode* current = Root;
	while (current != nullptr && current->Priority > priority)
	{
		if (current->data > key)
		{
			if (current->pLeft == nullptr) break;
			current = current->pLeft;
		}
		else
		{
			if (current->pRight == nullptr) break;
			current = current->pRight;
		}
	}
	TreapNode* inserted = new TreapNode();
	inserted->data = key;
	inserted->Priority = priority;
	if (Root == nullptr || Root->Priority < inserted->Priority)
	{
		Split(current, key, inserted->pLeft, inserted->pRight);
		Root = inserted;
	}
	else if (current->data > inserted->data)
	{
		Split(current->pLeft, key, inserted->pLeft, inserted->pRight);
		current->pLeft = inserted;
	}
	else
	{
		Split(current->pRight, key, inserted->pLeft, inserted->pRight);
		current->pRight = inserted;
	}
}

TreapNode* Treap::SlowDelete(int key)
{
	TreapNode* left, * deleteElem, * right;
	Split(Root, key - 1, left, right);
	Split(right, key, deleteElem, right);
	delete deleteElem;
	return Merge(left, right);
}

bool Treap::FastDelete(TreapNode* node, TreapNode* parent, int key)
{
	if (node == nullptr)
	{
		return false;
	}
	if (key < node->data)
	{
		FastDelete(node->pLeft, node, key);
	}
	else if (key > node->data)
	{
		FastDelete(node->pRight, node, key);
	}
	else
	{
		TreapNode* newNode = Merge(node->pLeft, node->pRight);
		if (parent != nullptr)
		{
			parent->pLeft == node ? parent->pLeft = newNode : parent->pRight = newNode;
		}
		else
		{
			Root = newNode;
		}
		delete node;
		return true;
	}
}

void Treap::Clear(TreapNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	Clear(node->pLeft);
	Clear(node->pRight);
	delete node;
}

bool Treap::IsEmpty()
{
	return Root == nullptr;
}

void PrintTreap(TreapNode* node, int level)
{
	if (node != nullptr)
	{
		PrintTreap(node->pRight, level + 1);
		for (int i = 0; i < level; i++)
		{
			cout << "\t";
		}
		cout << node->data << "; " << node->Priority << "\n";
		PrintTreap(node->pLeft, level + 1);
	}
}
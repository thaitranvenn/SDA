#pragma once
struct BinaryTree
{
	BinaryTreeNode* Root = nullptr;
	void Create();

	//TODO: передача node
	BinaryTreeNode* Find(BinaryTreeNode* node, int key);
	BinaryTreeNode* FindMax(BinaryTreeNode* node);
	BinaryTreeNode* FindMin(BinaryTreeNode* node);
	bool Insert(BinaryTreeNode* node, int key);
	bool Remove(BinaryTreeNode* node, int key);
	void Clear(BinaryTreeNode* node);
	bool IsEmpty();
	bool IsCreated;
};

void PrintBinaryTree(BinaryTreeNode* node, int level);
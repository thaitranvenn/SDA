#pragma once

struct BinaryTreeNode
{
	int data;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
	BinaryTreeNode* pParent;
	void Init(int data);
};
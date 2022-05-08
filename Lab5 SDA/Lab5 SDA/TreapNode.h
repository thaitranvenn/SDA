#pragma once
struct TreapNode
{
	int data;
	int Priority;
	TreapNode* pLeft;
	TreapNode* pRight;
	void Init(int key);
};
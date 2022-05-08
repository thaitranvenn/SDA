#pragma once
#include <iostream>
#include <ctime>
#include "TreapNode.h"

struct Treap
{
	TreapNode* Root;
	void Create();
	TreapNode* Find(TreapNode* node, int key);
	void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);
	TreapNode* Merge(TreapNode* left, TreapNode* right);
	void SlowInsert(int key);
	void FastInsert(int key, int priority);
	TreapNode* SlowDelete(int key);
	bool FastDelete(TreapNode* node, TreapNode* parent, int key);
	void Clear(TreapNode* node);
	bool IsEmpty();
	bool IsCreated;
};

void PrintTreap(TreapNode* node, int level);
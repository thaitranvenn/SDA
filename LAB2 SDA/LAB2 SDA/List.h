#pragma once
#include "Header.h"

struct List
{
	Node* pHead = nullptr;
	Node* pTail = nullptr;

	void AddHead(int element);
	void AddTail(int element);
	void AddAfter(int element, int index);
	void AddBefore(int element, int index);
	void DeleteTail();
	void DeleteElement(int index);
	void DeleteHead();
};
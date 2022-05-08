#pragma once
#include "Node.h"

struct List
{
	Node* Head = nullptr;
	int Length = 0;
};

void AddNewKey(List* list, string key, string value);
void DeleteNodeKey(List* list, string value);
bool Trigger(List* list, string key);
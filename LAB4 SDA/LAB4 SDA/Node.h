#pragma once
#include <string>

using namespace std;

struct Node
{
	string Key;
	string Value;
	Node* NextNode = nullptr;
	Node* PrevNode = nullptr;
};
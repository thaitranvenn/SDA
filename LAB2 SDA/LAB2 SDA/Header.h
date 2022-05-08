#pragma once
#include <iostream>
using namespace std;

void menu();

struct Node
{
	// поле данных
	int data = 0;
	// указатель на следующий элемент
	Node* pNext = nullptr;
	// указатель на предыдущий элемент
	Node* pPrev = nullptr;
};

struct StructList
{
	// поле данных
	int data;
	// Для порядкового номера в списке
	int index;
	// указатель на следующий элемент
	StructList* pNext;
	// указатель на предыдущий элемент
	StructList* pPrev;
};

StructList* CreateFirst(int a);
StructList* PushNew(StructList* List, int number);
void Listprint(StructList* List);
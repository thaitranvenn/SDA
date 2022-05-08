#pragma once
#include "Header.h"

StructList* CreateFirst(int a)
{
	StructList* list;
	// выделение памяти под корень списка
	list = (struct StructList*)malloc(sizeof(struct StructList));
	list->data = a;
	// указатель на следующий узел
	list->pNext = nullptr;
	// указатель на предыдущий узел
	list->pPrev = nullptr;
	list->index = 1;
	return(list);
};
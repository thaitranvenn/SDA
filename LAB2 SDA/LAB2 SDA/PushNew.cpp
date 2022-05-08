#include "Header.h"

StructList* PushNew(StructList* List, int number)
{
	StructList* temp;
	StructList* pNode;
	while (List->pNext != nullptr)
	{
		List = List->pNext;
	}
	temp = (StructList*)malloc(sizeof(StructList));
	// сохранение указателя на следующий узел
	pNode = List->pNext;
	// предыдущий узел указывает на создаваемый
	List->pNext = temp;
	// сохранение поля данных добавляемого узла
	temp->data = number;
	// созданный узел указывает на следующий узел
	temp->pNext = pNode;
	// созданный узел указывает на предыдущий узел
	temp->pPrev = List;
	temp->index = List->index + 1;
	if (pNode != nullptr)
	{
		pNode->pPrev = temp;
	}
	return(temp);
};
#include "List.h"

// добавление ключа
void AddNewKey(List* list, string key, string value)
{
	Node* temp = new Node();
	temp->Key = key;
	temp->Value = value;
	if (list->Head == nullptr)
	{
		list->Head = temp;
	}
	else
	{
		Node* Temperary = list->Head->PrevNode;
		Temperary = temp;
		temp->NextNode = list->Head;
		list->Head = temp;
	}
	list->Length++;
}

// удаление по ключу
void DeleteNodeKey(List* list, string key)
{
	Node* temp = list->Head;
	if (temp != nullptr)
	{
		while (temp->Key != key)
		{
			// поиск ключа
			temp = temp->NextNode;
		}
		if ((temp->PrevNode != nullptr) && (temp->NextNode != nullptr))
		{
			temp->PrevNode->NextNode = temp->NextNode;
			temp->NextNode->PrevNode = temp->PrevNode;
		}
		else if ((temp->PrevNode == nullptr) && (temp->NextNode != nullptr))
		{
			temp->NextNode->PrevNode = temp->PrevNode;
			list->Head = temp->NextNode;
		}
		else if ((temp->PrevNode != nullptr) && (temp->NextNode == nullptr))
		{
			temp->PrevNode->NextNode = temp->NextNode;
		}
		// перенос указателей
		list->Length--;
		// удаление записи
		if (temp == list->Head)
		{
			list->Head = nullptr;
		}
		delete temp;
	}
}

// устранение коллизий
bool Trigger(List* list, string key)
{
	Node* temp = list->Head;
	while (temp != nullptr)
	{
		if (temp->Key == key)
		{
			// вернёт если такой ключ уже есть
			return(true);
		}
		temp = temp->NextNode;
	}
	return(false);
}
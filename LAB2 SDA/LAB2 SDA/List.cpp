#include "List.h"

void List::AddHead(int element)
{
	Node* temp = new Node;
	temp->data = element;
	temp->pNext = pHead;
	pHead->pPrev = temp;
	pHead = pHead->pPrev;
}

void List::AddTail(int element)
{
	Node* temp = new Node;
	temp->data = element;
	temp->pPrev = pTail;
	pTail->pNext = temp;
	pTail = pTail->pNext;
}

void List::AddAfter(int element, int index)
{
	Node* temp = new Node;
	Node* tempNode = pHead;
	temp->data = element;
	for (int i = 1; i <= index - 1; i++)
	{
		tempNode = tempNode->pNext;
	}
	temp->pPrev = tempNode;
	temp->pNext = tempNode->pNext;
	tempNode->pNext->pPrev = temp;
	tempNode->pNext = temp;
}

void List::AddBefore(int element, int index)
{
	Node* temp = new Node;
	Node* tempNode = pHead;
	temp->data = element;
	for (int i = 1; i <= index - 1; i++)
	{
		tempNode = tempNode->pNext;
	}
	temp->pNext = tempNode;
	tempNode->pPrev->pNext = temp;
	temp->pPrev = tempNode->pPrev;
	tempNode->pPrev = temp;
}

void List::DeleteElement(int index)
{
	Node* temp;
	Node* tempNode = pHead;
	for (int i = 1; i < index - 1; i++)
	{
		tempNode = tempNode->pNext;
	}
	temp = tempNode->pNext;
	temp->pNext->pPrev = tempNode;
	tempNode->pNext = temp->pNext;
	delete temp;
}

void List::DeleteHead()
{
	Node* temp;
	temp = pHead;
	pHead = pHead->pNext;
	delete temp;
	if (pHead != nullptr)
	{
		pHead->pPrev = nullptr;
	}
}

void List::DeleteTail()
{
	Node* temp;
	temp = pTail;
	pTail = pTail->pPrev;
	if (pTail != nullptr)
	{
		pTail->pNext = nullptr;
	}
	delete temp;
}
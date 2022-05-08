#include <iostream>
#include "Stack.h"
#include "TwoStacksQueue.h"

using namespace std;

void twoStacksQueue::Push(int element)
{
	Input->Push(element);
}

void twoStacksQueue::moreCapacity()
{
	int* temp = new int[Input->Capacity * 2];
	for (int i = 0; i < Input->Capacity; i++)
	{
		temp[i] = Input->Array[i];
	}
	delete[] Input->Array;
	Input->Capacity = Input->Capacity * 2;
	Output->Capacity = Input->Capacity * 2;
	Input->Array = temp;
	Output->Array = Input->Array;
}

void twoStacksQueue::Reverse()
{
	int j = 0;
	for (int i = Input->Length - 1; i >= 0; i--)
	{
		Output->Array[j] = Input->Array[i];
		j++;
	}
	if (Input->Length == 1)
	{
		Output->Array[0] = Input->Array[0];
	}
	Output->Length = Input->Length;
	Input->Length = 0;
}

int twoStacksQueue::Pop()
{
	int tempPop = Output->Array[Output->Length - 1];
	Output->Length--;
	return(tempPop);
}

void twoStacksQueue::Delete()
{
	Input->Length = 0;
	delete[] Input->Array;
	Input->Capacity = 8;
	Input->isCreated = false;
	Input->Array = new int[Input->Capacity];
	Output->Array = Input->Array;

	Output->Length = 0;
	delete[] Output->Array;
	Output->Capacity = 8;
	Output->isCreated = false;
	Input->Array = new int[Input->Capacity];
	Output->Array = Input->Array;
}
#include <iostream>
#include "Stack.h"

using namespace std;

void Stack::Push(int number)
{
	Array[Length] = number;
	Length++;
}

int Stack::Pop()
{
	Length--;
	return Array[Length];
}

void Stack::listStack()
{
	for (int i = 0; i < Length; i++)
	{
		cout << "  " << Array[i];
	}
	cout << endl << endl;
}

void Stack::moreCapacity()
{
	int* temp = new int[Capacity * 2];
	for (int i = 0; i < Length; i++)
	{
		temp[i] = Array[i];
	}
	Capacity = Capacity * 2;
	delete[] Array;
	Array = temp;
}
#include <iostream>
#include "RingBuffer.h"

using namespace std;

void ringBuffer::List()
{
	int read = Read;
	for (int i = 0; i < Length; i++)
	{
		cout << Buffer[read] << " ";
		read = (read + 1) % Capacity;
	}
	cout << endl << endl;
};

void ringBuffer::Push(int element)
{
	Buffer[Write] = element;
	Write = (Write + 1) % Capacity;
	if (Length == Capacity)
	{
		Read = (Read + 1) % Capacity;
	}
	else
	{
		Length++;
	}
};

int ringBuffer::Pop()
{
	int element = Buffer[Read];
	Read = (Read + 1) % Capacity;
	Length--;
	return element;
};

void ringBuffer::moreCapacity()
{
	int* temp = new int[Capacity * 2];
	for (int i = 0; i < Capacity; i++)
	{
		temp[i] = Buffer[Read];
		Read = (Read + 1) % Capacity;
	}
	delete[] Buffer;
	Capacity = Capacity * 2;
	Buffer = temp;
	Read = 0;
	Write = Length;
}

void ringBuffer::Delete()
{
	Length = 0;
	Read = 0;
	Write = 0;
	Capacity = 0;
	delete[] Buffer;
	Buffer = new int[Capacity];
}
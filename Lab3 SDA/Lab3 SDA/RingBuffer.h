#pragma once
#include <iostream>

using namespace std;

// кольцевой буфер
struct ringBuffer
{
	int Read = 0;
	int Write = 0;
	int Length = 0;
	// Ёмкость буфера
	int Capacity = 8;
	// Массив
	int* Buffer = new int[Capacity * 2];
	bool Continue = false;

	void List();
	void Push(int element);
	int Pop();
	void moreCapacity();
	void Delete();
};
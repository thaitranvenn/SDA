#pragma once

// стек
struct Stack
{
	int Length = 0;
	int Capacity = 8;
	int* Array;
	bool isCreated = false;
	bool isContinue = false;
	// Вывод
	int Pop();
	void Push(int number);
	void moreCapacity();
	void listStack();
};
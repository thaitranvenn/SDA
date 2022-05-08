#pragma once
#include "Stack.h"
struct twoStacksQueue
{
	Stack* Input = new Stack;
	Stack* Output = new Stack;

	void Push(int element);
	int Pop();
	void Reverse();
	void Delete();
	void moreCapacity();
	bool isContinue = false;
	bool isCreated = false;
};
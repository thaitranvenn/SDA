#include <iostream>
#include "RingBuffer.h"
#include "RingBufferQueue.h"

using namespace std;

int ringBufferQueue::Pop()
{
	int element = Buff->Pop();
	return element;
}

void ringBufferQueue::Push(int element)
{
	Buff->Push(element);
}

void ringBufferQueue::moreCapacity()
{
	Buff->moreCapacity();
}

void ringBufferQueue::List()
{
	Buff->List();
}

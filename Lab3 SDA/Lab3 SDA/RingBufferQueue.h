#include "RingBuffer.h"

struct ringBufferQueue
{
	ringBuffer* Buff = new ringBuffer;
	int Pop();
	void Push(int element);
	void moreCapacity();
	void List();
};
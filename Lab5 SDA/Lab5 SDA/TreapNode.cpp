#include <iostream>
#include <ctime>
#include "TreapNode.h"

void TreapNode::Init(int key)
{
	srand(time(0));
	data = key;
	Priority = rand() % 100;
	pLeft = nullptr;
	pRight = nullptr;
}

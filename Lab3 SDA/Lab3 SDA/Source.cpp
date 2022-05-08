#include <iostream>
#include "Check.h"
#include "Stack.h"
#include "RingBuffer.h"
#include "RingBufferQueue.h" 
#include "TwoStacksQueue.h"

using namespace std;

int main()
{
	Stack newStack;
	ringBuffer ringBuff;
	ringBuffer Queue;
	twoStacksQueue twoQueue;
	bool back = false;
	int number = 0;
	while (true)
	{
		system("cls");
		cout << "|0| Exit the program\n";
		cout << "|1| Work with the stack\n";
		cout << "|2| Work with the ring buffer\n";
		cout << "|3| Work with a queue based on a ring buffer\n";
		cout << "|4| Work with a queue based on two stacks\n";
		Check(number);
		switch (number)
		{
			case 0:
			{
				return 0;
			}
			// Стек
			case 1:
			{
				back = false;
				while (!back)
				{
					system("cls");
					if (newStack.isContinue)
					{
						cout << "You did not clear the stack, continue...\n";
						newStack.isContinue = false;
					}
					if (newStack.Length != 0)
					{
						cout << "\nNow on the stack: ";
						newStack.listStack();
					}
					else
					{
						cout << "The stack is empty or not created..\n";
					}
					cout << "|0| Return to previous menu:\n";
					cout << "|1| Create stack:\n";
					cout << "|2| Add value to stack (Push):\n";
					cout << "|3| Extract value from stack (Pop):\n";
					cout << "|4| Increase stack capacity:\n";
					cout << "|5| Clear stack:\n";
					Check(number);
					switch (number)
					{
						case 0:
						{
							if (newStack.Length != 0)
							{
								newStack.isContinue = true;
							}
							back = true;
							break;
						}
						case 1:
						{
							if (!newStack.isCreated)
							{
								newStack.Array = new int[newStack.Capacity];
								newStack.isCreated = true;
								cout << "You created a stack.\n";
								system("pause");
							}
							else
							{
								cout << "The stack has already been created...\n";
								system("pause");
							}
							break;
						}
						case 2:
						{
							if (!newStack.isCreated)
							{
								cout << "Please create a stack first!\n";
								system("pause");
								break;
							}
							if (newStack.Length == newStack.Capacity)
							{
								cout << "The stack is full.\n";
								system("pause");
							}
							else
							{
								cout << "\nEnter a value to add to the stack: \n";
								Check(number);
								newStack.Push(number);
							}
							break;
						}
						case 3:
						{
							if (newStack.Length != 0)
							{
								cout << "Received data: " << newStack.Pop() << endl;
							}
							else
							{
								cout << "The stack is empty.\n";
							}
							system("pause");
							break;
						}
						case 4:
						{
							cout << "\nCapacity doubled.\n";
							newStack.moreCapacity();
							system("pause");
							break;
						}
						case 5:
						{
							if (!newStack.isCreated)
							{
								cout << "\nStack is not created.\n";
								system("pause");
								break;
							}
							delete[] newStack.Array;
							newStack.isCreated = false;
							newStack.Length = 0;
							break;
						}
					}
				}
				break;
			}
			// Кольцевой буфер
			case 2:
			{
				back = false;
				while (!back)
				{
					system("cls");
					if (ringBuff.Continue)
					{
						cout << "You did not clear the ring buffer, continue from the same place...\n";
						ringBuff.Continue = false;
					}
					if (ringBuff.Length == 0)
					{
						cout << "Ring buffer is empty.\n";
					}
					else
					{
						cout << "Now in buffer: ";
						ringBuff.List();
					}
					cout << "|0| Return to previous menu:\n";
					cout << "|1| Add to value in ring buffer:\n";
					cout << "|2| Get value from buffer:\n";
					cout << "|3| Buffer free space:\n";
					cout << "|4| Buffer space occupied:\n";
					cout << "|5| Extend Ring Buffer:\n";
					cout << "|6| Delete buffer:\n";
					Check(number);
					switch (number)
					{
						case 0:
						{
							if (ringBuff.Length != 0)
							{
								ringBuff.Continue = true;
							}
							back = true;
							break;
						}
						case 1:
						{
							cout << "\nEnter a value to add: \n";
							Check(number);
							ringBuff.Push(number);
							break;
						}
						case 2:
						{
							if (ringBuff.Length == 0)
							{
								cout << "\nCannot extract data from an empty buffer.\n";
								system("pause");
								break;
							}
							cout << "Received data: ";
							cout << ringBuff.Pop() << endl;
							system("pause");
							break;
						}
						case 3:
						{
							cout << "Buffer free space: " << ringBuff.Capacity - ringBuff.Length << endl;
							system("pause");
							break;
						}
						case 4:
						{
							cout << "Buffer space occupied: " << ringBuff.Capacity << endl;
							system("pause");
							break;
						}
						case 5:
						{
							ringBuff.moreCapacity();
							cout << "Ring buffer capacity doubled.\n";
							system("pause");
							break;
						}
						case 6:
						{
							ringBuff.Delete();
							break;
						}
					}
				}
				break;
			}
			// Очередь на базе кольцевого буфера
			case 3:
			{
				back = false;
				while (!back)
				{
					system("cls");
					if (Queue.Continue)
					{
						cout << "You have not cleared the queue, continue from the same place...\n";
						Queue.Continue = false;
					}
					if (Queue.Length == Queue.Capacity)
					{
						int* temp = new int[Queue.Capacity * 2];
						for (int i = 0; i < Queue.Length; i++)
						{
							temp[i] = Queue.Buffer[Queue.Read];
							Queue.Read = (Queue.Read + 1) % Queue.Capacity;
						}
						delete[] Queue.Buffer;
						Queue.Buffer = temp;
						Queue.Capacity = Queue.Capacity * 2;
						Queue.Read = 0;
						Queue.Write = Queue.Length;
					}
					if (Queue.Length == 0)
					{
						cout << "Queue is empty.\n";
					}
					else
					{
						cout << "Now in queue: ";
						Queue.List();
					}
					cout << "|0| Return to previous menu:\n";
					cout << "|1| Add to Queue Value:\n";
					cout << "|2| Get value from queue:\n";
					cout << "|3| Clear queue:\n";
					Check(number);
					switch (number)
					{
						case 0:
						{
							if (Queue.Length != 0)
							{
								Queue.Continue = true;
							}
							back = true;
							break;
						}
						case 1:
						{
							cout << "\nEnter a value to add:\n";
							Check(number);
							Queue.Push(number);
							break;
						}
						case 2:
						{
							if (Queue.Length == 0)
							{
								cout << "Queue is empty, data cannot be extracted\n";
								system("pause");
								break;
							}
							Queue.Pop();
							break;
						}
						case 3:
						{
							Queue.Delete();
							break;
						}
					}
				}
				break;
			}
			// Очередь на базе двух стеков
			case 4:
			{
				back = false;
				while (!back)
				{
					system("cls");
					if (!twoQueue.isCreated)
					{
						twoQueue.isCreated = true;
						twoQueue.Input->Array = new int[twoQueue.Input->Capacity];
						twoQueue.Output->Array = new int[twoQueue.Output->Capacity];
						twoQueue.Output->isCreated = true;
						twoQueue.Input->isCreated = true;
					}
					if (twoQueue.isContinue)
					{
						cout << "You have not cleared the queue. Continue...\n";
						twoQueue.isContinue = false;
					}
					if (twoQueue.Input->Length == twoQueue.Input->Capacity)
					{
						twoQueue.moreCapacity();
					}
					if (twoQueue.Input->Length == 0)
					{
						cout << "Queue 1 is empty.\n";
					}
					else
					{
						cout << "Now in queue 1: ";
						twoQueue.Input->listStack();
					}
					if (twoQueue.Output->Length == 0)
					{
						cout << "Queue 2 is empty.\n\n";
					}
					else
					{
						cout << "\nNow in queue 2: ";
						twoQueue.Output->listStack();
					}
					cout << "|0| Return to previous menu:\n";
					cout << "|1| Add element to queue\n";
					cout << "|2| Extract element from queue\n";
					cout << "|3| Clear Queue\n";
					Check(number);
					switch (number)
					{
						case 0:
						{
							if (twoQueue.Input->Length != 0)
							{
								twoQueue.isContinue = true;
							}
							back = true;
							break;
						}
						case 1:
						{
							cout << "\nEnter element to insert: \n";
							Check(number);
							twoQueue.Push(number);
							break;
						}
						case 2:
						{
							if ((twoQueue.Input->Length == 0) && (twoQueue.Output->Length == 0))
							{
								cout << "\nEmpty!\n";
								system("pause");
								break;
							}
							if (twoQueue.Output->Length <= 0)
							{
								twoQueue.Reverse();
								cout << "Stack is empty!\n";
							}
							else
							{
								cout << "Received value: " << twoQueue.Pop() << "\n";
								system("pause");
							}
							if ((twoQueue.Input->Length == 0) && (twoQueue.Output->Length == 0))
							{
								twoQueue.isCreated = false;
							}
							break;
						}
						case 3:
						{
							twoQueue.Delete();
							break;
						}
					}
				}
				break;
			}
		}
	}
}
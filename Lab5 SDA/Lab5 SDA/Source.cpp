#include <iostream>
#include <ctime>
#include "BinaryTreeNode.h"
#include "BinaryTree.h"
#include "TreapNode.h"
#include "Treap.h"
#include <conio.h>
#include "Check.h"

using namespace std;

int main()
{
	srand;
	char activeKey = 0;
	BinaryTree binaryTree;
	Treap* treap = new Treap();
	binaryTree.IsCreated = false;
	treap->IsCreated = false;
	bool exit = false;
	do
	{
		system("cls");
		cout << "\n====PROGRAM MENU====\n";
		cout << "|0| Exit\n";
		cout << "|1| Binary tree\n";
		cout << "|2| Cartesian tree\n";
		cout << "=========END========\n";
		cout << "Your choose:\n";
		bool back = false;
		activeKey = _getch();
		switch (activeKey)
		{
			// бинарное дерево
			case '1':
			{
				while (!back)
				{
					cout << endl << "=============MENU==============\n";
					cout << "|0| To previous menu.\n";
					cout << "|1| Add an element.\n";
					cout << "|2| Delete element.\n";
					cout << "|3| Binary tree search.\n";
					cout << "|4| Find the maximum.\n";
					cout << "|5| Find the minimum.\n";
					cout << "|6| Remove tree.\n";
					cout << "|7| Output a search binary tree\n";
					cout << "=============END===============\n";
					cout << "Your choose:\n";
					activeKey = _getch();
					switch (activeKey)
					{
						case '1':
						{
							if (!binaryTree.IsCreated)
							{
								binaryTree.Create();
							}
							cout << "Enter key of the value: ";
							int key = GetNumber();
							cout << "\n";
							if (binaryTree.Insert(binaryTree.Root, key) == false)
							{
								cout << "Already exist an element in that key\n\n";
							}
							PrintBinaryTree(binaryTree.Root, 0);
							system("pause");
							break;
						}
						case '2':
						{
							if (!binaryTree.IsCreated || binaryTree.IsEmpty())
							{
								cout << "Tree is empty!\n";
								break;
							}
							cout << "Enter key of the value: ";
							int key = GetNumber();
							cout << "\n";
							if (binaryTree.Remove(binaryTree.Root, key) == false)
							{
								cout << "No such element exists!\n\n";
							}
							PrintBinaryTree(binaryTree.Root, 0);
							break;
						}
						case '3':
						{
							if (!binaryTree.IsCreated || binaryTree.IsEmpty())
							{
								cout << "Tree is empty!\n ";
								break;
							}
							cout << "Enter key of the value: ";
							int key = GetNumber();
							cout << "\n";
							BinaryTreeNode* node = binaryTree.Find(binaryTree.Root, key);
							if (node == nullptr)
							{
								cout << "Does not have that element\n";
							}
							else
							{
								cout << "Found element! \n";
							}
							system("pause");
							break;
						}
						case '4':
						{
							if (!binaryTree.IsCreated || binaryTree.IsEmpty())
							{
								cout << "Tree is empty!\n";
								break;
							}
							BinaryTreeNode* max;
							max = binaryTree.FindMax(binaryTree.Root);
							if (max == nullptr)
							{
								cout << "Tree is empty!\n";
								break;
							}
							cout << "Maximum element: " << max->data << "\n";
							system("pause");
							break;
						}
						case '5':
						{
							if (!binaryTree.IsCreated || binaryTree.IsEmpty())
							{
								cout << "Tree is empty!\n";
								break;
							}
							BinaryTreeNode* min;
							min = binaryTree.FindMin(binaryTree.Root);
							if (min == nullptr)
							{
								cout << "Tree is empty!\n";
								break;
							}
							cout << "Minimum element: " << min->data << "\n";
							system("pause");
							break;
						}
						case '6':
						{
							if (!binaryTree.IsCreated)
							{
								break;
							}
							binaryTree.Clear(binaryTree.Root);
							binaryTree.IsCreated = false;
							break;
						}
						case '7':
						{
							if (!binaryTree.IsCreated || binaryTree.IsEmpty())
							{
								cout << "Tree is empty!\n";
								break;
							}
							cout << "\n";
							PrintBinaryTree(binaryTree.Root, 0);
							system("pause");
							break;
						}
						case '0':
						{
							back = true;
							break;
						}
					}
				}
				break;
			}
			// Декартово дерево
			case '2':
			{
				while (!back)
				{
					cout << "\n=====================MENU=====================\n";
					cout << "|0| To previous menu\n";
					cout << "|1| Add an item with a non-optimized algorithm.\n";
					cout << "|2| Add an item with an optimized algorithm.\n";
					cout << "|3| Delete an item by a non-optimized algorithm.\n";
					cout << "|4| Delete an element with an optimized algorithm.\n";
					cout << "|5| Search an element.\n";
					cout << "|6| Delete tree.\n";
					cout << "======================END=====================\n";
					cout << "Your choose:\n";
					activeKey = _getch();
					switch (activeKey)
					{
						case '1':
						{
							if (!treap->IsCreated)
							{
								treap->Create();
							}
							cout << "Enter key of the value: ";
							int key = GetNumber();
							cout << "\n";
							TreapNode* node = treap->Find(treap->Root, key);
							while (node != nullptr)
							{
								cout << "Already exist an element in that key. Try again! ";
								key = GetNumber();
								cout << "\n";
								node = treap->Find(treap->Root, key);
							}
							treap->SlowInsert(key);
							PrintTreap(treap->Root, 0);
							system("pause");
							break;
						}
						case '2':
						{
							if (!treap->IsCreated)
							{
								treap->Create();
							}
							cout << "Enter key of the value: ";
							int key = GetNumber();
							cout << "\n";
							TreapNode* node = treap->Find(treap->Root, key);
							while (node != nullptr)
							{
								cout << "Already exist an element in that key. Try again! ";
								key = GetNumber();
								cout << "\n";
								node = treap->Find(treap->Root, key);
							}
							srand(time(0));
							int priority = rand() % 100;
							treap->FastInsert(key, priority);
							PrintTreap(treap->Root, 0);
							system("pause");
							break;
						}
						case '3':
						{
							if (!treap->IsCreated || treap->IsEmpty())
							{
								cout << "Tree is empty!\n";
								break;
							}
							cout << "Enter key of the value: ";
							int key = GetNumber();
							cout << "\n";
							treap->Root = treap->SlowDelete(key);

							PrintTreap(treap->Root, 0);
							system("pause");
							break;
						}
						case '4':
						{
							if (!treap->IsCreated || treap->IsEmpty())
							{
								cout << "Tree is empty!\n";
								break;
							}
							cout << "Enter key of the value: ";
							int key = GetNumber();
							cout << "\n";
							if (treap->FastDelete(treap->Root, nullptr, key) == false)
							{
								cout << "No such element exists!\n\n";
							}
							PrintTreap(treap->Root, 0);
							system("pause");
							break;
						}
						case '5':
						{
							if (!treap->IsCreated || treap->IsEmpty())
							{
								cout << "Tree is empty!\n";
								break;
							}
							cout << "Enter key of the value: ";
							int key = GetNumber();
							TreapNode* node = treap->Find(treap->Root, key);
							if (node == nullptr)
							{
								cout << "No such element exists!\n";
							}
							else
							{
								cout << "Found element, key = " << node->data << "| Priority = " << node->Priority << ".\n";
							}
							system("pause");
							break;
						}
						case '6':
						{
							if (!treap->IsCreated || treap->IsEmpty())
							{
								break;
							}
							treap->Clear(treap->Root);
							treap->IsCreated = false;
							break;
						}
						case '7':
						{
							if (!treap->IsCreated || treap->IsEmpty())
							{
								cout << "Tree is empty!\n";
								break;
							}
							cout << "\n";
							PrintTreap(treap->Root, 0);
							system("pause");
							break;
						}
						case '0':
						{
							back = true;
							break;
						}
					}
				}
				break;
			}
			case '0':
			{
				return 0;
			}
		}
	}while (activeKey != 27);
	return 0;
}
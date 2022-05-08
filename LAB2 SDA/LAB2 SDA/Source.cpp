#include <ctime>
#include "Header.h"
#include "List.h"
#include "Check.h"

int main()
{
	bool isNotCreated = false;
	bool isEmpty = true;
	int element = -1;
	//Количество элементов в двусвязном списке
	int length = 0;
	Node* newNode = new Node;
	List list;
	while (true)
	{
		system("cls");
		if (isNotCreated)
		{
			newNode = new Node;
			isNotCreated = false;
		}
		if (isEmpty)
		{
			cout << "No value\n\n";
		}
		else
		{
			newNode = list.pHead;
			for (int i = 1; i <= length; i++)
			{
				cout << "ID: " << i << " | Value: " << newNode->data << endl << endl;
				// переход к следующему узлу
				newNode = newNode->pNext;
			}
			newNode = list.pHead;
		}
		int number = -1;
		menu();
		Check(number);
		switch (number)
		{
			case 0:
			{
				cout << "Exiting the program ...\n";
				if (isEmpty)
				{
					return 0;
				}
				Node* temp;
				while (newNode->pNext != nullptr)
				{
					temp = newNode;
					newNode = newNode->pNext;
					delete temp;
				}
				delete newNode;
				return 0;
			}
			//Добавление в начало
			case 1:
			{
				cout << "Enter the element you want to add:\n";
				Check(element);
				if (isEmpty)
				{
					isEmpty = false;
					newNode->data = element;
					list.pHead = newNode;
					list.pTail = newNode;
					length++;
					break;
				}
				list.AddHead(element);
				newNode = list.pHead;
				length++;
				break;
			}
			//Добавление в конец
			case 2:
			{
				cout << "Enter the element you want to add:\n";
				Check(element);
				if (isEmpty)
				{
					isEmpty = false;
					newNode->data = element;
					list.pHead = newNode;
					list.pTail = newNode;
					length++;
					break;
				}
				list.AddTail(element);
				newNode = list.pHead;
				length++;
				break;
			}
			//Добавление после определенного элемента
			case 3:
			{
				cout << "Enter the element you want to add:\n";
				Check(element);
				if (isEmpty)
				{
					isEmpty = false;
					newNode->data = element;
					list.pHead = newNode;
					list.pTail = newNode;
					length++;
					break;
				}
				int index = 0;
				while ((index < 1) || (index > length))
				{
					cout << "Enter the ID of the item after which you want to add a value:\n";
					Check(index);
				}
				if (index == length)
				{
					list.AddTail(element);
					newNode = list.pHead;
					length++;
					break;
				}
				list.AddAfter(element, index);
				newNode = list.pHead;
				length++;
				break;
			}
			//Добавление до определенного элемента
			case 4:
			{
				cout << "Enter the element you want to add:\n";
				Check(element);
				if (isEmpty)
				{
					isEmpty = false;
					newNode->data = element;
					list.pHead = newNode;
					list.pTail = newNode;
					length++;
					break;
				}
				//Начинаются индексы в списке с 1, поэтому равно 0
				int index = 0;
				newNode = list.pHead;
				while ((index < 1) || (index > length))
				{
					cout << "Enter the ID of the element to which you want to add a value:\n";
					Check(index);
				}
				//Для добавление до первого элемента. Смещение головы
				if (index == 1)
				{
					list.AddHead(element);
					newNode = list.pHead;
					length++;
					break;
				}
				list.AddBefore(element, index);
				newNode = list.pHead;
				length++;
				break;
			}
			//Удаление элемента
			case 5:
			{
				if (isEmpty)
				{
					cout << "\nERROR!\nNothing to delete.\n";
					system("pause");
					break;
				}
				bool isNotCorrect = true;
				int choice = -1;
				while (isNotCorrect)
				{
					cout << "\nEnter the ID of element to delete:\n";
					Check(choice);
					//Выбранный ID должен соответствовать диапазону от первого до последнего
					if ((choice >= 1) && (choice <= length))
					{
						isNotCorrect = false;
					}
					else
					{
						cout << "This ID of element does not exist!\n";
					}
				}
				//Если единственный элемент
				if (length == 1)
				{
					isNotCreated = true;
					isEmpty = true;
					delete newNode;
					length--;
					break;
				}
				//Если выбран элемент между 1 и последним
				if ((choice > 1) && (choice < length))
				{
					list.DeleteElement(choice);
					length--;
					break;
				}
				//Если выбран первый элемент
				if (choice == 1)
				{
					list.DeleteHead();
					newNode = list.pHead;
					length--;
					break;
				}
				//Если выбран последний элемент
				if (choice == length)
				{
					list.DeleteTail();
					newNode = list.pHead;
					length--;
					break;
				}
			}
			//Линейный поиск
			case 6:
			{
				if (isEmpty)
				{
					cout << "\nERROR!\nNo values.\n";
					system("pause");
					break;
				}
				cout << "Enter a value to search:\n";
				Check(element);
				cout << "\nFound data:\n";
				while (newNode->pNext != nullptr)
				{
					if (newNode->data == element)
					{
						cout << "Value: " << newNode->data << endl;
					}
					newNode = newNode->pNext;
				}
				if (list.pTail->data == element)
				{
					cout << "Value: " << newNode->data << endl;
				}
				newNode = list.pHead;
				system("pause");
				break;
			}
			//Сортировка
			case 7:
			{
				if (isEmpty)
				{
					cout << "\nERROR!\nNo values.\n";
					system("pause");
					break;
				}
				if ((newNode->pNext == nullptr) && (newNode->pPrev == nullptr))
				{
					cout << "In a double linked list only 1 element." << endl;
					system("pause");
					break;
				}
				element = 0;
				Node* temp;
				Node* moreTemp;
				temp = list.pTail;
				while (true)
				{
					cout << "Choose a sort method:\n";
					cout << "|1) Sort ascending |\n";
					cout << "|2) Sort descending|\n";
					Check(element);
					if (element == 1)
					{
						for (int i = 1; i < length; i++)
						{
							while (newNode->pNext != nullptr)
							{
								moreTemp = newNode->pNext;
								if (newNode->data > moreTemp->data)
								{
									element = newNode->data;
									newNode->data = moreTemp->data;
									moreTemp->data = element;
								}
								newNode = newNode->pNext;
							}
							while (newNode->pPrev != nullptr)
							{
								newNode = newNode->pPrev;
							}
							list.pHead = newNode;
							while (newNode->pNext != nullptr)
							{
								newNode = newNode->pNext;
							}
							list.pTail = newNode;
							newNode = list.pHead;
						}
						break;
					}
					if (element == 2)
					{
						for (int i = 1; i < length; i++)
						{
							while (newNode->pNext != nullptr)
							{
								moreTemp = newNode->pNext;
								if (newNode->data < moreTemp->data)
								{
									element = newNode->data;
									newNode->data = moreTemp->data;
									moreTemp->data = element;
								}
								newNode = newNode->pNext;
							}
							while (newNode->pPrev != nullptr)
							{
								newNode = newNode->pPrev;
							}
							list.pHead = newNode;
							while (newNode->pNext != nullptr)
							{
								newNode = newNode->pNext;
							}
							list.pTail = newNode;
							newNode = list.pHead;
						}
						break;
					}
					cout << "You entered incorrect data.\n";
				}
				break;
			}
		}
	}
}
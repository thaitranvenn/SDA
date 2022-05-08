#include <iostream>
#include <string>
#include "Node.h"
#include "HashTable.h"
#include "List.h"
#include "Check.h"
#include "Dictionary.h"
#include "print.h"

using namespace std;

int main()
{
	int number = -1;
	int sizeOfTable = 5;
	Dictionary dictionary;
	dictionary.Table = CreateHashTable(sizeOfTable);
	string key;
	string value;
	HashTable* sampleTable = CreateHashTable(sizeOfTable);
	Node* temp;
	while (true)
	{
		system("cls");
		cout << "Menu:\n";
		cout << "|0| Exit.\n";
		cout << "|1| Hash Table.\n";
		cout << "|2| Dictionary and hash table.\n";
		cout << "Your choose:\n";
		Check(number);
		switch (number)
		{
			case 0:
			{
				DeleteTable(sampleTable);
				DeleteTableList(dictionary.Table);
				DeleteTable(dictionary.Table);
				return 0;
			}
			case 1:
			{
				bool back = false;
				while (!back)
				{
					system("cls");
					PrintTable(sampleTable);
					cout << endl;
					cout << endl << "Menu:" << endl;
					cout << "|0| Exit\n";
					cout << "|1| Add an element (key, value)\n";
					cout << "|2| Search by key\n";
					cout << "|3| Delete by key\n";
					Check(number);
					switch (number)
					{
						case 0:
						{
							back = true;
							break;
						}
						// Добавления (key, value)
						case 1:
						{
							cout << "Enter key:\n";
							cin >> key;
							cout << "Enter value:\n";
							cin >> value;
							sampleTable = ReHash(sampleTable);
							AddElementHashTable(sampleTable, key, value);
							break;
						}
						// Пойск по ключу
						case 2:
						{
							cout << "Enter key:\n";
							cin >> key;
							temp = Search(key, sampleTable);
							if (temp != nullptr)
							{
								cout << "The value found: \n";
								cout << temp->Value << " \n";
							}
							else
							{
								cout << "Try again!\n";
							}
							system("pause");
							break;
						}
						//Удаление по ключу
						case 3:
						{
							cout << "Enter key:\n";
							cin >> key;
							DeleteElementHashTable(sampleTable, key);
							break;
						}
					}
				}
				break;
			}
			case 2:
			{
				bool back = false;
				while (!back)
				{
					system("cls");
					PrintTable(dictionary.Table);
					PrintDictionary(&dictionary);
					cout << endl;
					cout << "Menu:\n";
					cout << "|0| Exit\n";
					cout << "|1| Add an element\n";
					cout << "|2| Search by key\n";
					cout << "|3| Delete by key\n";
					Check(number);
					switch (number)
					{
						case 0:
						{
							back = true;
							break;
						}
						// Добавления
						case 1:
						{
							cout << "Enter key:\n";
							cin >> key;
							cout << "Enter value:\n";
							cin >> value;
							dictionary.Table = ReHash(dictionary.Table);
							if (!AddNewPhrase(&dictionary, key, value))
							{
								cout << "This key is already in the dictionary!\n";
								system("pause");
							}
							break;
						}
						// Пойск по ключу
						case 2:
						{
							cout << "Enter key\n";
							cin >> key;
							temp = Search(key, dictionary.Table);
							if (temp != nullptr)
							{
								cout << "The value found: \n";
								cout << temp->Value << " \n";
							}
							else
							{
								cout << "Try again!\n";
							}
							system("pause");
							break;
						}
						//Удаление по ключу
						case 3:
						{
							cout << "Enter key:\n";
							cin >> key;
							DeletePhrase(&dictionary, key);
							break;
						}
					}
				}
				break;
			}
		}
	}
}
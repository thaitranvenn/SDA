#include <iostream>
#include "HashTable.h"
#include "dictionary.h"

using namespace std;

// таблица печати
void PrintTable(HashTable* table)
{
	Node* temp;
	cout << "Hash table:" << endl;
	for (int i = 0; i < table->Capacity; i++)
	{
		temp = table->List[i].Head;
		if (temp != nullptr)
		{
			while (temp != nullptr)
			{
				if (temp->Key.length() != 0 && temp->Value.length() != 0)
				{
					cout << temp->Key << " " << temp->Value << " " << endl;
				}
				temp = temp->NextNode;
			}
		}
		else
		{
			cout << "Cell is empty!" << endl;
		}
		cout << "__________________________________________" << endl;
	}
}

// Распечатать словарь
void PrintDictionary(Dictionary* dictionary)
{
	Node* temp;
	int dictionar = 0;
	cout << "\nDictionary:" << endl;
	for (int i = 0; i < dictionary->Table->Capacity; i++)
	{
		temp = dictionary->Table->List[i].Head;

		if (temp != nullptr)
		{
			while (temp != nullptr)
			{
				cout << temp->Key << " " << temp->Value << " ";
				temp = temp->NextNode;
			}
			cout << endl;
			dictionar++;
		}
	}
	if (dictionar == 0)
	{
		cout << endl << "Dictionary is empty!" << endl;
	}
}
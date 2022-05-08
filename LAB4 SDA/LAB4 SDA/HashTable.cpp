#include "HashTable.h"
#include "Dictionary.h"
#include "List.h"

// поиск данных
Node* Search(string key, HashTable* table)
{
	List* list = &table->List[HashFunction(key, table->Capacity)];
	Node* temp = list->Head;
	if (list->Length != 0)
	{
		while (temp != nullptr)
		{
			if (key == temp->Key)
			{
				return(temp);
			}
			else
			{
				temp = temp->NextNode;
			}
		}
	}
	return(0);
}

// Создать хэш - таблицу
HashTable* CreateHashTable(int capacity)
{
	HashTable* tempHashTable = new HashTable();
	tempHashTable->Capacity = capacity;
	tempHashTable->List = new List[capacity];
	tempHashTable->Number = 0;
	return(tempHashTable);
}

// удалить список таблиц
void DeleteTableList(HashTable* table)
{
	delete[] table->List;
}

// удалить таблицу
void DeleteTable(HashTable* table)
{
	delete[] table;
}

// перехеширование
HashTable* ReHash(HashTable* table)
{
	int number = 0;
	for (int i = 0; i < table->Capacity; i++)
	{
		if (table->List[i].Head != nullptr)
		{
			for (int j = 0; j < table->List->Length; j++)
			{
				number++;
			}
		}
	}
	// условие увеличения ёмкости таблицы
	if (number >= table->Capacity - 2)
	{
		int newsize = table->Capacity * 1.5;
		HashTable* tempTable = CreateHashTable(newsize);
		int index = 0;
		Node* key;
		for (int i = 0; i < table->Capacity; i++)
		{
			if (table->List[i].Head != nullptr)
			{
				key = table->List[i].Head;
				while (key != nullptr)
				{
					index = HashFunction(key->Key, newsize);
					AddNewKey(&tempTable->List[index], key->Key, key->Value);
					key = key->NextNode;
				}
			}
		}
		tempTable->Capacity = newsize;
		DeleteTableList(table);
		DeleteTable(table);
		return(tempTable);
	}
	else
	{
		return(table);
	}
}

// хэш-функция
int HashFunction(string key, int capacity)
{
	int hash = 0;
	for (int i = 0; i < key.length(); i++)
	{
		hash = (hash * HASH_CONST + key[i]) % capacity;
	}
	// возврат кэш_сумма
	return (hash);
}

void AddElementHashTable(HashTable* sampleTable, string key, string value)
{
	int index;
	// вычисление индекса для записи
	index = HashFunction(key, sampleTable->Capacity);
	AddNewKey(&sampleTable->List[index], key, value);
}

void DeleteElementHashTable(HashTable* sampleTable, string key)
{
	int index = HashFunction(key, sampleTable->Capacity);
	DeleteNodeKey(&sampleTable->List[index], key);
}
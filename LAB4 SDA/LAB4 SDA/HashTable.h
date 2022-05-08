#pragma once
#include "List.h"

const int HASH_CONST = 1;

struct HashTable
{
	List* List;
	int Number;
	int Capacity;
};

HashTable* CreateHashTable(int capacity);
void AddElementHashTable(HashTable* sampleTable, string key, string value);
void DeleteElementHashTable(HashTable* sampleTable, string key);
void DeleteTableList(HashTable* table);
HashTable* ReHash(HashTable* table);
int HashFunction(string key, int capacity);
Node* Search(string key, HashTable* table);
void DeleteTable(HashTable* table);
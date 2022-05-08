#pragma once
#include"HashTable.h"

struct Dictionary
{
	HashTable* Table;
};

bool AddNewPhrase(Dictionary* dictionary, string key, string value);
void DeletePhrase(Dictionary* dictionary, string key);
#include "dictionary.h"
#include "List.h"
#include "HashTable.h"

// //Функция добавление
bool AddNewPhrase(Dictionary* dictionary, string key, string value)
{
	int index;
	index = HashFunction(key, dictionary->Table->Capacity);
	if (Trigger(&dictionary->Table->List[index], key) == false)
	{
		AddNewKey(&dictionary->Table->List[index], key, value);
		return true;
	}
	else
	{
		return(false);
	}
}

//Функция удаления
void DeletePhrase(Dictionary* dictionary, string key)
{
	int index = HashFunction(key, dictionary->Table->Capacity);
	DeleteNodeKey(&dictionary->Table->List[index], key);
}
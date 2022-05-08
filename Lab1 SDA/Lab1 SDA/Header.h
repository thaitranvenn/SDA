#pragma once

#include <iostream>

using namespace std;

struct Array
{
	// Ёмкость
	int Capacity;
	// Длина заполненности
	int Length;
	// Массив
	int* Array;
	// Создан ли массив(0 - нет, 1 - да)
	bool IsCreated;
	// Пустой - false, есть элемент - true
	bool IsNotEmpty;
};

void Show(Array* array);
void Input(Array* array);
void Creation(Array* array);
void MoreCapacity(Array*& array);
void AddHead(Array*& array, int number, int element);
void AddTail(Array*& array, int number, int element);
void AddAnyWhere(Array*& array, int number, int element);
void Delete(Array*& array, const int number);
void SortUpAscending(Array* array, int number);
void SortUpDescending(Array* array, int number);
void LinearSearch(Array* array, const int number);
void BinarySearch(Array*& array, const int temp, const int& number);
void InputInteger(int& number);
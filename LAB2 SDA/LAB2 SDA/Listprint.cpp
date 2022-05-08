#pragma once
#include "Header.h"

void Listprint(StructList* List)
{
	StructList* Temperary;
	Temperary = List;
	cout << endl;
	do
	{
		// вывод значения элемента p
		cout << "ID: " << Temperary->index << " | Value: " << Temperary->data << endl;
		// переход к следующему узлу
		Temperary = Temperary->pNext;
		// условие окончания обхода
	} while (Temperary != nullptr);
	cout << endl;
};
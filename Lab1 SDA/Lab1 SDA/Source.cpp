#include "Header.h"

void InputInteger(int& number)
{
	int i;
	bool isCorrect = false;
	while (!isCorrect)
	{
		cin >> i;
		if (cin.fail())
		{
			cin.clear();
			while (cin.get() != '\n');
			{
				cout << "Enter a valid value:" << endl;
				isCorrect = false;
			}
		}
		else
		{
			number = i;
			isCorrect = true;
		}
	}
};

//Содержимое структуры
void Show(Array* array)
{
	cout << "\n__________Currently in an array:_____________\n";
	for (int i = 0; i < array->Length; i++)
	{
		cout << "|ID: " << i + 1 << " |Value: " << array->Array[i] << "\n";
	}
	cout << "_______________________________________________\n" << endl;
};

// Ввод значений
void Input(Array* array)
{
	int choice = 0;
	while ((choice > 2) || (choice < 1))
	{
		cout << "| To enter manually - enter 1.\n";
		cout << "| To set random values - enter 2\n";
		InputInteger(choice);
	}
	if (choice == 1)
	{
		for (int i = 0; i < array->Length; i++)
		{
			cout << "\nEnter a value for |ID:" << i + 1 << ":\n";
			InputInteger(array->Array[i]);
		}
	}
	if (choice == 2)
	{
		for (int i = 0; i < array->Length; i++)
		{
			//Произвольный выбор значений.
			array->Array[i] = rand() % 50;
		}
	}
};

// Создание массива в структуре
void Creation(Array* array)
{
	array->IsCreated = true;
	array->Array = new int[array->Capacity];
};

// Больше ёмкость
void MoreCapacity(Array*& array)
{
	array->Capacity = array->Length * 2;
	int* temp = new int[array->Capacity];
	for (int i = 0; i < array->Length; i++)
	{
		temp[i] = array->Array[i];
	}
	delete array->Array;
	array->Array = temp;
};

// Вставка элемента в начало
void AddHead(Array*& array, int number, int element)
{
	for (int i = array->Length; i > 0; i--)
	{
		array->Array[i] = array->Array[i - 1];
	}
	array->Array[0] = element;
	array->Length++;
	array->IsNotEmpty = true;
};

// Вставка элемента в конец
void AddTail(Array*& array, int number, int element)
{
	array->Array[array->Length] = element;
	array->Length++;
	array->IsNotEmpty = true;
};

// Вставка после определенного элемента
void AddAnyWhere(Array*& array, int number, int element)
{
	for (int i = array->Length; i > number; i--)
	{
		array->Array[i] = array->Array[i - 1];
	}
	array->Length++;
	array->Array[number] = element;
	array->IsNotEmpty = true;
};

// Удаление элемента
void Delete(Array*& array, const int number)
{
	if ((number >= 0) && (number < array->Length - 1))
	{
		for (int i = number; i < array->Length; i++)
		{
			array->Array[i] = array->Array[i + 1];
		}
		array->Length--;
	}
	else
	{
		if (number == array->Length - 1)
		{
			array->Length--;
		}
	}

};

// Сортировка
void SortUpAscending(Array* array, int number)
{
	for (int i = 1; i < array->Length; i++)
	{
		if (array->Array[i] < array->Array[i - 1])
		{
			for (int j = i; j > 0; j--)
			{
				if (array->Array[j] < array->Array[j - 1])
				{
					array->Array[array->Capacity] = array->Array[j];
					array->Array[j] = array->Array[j - 1];
					array->Array[j - 1] = array->Array[array->Capacity];
				}
			}
		}
	}
}

// Сортировка
void SortUpDescending(Array* array, int number)
{
	for (int i = 1; i < array->Length; i++)
	{
		if (array->Array[i] > array->Array[i - 1])
		{
			for (int j = i; j > 0; j--)
			{
				if (array->Array[j] > array->Array[j - 1])
				{
					array->Array[array->Capacity] = array->Array[j];
					array->Array[j] = array->Array[j - 1];
					array->Array[j - 1] = array->Array[array->Capacity];
				}
			}
		}
	}
}

// Линейный поиск
void LinearSearch(Array* array, const int number)
{
	cout << endl << "List of values equal: " << number << "\n";
	for (int i = 0; i < array->Length; i++)
	{
		if (array->Array[i] == number)
			cout << "ID: " << i + 1 << " |Value: " << array->Array[i] << endl;
	}
	cout << endl;
	system("pause");
};

// Бинарный поиск
void BinarySearch(Array*& array, const int temp, const int& choice)
{
	int high = array->Length;
	int low = 0;
	int mid = (low + (high - low) / 2);
	int id;
	cout << "\nInformation found:\n";
	if (choice == 1)
	{
		id = -1;

		while (id == -1)
		{
			if (array->Array[mid] == temp)
			{
				id = mid;
			}
			else
			{
				if (array->Array[mid] > temp)
				{
					high = mid;
					mid = (low + (high - low) / 2);
				}
				else
				{
					low = mid;
					mid = low + (high - low) / 2;
				}
			}
		}
		cout << "ID: " << id + 1 << " | Value: " << array->Array[id] << endl;
	}
	if (choice == 2)
	{
		id = -1;
		while (id == -1)
		{
			if (array->Array[mid] == temp)
			{
				id = mid;
			}
			else
			{
				if (array->Array[mid] < temp)
				{
					high = mid;
					mid = (low + (high - low) / 2);
				}
				else
				{
					low = mid;
					mid = low + (high - low) / 2;
				}
			}

		}
		cout << "ID: " << id + 1 << " | Value: " << array->Array[id] << endl;
	}
	system("pause");
};
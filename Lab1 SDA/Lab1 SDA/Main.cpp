#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	// Для бинарного поиска. Отвечает за отсортированность массива.
	int number = 0;
	// Вставляемое значение.
	int input;
	// Структура
	Array* array = new Array[];
	// Длина заполненности массива
	array->Length = 4;
	// Ёмкость массива
	array->Capacity = 8;
	// Для того, чтобы повторно нельзя было создать массив если он создан.
	array->IsCreated = false;
	array->IsNotEmpty = false;
	while (true)
	{
		// Очистка консоли
		system("cls");
		if (array->IsNotEmpty)
		{
			Show(array);
		}
		else
		{
			cout << "There are no values in the array or it was not created.";
		}
		cout << endl;
		int number = -1;
		cout << "Program menu:\n";
		cout << "|To continue, select one of the element:\n";
		cout << "|Enter 0 to exit the program.\n";
		cout << "|Enter 1 to create an array.\n";
		cout << "|Enter 2 to add the value to the TOP.\n";
		cout << "|Enter 3 to add the value to the END.\n";
		cout << "|Enter 4 to add a value after any element.\n";
		cout << "|Enter 5 to delete the element.\n";
		cout << "|Enter 6 to sort array.\n";
		cout << "|Enter 7 to linear search.\n";
		cout << "|Enter 8 to binary search.\n";
		InputInteger(number);
		if (array->Length == 1)
		{
			number = 1;
		}
		if (array->Length == array->Capacity)
		{
			MoreCapacity(array);
		}
		switch (number)
		{
			// to exit the program
			case 0:
			{
				cout << "Exiting the program ...\nThanks for using this program.";
				system("pause");
				return 0;
			}
			// Функция создания и инициализации полей массива (length, capacity, array)
			case 1:
			{
				if (!array->IsCreated)
				{
					Creation(array);
					array->IsNotEmpty = true;
					Input(array);
					Show(array);
					for (int i = 1; i < array->Length; i++)
					{
						if (array->Array[i] >= array->Array[i - 1])
						{
							number = 1;
						}
						else
						{
							number = 0;
							break;
						}
					}
					for (int i = 1; i < array->Length; i++)
					{
						if (number == 1)
						{
							break;
						}
						if (array->Array[i] <= array->Array[i - 1])
						{
							number = 2;
						}
						else
						{
							number = 0;
							break;
						}
					}
				}
				else
				{
					cout << "MISTAKE! You have already created an array of values!\n";
				}
				system("pause");
				break;
			}
			// Вставка элемента в начало
			case 2:
			{
				if (!array->IsCreated)
				{
					cout << "\nMISTAKE! Create or fill an array!";
					system("pause");
				}
				else
				{
					cout << "\nYou have selected an insert at the beginning.\n";
					cout << "Enter the value you want to add: \n";
					InputInteger(input);
					AddHead(array, 0, input);
					Show(array);
				}
				break;
			}
			// Вставка элемента в конец
			case 3:
			{
				if (!array->IsCreated)
				{
					cout << "\nMISTAKE! Create or fill an array!";
					system("pause");
				}
				else
				{
					cout << "\nYou have selected an insert at the end.\n";
					cout << "Enter the value you want to insert:\n";
					InputInteger(input);
					AddTail(array, 0, input);
					Show(array);
				}
				break;
			}
			// Вставка после определенного элемента
			case 4:
			{
				if (!array->IsCreated)
				{
					cout << "\nMISTAKE! Create or fill an array!";
					system("pause");
				}
				else
				{
					int number = -1;
					int choice = 0;
					if (array->IsNotEmpty)
					{
						cout << "\nYou have chosen to insert after a specific item.\n";
						cout << "Enter the value you want to add:\n";
						InputInteger(input);
						while (choice != 1)
						{
							while ((number < 1) || (number > array->Length))
							{
								cout << "\nSelect the ID of the element after which you want to insert:\n";
								InputInteger(number);
							}
							number--;
							if ((number >= 0) && (number < array->Length))
							{
								cout << "Do you want to insert a value after this element?:\n";
								cout << "ID: " << number + 1 << " |Value: " << array->Array[number];
								cout << "\n1 - Yes; 2 - No;\n";
								InputInteger(choice);
								while ((choice < 1) || (choice > 2))
								{
									if (choice == 1)
									{
										break;
									}
									cout << "\n1 - Yes; 2 - No;\n";
									InputInteger(choice);
								}
							}
						}
						AddAnyWhere(array, number + 1, input);
						Show(array);
					}
					else
					{
						cout << "MISTAKE! At the moment, you can only insert a value at the BEGINNING or the END!";
						system("pause");
					}
				}
				break;
			}
			// Удаление элемента из массива
			case 5:
			{
				if (!array->IsCreated)
				{
					cout << "\nMISTAKE! Create or fill an array!";
					system("pause");
				}
				else
				{
					int number = -1;
					int choice = 0;
					cout << "\nYou have chosen to delete a specific item.\n";
					if (array->Length == 0)
					{
						cout << "MISTAKE! There are no values in the array.\n";
						system("pause");
						break;
					}
					while (choice != 1)
					{
						cout << "\nSelect the ID of the item you want to delete:\n";
						InputInteger(number);
						number--;
						if ((number >= 0) && (number < array->Length))
						{
							cout << "Do you want to delete this entry?:\n";
							cout << "ID: " << number + 1 << " |Value: " << array->Array[number];
							cout << "\n1 - Yes; 2 - No;\n";
							InputInteger(choice);
							while ((choice < 1) || (choice > 2))
							{
								if (choice == 1)
								{
									break;
								}
								cout << "\n1 - Yes; 2 - No;\n";
								InputInteger(choice);
							}
						}
					}
					Delete(array, number);
					if (array->Length == 0)
					{
						array->IsNotEmpty = false;
					}
				}
				break;
			}
			// Сортировка массива
			case 6:
			{

				if (!array->IsCreated)
				{
					cout << "\nMISTAKE! Create or fill an array!";
					system("pause");
				}
				else
				{
					if (array->IsNotEmpty)
					{
						cout << "You have selected sorting.\n";
						cout << "To sort in ascending order, enter 1.\n";
						cout << "To sort in descending order, enter 2.\n";
						InputInteger(number);
						while ((number > 2) || (number < 1))
						{
							cout << "To sort in ascending order, enter 1.\n";
							cout << "To sort in descending order, enter 2.\n";
							InputInteger(number);
						}
						if (number == 1)
						{
							SortUpAscending(array, number);
						}
						if (number == 2)
						{
							SortUpDescending(array, number);
						}
						cout << endl << "Sorted Records:\n" << endl;
						Show(array);
					}
					else
					{
						cout << "\nNo values in array.\n";
						system("pause");
					}
				}
				break;
			}
			// Линейный поиск элемента в массиве
			case 7:
			{
				if (!array->IsCreated)
				{
					cout << "\nMISTAKE! Create or fill an array!";
					system("pause");
				}
				else
				{
					if (array->IsNotEmpty)
					{
						int number = 0;
						cout << "Enter a value to search for:\n";
						InputInteger(number);
						LinearSearch(array, number);
					}
					else
					{
						cout << "\nThere are no values in the array.\n";
						system("pause");
					}
				}
				break;
			}
			// Бинарный поиск элемента в массиве
			case 8:
			{
				if (!array->IsCreated)
				{
					cout << "\nMISTAKE! Create or fill an array!";
					system("pause");
				}
				else
				{
					int choice = 0;
					int choose = -1;

					for (int i = 1; i < array->Length; i++)
					{
						if (array->Array[i] >= array->Array[i - 1])
						{
							number = 1;
						}
						else
						{
							number = 0;
							break;
						}
					}
					for (int i = 1; i < array->Length; i++)
					{
						if (number == 1)
						{
							break;
						}
						if (array->Array[i] <= array->Array[i - 1])
						{
							number = 2;
						}
						else
						{
							number = 0;
							break;
						}
					}
					if (array->IsNotEmpty)
					{
						cout << "\nEnter the search value:\n";
						InputInteger(choice);
						for (int i = 0; i < array->Length; i++)
						{
							if (array->Array[i] == choice)
							{
								choose = 0;
								break;
							}
						}
						if (number == 0)
						{
							cout << "\nMISTAKE! Sort your data first!\n\n";
							system("pause");
						}
						else
						{
							while (choose != 0)
							{
								cout << "\nMISTAKE! Enter the correct data!";
								cout << "\nEnter the search value:\n";
								InputInteger(choice);
								for (int i = 0; i < array->Length; i++)
								{
									if (array->Array[i] == choice)
									{
										choose = 0;
										break;
									}
								}
							}
							BinarySearch(array, choice, number);
						}
					}
					else
					{
						cout << "\n Missing array values.\n";
						system("pause");
					}
				}
				break;
			}
		}
	}
}
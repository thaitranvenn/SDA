#pragma once
#include <iostream>

using namespace std;

int GetNumber()
{
	bool errorNumber = false;
	char* numberChar = new char[0];
	do {
		errorNumber = false;
		while (getchar() != '\n');
		cin >> numberChar;
		for (int i = 0; i < strlen(numberChar); i++)
		{
			if (((numberChar[i] >= '0') && (numberChar[i] <= '9')) || ((numberChar[i] == '-') && (i == 0))) {}
			else
			{
				char* numberChar = new char[0];
				errorNumber = true;
				cout << "Entered the value not true\n";
				break;
			}
		}
	} while (errorNumber != false);
	int number = atoi(numberChar);
	return(number);
}
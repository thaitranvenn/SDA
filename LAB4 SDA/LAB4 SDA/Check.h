#pragma once
#include <iostream>

using namespace std;

void Check(int& number)
{
	int temp;
	bool correct = false;
	while (!correct)
	{
		cin >> temp;
		if (cin.fail())
		{
			cin.clear();
			while (cin.get() != '\n');
			{
				cout << "Enter a valid value" << endl;
				correct = false;
			}
		}
		else
		{
			number = temp;
			correct = true;
		}
	}
};
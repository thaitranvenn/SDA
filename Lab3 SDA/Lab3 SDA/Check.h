#pragma once
#include <iostream>

using namespace std;

void Check(int& number)
{
	int i;
	bool correct = false;
	while (!correct)
	{
		cin >> i;
		if (cin.fail())
		{
			cin.clear();
			while (cin.get() != '\n');
			{
				cout << "Enter a valid value:" << endl;
				correct = false;
			}
		}
		else
		{
			number = i;
			correct = true;
		}
	}
};
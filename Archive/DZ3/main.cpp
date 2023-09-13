#include <iostream>
#include "Caller.h"
using namespace std;

enum menuCodes
{
	codeAddÑaller = 1, codeDeleteÑaller, codeSearchByName, codeShowAllCallers, codeExitProgram
};
void printMenu()
{
	cout << "\tMain menu:" << endl;
	cout << "[" << codeAddÑaller << "] - Add new caller" << endl;
	cout << "[" << codeDeleteÑaller << "] - Delete caller" << endl;
	cout << "[" << codeSearchByName << "] - Search caller by name" << endl;
	cout << "[" << codeShowAllCallers << "] - Print all callers" << endl;
	cout << "[" << codeExitProgram << "] - Exit the program" << endl;
}
char* lowercase(char* str)
{
	for (int i = 0; i < str[i] != '\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
	return str;
}

Caller* addCaller(Caller* array, int& size)
{
	size++;
	Caller* newArray = new Caller[size];
	for (int i = 0; i < size - 1; i++)
	{
		newArray[i].deepCopy(array[i]);
	}
	delete[] array;
	newArray[size - 1].input();
	array = newArray;
	return array;
}
Caller* deleteCaller(Caller* array, int& size)
{
	if (size <= 0)
	{
		cout << "List is empty" << endl;
		return array;
	}

	int indexDelete = -1;
	char firstName[32];
	char lastName[32];
	char* tempFirstName;
	char* tempLastName;

	cout << "Enter first name: ";
	cin >> firstName;
	cout << "Enter last name: ";
	cin >> lastName;
	lowercase(firstName);
	lowercase(lastName);

	for (int i = 0; i < size; i++)
	{
		tempFirstName = new char[strlen(array[i].getFirstName()) + 1];
		strcpy_s(tempFirstName, strlen(array[i].getFirstName()) + 1, array[i].getFirstName());
		tempLastName = new char[strlen(array[i].getLastName()) + 1];
		strcpy_s(tempLastName, strlen(array[i].getLastName()) + 1, array[i].getLastName());
		lowercase(tempFirstName);
		lowercase(tempLastName);

		if (strcmp(firstName, tempFirstName) == 0 && strcmp(lastName, tempLastName) == 0)
		{
			indexDelete = i;
			break;
		}
	}

	if (indexDelete != -1)
	{
		char userAnswer;
		bool isConfirm = false;
		while (isConfirm == false)
		{
			cout << "Are you sure you want to remove this caller? (y/n): ";
			cin >> userAnswer;
			if (userAnswer == 'N' || userAnswer == 'n')
				return array;
			else if (userAnswer == 'Y' || userAnswer == 'y')
				isConfirm = true;
		}

		int newSize = size - 1;
		int indexNewArray = 0;
		Caller* newArray = new Caller[size];
		for (int i = 0; i < size; i++)
		{
			if (i != indexDelete)
				newArray[indexNewArray++].deepCopy(array[i]);
		}
		delete[] array;
		array = newArray;
		size = newSize;
	}
	else
		cout << "No one with that name was found" << endl;

	return array;
}
void searchCaller(Caller* array, const int size)
{
	if (size <= 0)
	{
		cout << "List is empty" << endl;
		return;
	}

	char firstName[32];
	char lastName[32];
	cout << "Enter first name: ";
	cin >> firstName;
	cout << "Enter last name: ";
	cin >> lastName;
	lowercase(firstName);
	lowercase(lastName);

	char* tempFirstName;
	char* tempLastName;

	for (int i = 0; i < size; i++)
	{
		tempFirstName = new char[strlen(array[i].getFirstName()) + 1];
		strcpy_s(tempFirstName, strlen(array[i].getFirstName()) + 1, array[i].getFirstName());
		tempLastName = new char[strlen(array[i].getLastName()) + 1];
		strcpy_s(tempLastName, strlen(array[i].getLastName()) + 1, array[i].getLastName());
		lowercase(tempFirstName);
		lowercase(tempLastName);
		if (strcmp(firstName, tempFirstName) == 0 && strcmp(lastName, tempLastName) == 0)
		{
			array[i].print();
			return;
		}
	}
	cout << "No one with that name was found" << endl;
}
void printAllCallers(Caller* array, int& size)
{
	if (size <= 0)
	{
		cout << "List is empty" << endl;
		return;
	}

	for (int i = 0; i < size; i++)
	{
		cout << "\tCaller #" << i + 1 << endl;
		array[i].print();
		cout << endl;
	}
}

int main()
{
	int arraySize = 0;
	Caller* array = new Caller[arraySize];

	int userChoice;
	bool exit = false;
	while (exit == false)
	{
		printMenu();
		cout << "\nChoose option: ";
		cin >> userChoice;
		cin.ignore(255, '\n');

		switch (userChoice)
		{
		case codeAddÑaller:
			array = addCaller(array, arraySize);
			break;
		case codeDeleteÑaller:
			array = deleteCaller(array, arraySize);
			break;
		case codeSearchByName:
			searchCaller(array, arraySize);
			break;
		case codeShowAllCallers:
			printAllCallers(array, arraySize);
			break;
		case codeExitProgram:
			cout << "Thanks for using our program! Press any button to start clear the memory." << endl;
			exit = true;
			break;
		default:
			cout << "You entered the wrong action code. Try again" << endl;
		}
		cout << endl;
		system("pause");
		system("cls");
	}
	delete[] array;
}
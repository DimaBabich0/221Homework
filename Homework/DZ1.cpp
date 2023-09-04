#include <iostream>
#include "DZ1.h"
using namespace std;

int main()
{
	int userChoice;
	bool returnToMain = false;
	while (true)
	{
		printMenuMain();

		cout << "\nChoose option: ";
		cin >> userChoice;
		cin.ignore(255, '\n');

		switch (userChoice)
		{
		case codeAddEmployee:
			addEmployee(pathEmployee);
			break;
		case codeDelEmployee:
			delEmployee(pathEmployee, pathTemp);
			break;
		case codeMenuReport:
			returnToMain = false;
			do
			{
				system("cls");
				printMenuReport();

				cout << "\nChoose option: ";
				cin >> userChoice;
				cin.ignore(255, '\n');
				cout << endl;

				switch (userChoice)
				{
				case codePrintAllEmployee:
					printAllEmployee(pathEmployee);
					break;
				case codePrintInfoEmployee:
					printInfoEmployee(pathEmployee);
					break;
				case codeExitReport:
					cout << "Returning to main menu...";
					returnToMain = true;
					break;
				default:
					cout << "You entered the wrong action code. Try again" << endl;
					break;
				}
				if (!returnToMain)
					system("pause");
			} while (!returnToMain);
			break;
		case codeExitProgram:
			cout << "Thanks for using our program!" << endl;
			return 0;
		default:
			cout << "You entered the wrong action code. Try again" << endl;
		}
		cout << endl;
		system("pause");
		system("cls");
	}
}

void printInfoStruct(Employee point)
{
	printf("Full name: %s %s\n", point.firstName, point.lastName);
	printf("Phone number: %s\n", point.phoneNumber);
	printf("Salary: %f\n", point.salary);
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

void addEmployee(const char pathEmployee[])
{
	FILE* file;
	errno_t code = fopen_s(&file, pathEmployee, "ab");
	if (code == 0)
	{
		Employee point;
		cout << "First name: ";
		cin >> point.firstName;
		cout << "Last name: ";
		cin >> point.lastName;
		cout << "Phone number: ";
		cin >> point.phoneNumber;
		cout << "Salary: ";
		cin >> point.salary;
		fwrite(&point, sizeof(Employee), 1, file);
		fclose(file);
	}
	else
		cout << "Error. Code: " << code << endl;
}
void delEmployee(const char pathEmployee[], const char pathTemp[])
{
	FILE* file;
	FILE* temp;
	bool isFind = false;

	errno_t fileCode = fopen_s(&file, pathEmployee, "rb");
	errno_t tempCode = fopen_s(&temp, pathTemp, "wb");

	if (fileCode == 0 && tempCode == 0)
	{
		char firstName[SIZE_STR];
		char lastName[SIZE_STR];
		cout << "First name: ";
		cin >> firstName;
		cout << "Last name: ";
		cin >> lastName;

		lowercase(firstName);
		lowercase(lastName);

		Employee point;
		while (!feof(file))
		{
			if (fread(&point, sizeof(Employee), 1, file))
			{
				Employee pointTemp = point;
				if (strcmp(firstName, lowercase(pointTemp.firstName)) != 0 && strcmp(lastName, lowercase(pointTemp.lastName)) != 0)
					fwrite(&point, sizeof(Employee), 1, temp);
				else
					isFind = true;
			}
		}
		fclose(file);
		fclose(temp);
	}

	if (isFind)
	{
		fileCode = fopen_s(&file, pathEmployee, "wb");
		tempCode = fopen_s(&temp, pathTemp, "rb");
		if (fileCode == 0 && tempCode == 0)
		{
			Employee point;

			while (!feof(temp))
			{
				if (fread(&point, sizeof(Employee), 1, temp))
					fwrite(&point, sizeof(Employee), 1, file);
			}

			fclose(file);
			fclose(temp);

			cout << "Employee was removed from the list" << endl;
		}
	}
	else
		cout << "Employee was not found in the list" << endl;
}

void printAllEmployee(const char pathEmployee[])
{
	FILE* file;
	errno_t code = fopen_s(&file, pathEmployee, "rb");
	if (code == 0)
	{
		Employee point;
		int counter = 1;
		while (!feof(file))
		{
			if (fread(&point, sizeof(Employee), 1, file))
			{
				printf("\tEmployee #%d\n", counter++);
				printInfoStruct(point);
			}
		}
		fclose(file);
	}
	else
		cout << "Error. Code: " << code << endl;
}
void printInfoEmployee(const char pathEmployee[])
{
	FILE* file;
	errno_t code = fopen_s(&file, pathEmployee, "rb");
	if (code == 0)
	{
		bool isFind = false;
		char lastName[SIZE_STR];
		cout << "Type last name employee: ";
		cin >> lastName;
		lowercase(lastName);

		Employee point;
		while (!feof(file))
		{
			if (fread(&point, sizeof(Employee), 1, file))
			{
				Employee pointTemp = point;
				if (strcmp(lastName, lowercase(pointTemp.lastName)) == 0)
				{
					printInfoStruct(point);
					isFind = true;
				}
			}
		}

		if (!isFind)
		{
			cout << "Not found" << endl;
		}

		fclose(file);
	}
	else
		cout << "Error. Code: " << code << endl;
}

void printMenuMain()
{
	cout << "\tMain menu:" << endl;
	cout << "[" << codeAddEmployee << "] - Add new employee" << endl;
	cout << "[" << codeDelEmployee << "] - Delete employee" << endl;
	cout << "[" << codeMenuReport << "] - Open report menu" << endl;
	cout << "[" << codeExitProgram << "] - Exit the program" << endl;
}
void printMenuReport()
{
	cout << "\tReport options:" << endl;
	cout << "[" << codePrintAllEmployee << "] - Print full list of employee" << endl;
	cout << "[" << codePrintInfoEmployee << "] - Print information about the employee" << endl;
	cout << "[" << codeExitReport << "] - Go back to main menu" << endl;
}
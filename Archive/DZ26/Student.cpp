#include "Student.h"
#include "Human.h"
#include "University.h"

Student::Student()
{
	Human::Human();
	University::University();
	groupName = "empty";
	arrSize = NULL;
	arrGrades = nullptr;
}
Student::~Student()
{
	delete[] arrGrades;
}

void Student::Print()
{
	cout << "\tHuman:" << endl;
	cout << "Name: " << Human::name << endl;
	cout << "Age: " << Human::age << endl;

	cout << "\tUniversity:" << endl;
	cout << "Name: " << University::name << endl;
	cout << "Adress: " << University::adress << endl;
	cout << "Faculty: " << University::faculty << endl;

	cout << "\tStudent:" << endl;
	cout << "Group name: " << groupName << endl;
	if (arrSize <= 0)
		cout << "Array of grades is empty" << endl;
	else
	{
		cout << "Array of grades [" << arrSize << "]:" << endl;
		for (int i = 0; i < arrSize; i++)
			cout << arrGrades[i] << " ";
	}
}
void Student::Input()
{
	cout << "\tHuman:" << endl;
	Human::Input();
	cout << "\tUniversity:" << endl;
	University::Input();

	cout << "\tStudent:" << endl;
	cout << "Group name: ";
	cin >> groupName;
	cout << "Enter the number of grades: ";
	cin >> arrSize;
	arrGrades = new int[arrSize];
	for (int i = 0; i < arrSize; i++)
	{
		cout << "Enter grade [" << i + 1 << "]: ";
		cin >> arrGrades[i];
	}
}
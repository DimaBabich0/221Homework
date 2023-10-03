#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
	string Name;
	int Age;
public:
	Person() : Name("empty"), Age(NULL) {}
	Person(const char* u_Name, int u_Age) : Name(u_Name), Age(u_Age)
	{}

	void Print()
	{
		cout << "Name: " << Name << endl;
		cout << "Age: " << Age << endl;
	}
	void Input()
	{
		cout << "Enter name: ";
		cin >> Name;

		cout << "Enter age: ";
		cin >> Age;
		cin.ignore(255, '\n');
	}
};

class Student: public Person
{
private:
	string University;
public:
	Student() : Person(), University("empty") {}
	Student(const char* u_Name, int u_Age, const char* u_Univer) : Person(u_Name, u_Age), University(u_Univer) {}

	void Print()
	{
		Person::Print();
		cout << "University: " << University << endl;
	}
	void Input()
	{
		Person::Input();
		cout << "Enter university: ";
		cin >> University;
	}
	void Input(const char* u_Univer)
	{
		University = u_Univer;
	}
};
class Teacher : public Person
{
private:
	string School;
	double Salary;
	int ArrSize;
	string* SchoolSubjects;
public:
	Teacher() : Person(), School("empty"), Salary(NULL), ArrSize(NULL), SchoolSubjects(nullptr) {}
	Teacher(const char* u_Name, int u_Age, const char* u_School, double u_Salary, int u_ArrSize, const char* u_SSubjects[]) : Person(u_Name, u_Age)
	{
		School = u_School;
		Salary = u_Salary;
		ArrSize = u_ArrSize;
		SchoolSubjects = new string[ArrSize];
		for (int i = 0; i < ArrSize; i++)
			SchoolSubjects[i] = u_SSubjects[i];
	}
	~Teacher() 
	{ 
		delete[] SchoolSubjects;
	}

	void Print()
	{
		Person::Print();
		cout << "School: " << School << endl;
		cout << "Salary: " << Salary << endl;
		if (ArrSize <= 0)
			cout << "There are no school subjects" << endl;
		else 
		{
			cout << "School subjects [" << ArrSize << "]:" << endl;
			for (int i = 0; i < ArrSize; i++)
				cout << i + 1 << ". " << SchoolSubjects[i] << endl;
		}
	}
	void Input()
	{
		Person::Input();
		cout << "Enter school: ";
		cin >> School;

		cout << "Enter salary: ";
		cin >> Salary;
		cin.ignore(255, '\n');

		cout << "Enter the number of school subjects: ";
		cin >> ArrSize;
		cin.ignore(255, '\n');

		delete[] SchoolSubjects;
		SchoolSubjects = new string[ArrSize];
		for (int i = 0; i < ArrSize; i++)
		{
			cout << "Enter the name of " << i + 1 << " subject: ";
			cin >> SchoolSubjects[i];
		}
	}
	void Input(const char* u_School, double u_Salary, int u_ArrSize, const char* u_SSubjects[])
	{
		School = u_School;
		Salary = u_Salary;
		ArrSize = u_ArrSize;

		delete[] SchoolSubjects;
		SchoolSubjects = new string[ArrSize];
		for (int i = 0; i < ArrSize; i++)
			SchoolSubjects[i] = u_SSubjects[i];
	}

};
class Driver : public Person
{
private:
	string CarNumber;
	string SeriesNumber;
	string LicenseNumber;
public:
	Driver() : Person(), CarNumber("empty"), SeriesNumber("empty"), LicenseNumber("empty") {}
	Driver(const char* u_Name, int u_Age, const char* u_CNumber, const char* u_SNumber, const char* u_LNumber) : Person(u_Name, u_Age)
	{
		CarNumber = u_CNumber;
		SeriesNumber = u_SNumber;
		LicenseNumber = u_LNumber;
	}

	void Print()
	{
		Person::Print();
		cout << "Car number: " << CarNumber << endl;
		cout << "Series number: " << SeriesNumber << endl;
		cout << "License number: " << LicenseNumber << endl;
	}
	void Input()
	{
		Person::Input();
		cout << "Enter car number: ";
		cin >> CarNumber;

		cout << "Enter license number: ";
		cin >> LicenseNumber;
	}
	void Input(const char* u_CNumber, const char* u_LNumber)
	{
		CarNumber = u_CNumber;
		LicenseNumber = u_LNumber;
	}
};
class Doctor : public Person
{
private:
	string Specialty;
	int WorkExperience;
	bool isFamilyDoctor;
public:
	Doctor() : Person(), Specialty("empty"), WorkExperience(NULL), isFamilyDoctor(NULL)
	{}
	Doctor(const char* u_Name, int u_Age, const char* u_Specialty, int u_WExperience, bool isFDoctor) : Person(u_Name, u_Age)
	{
		Specialty = u_Specialty;
		WorkExperience = u_WExperience;
		isFamilyDoctor = isFDoctor;
	}

	void Print()
	{
		Person::Print();
		cout << "Specialty: " << Specialty << endl;
		cout << "Work experience: " << WorkExperience  << " years" << endl;
		cout << "Is family doctor: ";
		if (isFamilyDoctor)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	void Input()
	{
		Person::Input();
		cout << "Enter specialty: ";
		cin >> Specialty;

		cout << "Enter work experience: ";
		cin >> WorkExperience;
		cin.ignore(255, '\n');

		cout << "Is family doctor (1 - yes, 0 - no): ";
		cin >> isFamilyDoctor;
	}
	void Input(const char* u_Specialty, int u_WExperience, bool isFDoctor)
	{
		Specialty = u_Specialty;
		WorkExperience = u_WExperience;
		isFamilyDoctor = isFDoctor;
	}
};

int main()
{
	Student pStudent("Oleg", 18, "STEP");
	pStudent.Print();
	cout << endl;

	pStudent.Input("Politex");
	pStudent.Print();
	system("pause");
	system("cls");

	const int sizeArr = 3;
	const char* subjects[sizeArr] = { "Mathematics", "History", "Programming" };
	Teacher pTeacher("Dima", 20, "#221", 11000.5, sizeArr, subjects);
	pTeacher.Print();
	system("pause");
	system("cls");

	Driver pDriver("Maks", 19, "BH 1946", "AA", "BYA 000254");
	pDriver.Print();
	system("pause");
	system("cls");

	Doctor pDoctor;
	pDoctor.Input();
	cout << endl;
	pDoctor.Print();
}
#include <iostream>
using namespace std;

const int SIZE_PHONE = 11;
class Caller
{
private:
	char* firstName;
	char* lastName;
	int age;
	char* email;
	char workPhone[SIZE_PHONE];
	char mobilePhone[SIZE_PHONE];

	void deleteNullPtr(char* pointer)
	{
		if (pointer != nullptr)
			delete[] pointer;
	}
	void coutVariable(char* variable)
	{
		if (variable == nullptr)
			cout << "empty" << endl;
		else
			cout << variable << endl;
	}
public:
	Caller()
	{
		cout << "Constructor by default" << endl;
		firstName = nullptr;
		lastName = nullptr;
		age = NULL;
		email = nullptr;

		strcpy_s(workPhone, SIZE_PHONE, "empty");
		strcpy_s(mobilePhone, SIZE_PHONE, "empty");
	}
	Caller(const char* userFirstName, const char* userLastName, int userAge, const char* userEmail, const char userWorkPhone[], const char userMobilePhone[])
	{
		cout << "Constructor by 6 parametrs" << endl;
		firstName = new char[strlen(userFirstName) + 1];
		strcpy_s(firstName, strlen(userFirstName) + 1, userFirstName);

		lastName = new char[strlen(userLastName) + 1];
		strcpy_s(lastName, strlen(userLastName) + 1, userLastName);

		age = userAge;

		email = new char[strlen(userEmail) + 1];
		strcpy_s(email, strlen(userEmail) + 1, userEmail);

		strcpy_s(workPhone, SIZE_PHONE, userWorkPhone);
		strcpy_s(mobilePhone, SIZE_PHONE, userMobilePhone);
	}
	~Caller()
	{
		cout << "Destructor" << endl;
		delete[] firstName;
		delete[] lastName;
		delete[] email;
	}

	void input()
	{
		char buff[30];

		deleteNullPtr(firstName);
		deleteNullPtr(lastName);
		deleteNullPtr(email);

		cout << "Enter first name: ";
		cin >> buff;
		firstName = new char[strlen(buff) + 1];
		strcpy_s(firstName, strlen(buff) + 1, buff);

		cout << "Enter last name: ";
		cin >> buff;
		lastName = new char[strlen(buff) + 1];
		strcpy_s(lastName, strlen(buff) + 1, buff);

		cout << "Enter age: ";
		cin >> age;

		cout << "Enter email: ";
		cin >> buff;
		email = new char[strlen(buff) + 1];
		strcpy_s(email, strlen(buff) + 1, buff);

		bool correctInput = false;
		while (correctInput == false)
		{
			cout << "Enter work phone: ";
			cin >> workPhone;
			if (strlen(workPhone) != 10)
				cout << "Incorrect phone number input. Try again. (Example: 0635635904)" << endl;
			else
				correctInput = true;
		}

		correctInput = false;
		while (correctInput == false)
		{
			cout << "Enter mobile phone: ";
			cin >> mobilePhone;
			if (strlen(mobilePhone) != 10)
				cout << "Incorrect phone number input. Try again. (Example: 0635635904)" << endl;
			else
				correctInput = true;
		}
	}
	void print()
	{
		cout << "First name: ";
		coutVariable(firstName);

		cout << "Last name: ";
		coutVariable(lastName);

		cout << "Email: ";
		coutVariable(email);

		cout << "Age: " << age << endl;
		cout << "Work phone: " << workPhone << endl;
		cout << "Mobile phone: " << mobilePhone << endl;
	}
};

int main()
{

}
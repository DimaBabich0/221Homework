#include "Main.h"

int main()
{
	Transport* object = nullptr;
	bool isExit = false;
	int userChoice;

	ChangeType(object);
	system("pause");
	system("cls");

	while (!isExit)
	{
		PrintMenu();
		cout << "Choose action: ";
		cin >> userChoice;
		cout << endl;

		switch (userChoice)
		{
		case codeChangeType:
			ChangeType(object);
			break;
		case codeInputObject:
			object->Input();
			break;
		case codePrintObject:
			object->Print();
			break;
		case codeExitProgram:
			cout << "Thanks for using our program!" << endl;
			isExit = true;
			break;
		default:
			cout << "Wrong code. Try again" << endl;
		}

		cout << endl;
		system("pause");
		system("cls");
	}

	delete object;
}
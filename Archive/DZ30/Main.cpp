#include <iostream>
#include <map>
using namespace std;

typedef pair<string, string> myPair;
enum actionsCodeMain
{
	codeAddElement = 1, codeDelElement, codePrintElements, codeChangeElement, codeSearchElement, codeExitProgram
};
void PrintMenu();

myPair EnterPair();
string EnterWord();

void DeleteElement(map<string, string>& arr);
void PrintElements(const map<string, string> arr);
void ChangeElement(map<string, string>& arr);
void SearchElement(const map<string, string> arr);

int main()
{
	map<string, string>dictionary;
	int userChoice;
	bool isExit = false;

	while (!isExit)
	{
		PrintMenu();
		cout << "\nChoose option: ";
		cin >> userChoice;
		cin.ignore(255, '\n');

		switch (userChoice)
		{
		case codeAddElement:
			dictionary.insert(EnterPair());
			break;
		case codeDelElement:
			DeleteElement(dictionary);
			break;
		case codePrintElements:
			PrintElements(dictionary);
			break;
		case codeChangeElement:
			ChangeElement(dictionary);
			break;
		case codeSearchElement:
			SearchElement(dictionary);
			break;
		case codeExitProgram:
			cout << "Thanks for using our program!" << endl;
			isExit = true;
			break;
		default:
			cout << "\nYou entered the wrong action code. Try again";
		}
		cout << endl;
		system("pause");
		system("cls");
	}
}

void PrintMenu()
{
	cout << "\tMenu:" << endl;
	cout << "[" << codeAddElement << "] - Add new word" << endl;
	cout << "[" << codeDelElement << "] - Delete word" << endl;
	cout << "[" << codePrintElements << "] - Print words" << endl;
	cout << "[" << codeChangeElement << "] - Change word" << endl;
	cout << "[" << codeSearchElement << "] - Search word" << endl;
	cout << "[" << codeExitProgram << "] - Exit the program" << endl;
}
myPair EnterPair()
{
	string key, value;
	cout << "Enter word: ";
	cin >> key;
	cout << "Enter the translation of the word: ";
	cin >> value;
	return myPair(key, value);
}
string EnterWord()
{
	string word;
	cout << "Enter the word you are looking for: ";
	cin >> word;
	return word;
}
void DeleteElement(map<string, string>& arr)
{
	bool isFind = false;
	for (auto ptr = arr.find(EnterWord()); ptr != arr.end();)
	{
		arr.erase(ptr);
		cout << "Word has been removed from the dictionary" << endl;
		isFind = true;
		break;
	}
	if (!isFind)
		cout << "There is no such word" << endl;
}
void PrintElements(const map<string, string> arr)
{
	for (auto ptr = arr.begin(); ptr != arr.end(); ptr++)
		cout << ptr->first << " - " << ptr->second << endl;
}
void ChangeElement(map<string, string>& arr)
{
	bool isFind = false;
	string seachWord = EnterWord();
	for (auto ptr = arr.find(seachWord); ptr != arr.end();)
	{
		arr.erase(ptr);

		string newValue;
		cout << "Enter new translated word: ";
		cin >> newValue;

		myPair temp(seachWord, newValue);
		arr.insert(temp);
		isFind = true;
		break;
	}
	if (!isFind)
		cout << "There is no such word" << endl;
}
void SearchElement(const map<string, string> arr)
{
	bool isFind = false;
	for (auto ptr = arr.find(EnterWord()); ptr != arr.end();)
	{
		cout << ptr->first << " - " << ptr->second << endl;
		isFind = true;
		break;
	}
	if (!isFind)
		cout << "There is no such word" << endl;
}
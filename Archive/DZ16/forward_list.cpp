#include <iostream>
using namespace std;

struct Element
{
	char data;
	Element* next;
};
class List
{
private:
	Element* head;
	Element* tail;
	int count;
public:
	List();
	~List();
	void Add(char userData);
	void AddPosition(char userData, int userPos);
	void DelPosition(int userPos);
	void Del();
	void DelAll();
	void Print();
	int SearchPosition(char userData);
	int GetCount();
};

List::List()
{
	head = tail = NULL;
	count = 0;
}
List::~List()
{
	DelAll();
}
int List::GetCount()
{
	return count;
}
void List::Add(char userData)
{
	Element* temp = new Element;

	temp->data = userData;
	temp->next = NULL;

	if (head != NULL)
	{
		tail->next = temp;
		tail = temp;
	}
	else
	{
		head = tail = temp;
	}
	count++;
}
void List::AddPosition(char userData, int userPos)
{
	if (userPos < 0 || userPos > count)
	{
		cout << "Unacceptable position" << endl;
		return;
	}
	else
	{
		if (userPos == count)
			Add(userData);
		else if (userPos == 1)
		{
			Element* newElem = new Element;
			newElem->data = userData;
			newElem->next = head;
			head = newElem;
			count++;
		}
		else
		{
			Element* newElem = new Element;
			newElem->data = userData;
			newElem->next = NULL;

			int tempCount = 1;
			Element* temp = head;

			while (tempCount != userPos - 1)
			{
				temp = temp->next;
				tempCount++;
			}
			newElem->next = temp->next;
			temp->next = newElem;
			count++;
		}
	}
}
void List::Del()
{
	Element* temp = head;
	head = head->next;
	delete temp;
	count--;
}
void List::DelPosition(int userPos)
{
	if (userPos < 0 || userPos > count)
	{
		cout << "Unacceptable position" << endl;
		return;
	}
	else
	{
		if (userPos == 1)
			Del();
		else
		{
			Element* temp = head;
			int tempCount = 1;
			while (tempCount != userPos - 1)
			{
				temp = temp->next;
				tempCount++;
			}
			Element* del = temp->next;
			temp->next = del->next;
			delete del;
			count--;
		}
	}
}
void List::DelAll()
{
	while (head != 0)
		Del();
}
void List::Print()
{
	Element* temp = head;
	while (temp != 0)
	{
		cout << temp->data;
		temp = temp->next;
	}
	cout << endl;
}
int List::SearchPosition(char userData)
{
	Element* temp = head;
	for (int i = 1; i != count; i++)
	{
		if (temp->data == userData)
			return i;
		else
			temp = temp->next;
	}
	return NULL;
}

void main()
{
	List lst;

	char s[] = "Hhelllo worldd";
	int len = strlen(s);
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	
	lst.Print();
	lst.DelPosition(lst.SearchPosition('h'));
	lst.DelPosition(lst.SearchPosition('l'));
	lst.DelPosition(lst.SearchPosition('d'));
	lst.AddPosition('!', lst.GetCount());
	lst.Print();
}
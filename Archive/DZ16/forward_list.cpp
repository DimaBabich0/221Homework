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
	if (userPos < 0 || userPos > count)//проверяем допустимость позиции
	{
		cout << "Unacceptable position" << endl;
		return;
	}
	else
	{
		if (userPos == count)//если элемент последний, то просто вызываем нашу функцию Add
			Add(userData);
		else if (userPos == 1)//если элемент первый, то меняем у head указатель на новый элемент
		{
			Element* newElem = new Element;
			newElem->data = userData;
			newElem->next = head;
			head = newElem;
			count++;//увеличиваем счетчик
		}
		else//если элемент на другой позиции, то тогда ищем по индексу
		{
			Element* newElem = new Element;//создаем новый элемент
			newElem->data = userData;
			newElem->next = NULL;

			int tempCount = 1;//счетчик для индекса
			Element* temp = head;//временный элемент для цикла

			while (tempCount != userPos - 1)//цикл пока не дойдем до элемента перед позицией пользователя
			{
				temp = temp->next;
				tempCount++;
			}
			newElem->next = temp->next;//меняем указатели у элементов
			temp->next = newElem;
			count++;//увеличиваем счетчик
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
	if (userPos < 0 || userPos > count)//проверяем допустимость позиции
	{
		cout << "Unacceptable position" << endl;
		return;
	}
	else
	{
		if (userPos == 1)//если элемент первый, то просто вызываем нашу функцию Del()
			Del();
		else//иначе
		{
			Element* temp = head;//берем первый элемент за основу
			int tempCount = 1;//счетчик для индекса
			while (tempCount != userPos - 1)//цикл пока не дойдем до элемента перед позицией пользователя
			{
				temp = temp->next;
				tempCount++;
			}
			Element* del = temp->next;//удаляем элемент
			temp->next = del->next;
			delete del;
			count--;//уменьшаем счетчик в объекте
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
	for (int i = 1; i != count; i++)//цикл для прохода по листу
	{
		if (temp->data == userData)//если символы совпадают
			return i;//возвращаем индекс
		else//иначе
			temp = temp->next;//переходим к следующему указателю
	}
	return NULL;//если цикл пройден и не было найдено индекса, то возвращаем null
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
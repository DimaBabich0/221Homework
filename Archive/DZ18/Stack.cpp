#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack()
{
    top = nullptr;
}
Stack::~Stack()
{
	DelAll();
}
bool Stack::isEmpty() 
{
    return top == nullptr;
}

void Stack::Add(int userData)
{
    Element* newElement = new Element(userData);
    if (isEmpty()) 
        top = newElement;
    else 
    {
        Element* temp = top;
        while (temp->GetNext() != nullptr)
        {
            temp = temp->GetNext();
        }
        temp->SetNext(newElement);
        newElement->SetPrev(temp);
    }
}
void Stack::Del()
{
	if (isEmpty())
	{
		cout << "Stack is empty" << endl;
		return;
	}
	
    Element* temp = top;
    top = top->GetNext();
    if (top)
        top->SetPrev(nullptr);
    delete temp;
}
void Stack::DelAll()
{
	while (!isEmpty())
		Del();
}
void Stack::Print()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return;
    }

    Element* temp = top;
    while (temp->GetNext() != nullptr)
    {
        cout << temp->GetData() << " ";
        temp = temp->GetNext();
    }
    cout << temp->GetData() << endl;
}
int Stack::Get()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return NULL;
    }

    Element* temp = top;
    top = temp->GetNext();

    int tempData = temp->GetData();
    delete temp;
    return tempData;
}
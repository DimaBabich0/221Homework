#include <iostream>
using namespace std;

class Element
{
private:
    int data;
    Element* next;
    Element* prev;
public:
    Element(int userData) : data(userData), next(nullptr), prev(nullptr) {}

    int GetData()
    {
        return data;
    }
    Element* GetNext()
    {
        return next;
    }
    Element* GetPrev()
    {
        return prev;
    }

    void SetData(int userData)
    {
        data = userData;
    }
    void SetNext(Element* userNext)
    {
        next = userNext;
    }
    void SetPrev(Element* userPrev)
    {
        prev = userPrev;
    }
};
class Queue 
{
private:
    Element* top;
    Element* end;
    int length;
public:
    Queue() : top(nullptr), end(nullptr), length(NULL) {}
    ~Queue() 
    {
        while (top != nullptr) 
        {
            Element* temp = top;
            top = top->GetNext();
            delete temp;
        }
    }

    void push(const int& data) 
    {
        Element* newElement = new Element(data);
        if (end == nullptr)
            top = end = newElement;
        else 
        {
            end->SetNext(newElement);
            newElement->SetPrev(end);
            end = newElement;
        }
        length++;
    }

    void pop() 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Element* temp = top;
        top = top->GetNext();
        if (top == nullptr)
            end = nullptr;
        else
            top->SetPrev(nullptr);
        delete temp;
        length--;
    }

    int peek() const 
    {
        if (isEmpty()) 
        {
            cout << "Queue is empty" << endl;
            return NULL;
        }
        return top->GetData();
    }

    bool isEmpty() const 
    {
        return length == 0;
    }
    int getLength() const
    {
        return length;
    }
};

int main() {
    Queue queue;

    for (int i = 0; i < 10; i++)
        queue.push(i + 1);
    cout << "Top element: " << queue.peek() << endl;

    queue.pop();
    cout << "Top element after pop: " << queue.peek() << endl;

    cout << "Length of queue: " << queue.getLength() << endl;
}
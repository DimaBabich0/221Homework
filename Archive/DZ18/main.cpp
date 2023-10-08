#include "Stack.h"
#include <iostream>
using namespace std;

int main()
{
	Stack st;

	const int SIZE = 10;
	int arr[SIZE] = { 0,1,2,3,4,5,6,7,8,9 };

	for (int i = 0; i < SIZE; i++)
	{
		st.Add(arr[i]);
	}

	cout << "Stack:" << endl;
	st.Print();

	cout << "Elements from Get():" << endl;
	int temp = st.Get();
	cout << temp << " ";
	temp = st.Get();
	cout << temp << " ";
	temp = st.Get();
	cout << temp << " " << endl;

	cout << "Changed stack:" << endl;
	st.Print();

	cout << "Stack after adding a new element:" << endl;
	st.Add(10);
	st.Print();

	cout << "Stack after deleting element:" << endl;
	st.Del();
	st.Print();

	cout << "Stack after deleting all element:" << endl;
	st.DelAll();
	st.Print();
}
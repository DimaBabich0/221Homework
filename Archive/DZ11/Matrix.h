#pragma once
#include <iostream>
using namespace std;

template<class T>
class Matrix
{
private:
	int cols;
	int rows;
	T** arr;
public:
	Matrix();
	Matrix(const int userCols, const int userRows);
	Matrix(const Matrix<T>& point);
	~Matrix();
	Matrix<T>& operator=(Matrix<T>&& obj);

	void Input();
	void InputRand(const int minRand, const int maxRand);
	void Print();

	Matrix<T> operator+(const Matrix<T>& obj);
	Matrix<T> operator-(const Matrix<T>& obj);
	Matrix<T> operator*(const Matrix<T>& obj);
	Matrix<T> operator/(const Matrix<T>& obj);

	void FindMax();
	void FindMin();
};

template<class T>
Matrix<T>::Matrix()
{
	rows = NULL;
	cols = NULL;
	T** arr = nullptr;
}
template<class T>
Matrix<T>::Matrix(const int userCols, const int userRows)
{
	cols = userCols;
	rows = userRows;
	arr = new T*[cols];
	for (int i = 0; i < cols; i++)
		arr[i] = new T[rows];
}
template<class T>
Matrix<T>::Matrix(const Matrix<T>& point)
{
	cols = point.cols;
	rows = point.rows;
	arr = new T*[cols];
	for (int i = 0; i < cols; i++)
	{
		arr[i] = new T[rows];
		for (int j = 0; j < rows; j++)
			arr[i][j] = point.arr[i][j];
	}
}
template<class T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < cols; ++i)
		delete[] arr[i];
	delete[] arr;
}
template<class T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>&& point)
{
	if (this != &point)
	{
		for (int i = 0; i < cols; ++i)
		{
			delete[] arr[i];
		}
		delete[] arr;

		cols = point.cols;
		rows = point.rows;
		arr = point.arr;

		point.cols = 0;
		point.rows = 0;
		point.arr = nullptr;
	}
	return *this;
}


template<class T>
void Matrix<T>::Input()
{
	for (int i = 0; i < cols; ++i)
	{
		cout << "Array #" << i << endl;
		for (int j = 0; j < rows; ++j)
		{
			cout << "Element #" << j << ": " << endl;
			cin >> arr[i][j];
		}
	}
}
template<class T>
void Matrix<T>::InputRand(const int minRand, const int maxRand)
{
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
	}
}
template<class T>
void Matrix<T>::Print()
{
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& obj)
{
	if (rows != obj.rows || cols != obj.cols)
		return Matrix<T>();

	Matrix<T> result(cols, rows);
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
			result.arr[i][j] = arr[i][j] + obj.arr[i][j];
	}
	return result;
}
template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& obj)
{
	if (rows != obj.rows || cols != obj.cols)
		return Matrix<T>();

	Matrix<T> result(cols, rows);
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
			result.arr[i][j] = arr[i][j] - obj.arr[i][j];
	}
	return result;
}
template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& obj)
{
	if (rows != obj.rows || cols != obj.cols)
		return Matrix<T>();

	Matrix<T> result(cols, rows);
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
			result.arr[i][j] = arr[i][j] * obj.arr[i][j];
	}
	return result;
}
template<class T>
Matrix<T> Matrix<T>::operator/(const Matrix<T>& obj)
{
	if (rows != obj.rows || cols != obj.cols)
		return Matrix<T>();

	Matrix<T> result(cols, rows);
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
			result.arr[i][j] = arr[i][j] / obj.arr[i][j];
	}
	return result;
}

template<class T>
void Matrix<T>::FindMax()
{
	T temp = arr[0][0];
	for (int i = 0; i < cols; ++i)
	{
		for (int j = 0; j < rows; ++j)
		{
			if (arr[i][j] > temp)
				temp = arr[i][j];
		}
	}
	cout << "Max element: " << temp << endl;
}
template<class T>
void Matrix<T>::FindMin()
{
	T temp = arr[0][0];
	for (int i = 0; i < cols; ++i)
	{
		for (int j = 0; j < rows; ++j)
		{
			if (arr[i][j] < temp)
				temp = arr[i][j];
		}
	}
	cout << "Min element: " << temp << endl;
}
#pragma once
#include <fstream>
#include "Sort.h"
#include "sortComp.h"
using namespace std;
template <class T>
class MyArr
{
private:
	T* arr; int n;
	void copy(T* a, int n);
public:
	MyArr();
	MyArr(T* a, int n);
	MyArr(const MyArr& a);
	MyArr(int n);
	void setN(int n) {
		if (arr) delete[] arr;
		this->n = n;
		arr = new T[n];
	}
	~MyArr();

	int getSize();

	MyArr<T>& operator = (const MyArr<T>& a);
	MyArr<T> operator + (const MyArr<T>& a);
	T& operator [] (int k);
	void sortQsort(int(*comp)(const void *, const void *));
	void sort(bool(*comp)(T&, T&));
	//T operator[] (int k) { return arr[k]; }
	friend ostream& operator << (ostream& os, MyArr<T>& a)
	{
		for (int i = 0; i < a.n; i++)
			os << a[i] << '\n';
		return os;
	}
	friend istream& operator >> (istream& is, MyArr<T>& a)
	{
		is >> a.n;
		a.setN(a.n);
		for (int i = 0; i < a.n; i++)
			is >> a[i];
		return is;
	}
};

template<class T>
inline void MyArr<T>::copy(T* a, int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = a[i];
	this->n = n;
}

template<class T>
inline int MyArr<T>::getSize()
{
	return n;
}

template<class T>
inline MyArr<T>::MyArr()
{
	arr = NULL;
	n = 0;
}

template<class T>
inline MyArr<T>::MyArr(T* a, int n)
{
	arr = new T[n];
	copy(arr, a);
}

template<class T>
inline MyArr<T>::MyArr(const MyArr<T>& a)
{
	arr = new T[a.n];
	copy(a.arr, a.n);
}

template<class T>
inline MyArr<T>::MyArr(int n)
{
	arr = new T[n];
	this->n = n;
}

template<class T>
inline MyArr<T>::~MyArr()
{
	n = 0;
	delete[] arr;
}

template<class T>
inline MyArr<T>& MyArr<T>::operator=(const MyArr<T> &a)
{
	if (arr) delete[] arr;
	arr = new T[n];
	copy(a.arr, a.n);
	return *this;
}

template<class T>
inline MyArr<T> MyArr<T>::operator+(const MyArr<T>& a)
{
	MyArr New(n + a.n);
	for (int i = 0; i < n; i++)
		New.Arr[i] = arr[i];
	for (int i = 0; i < a.n; i++)
		New.Arr[n + i] = a.arr[i];
	return New;
}

template<class T>
inline T& MyArr<T>::operator[](int k)
{
	if (k > n) throw("out of range");
	return arr[k];
}

template<class T>
inline void MyArr<T>::sortQsort(int (*comp)(const void *, const void *))
{
	//BubbleSort(this->arr, n);
	//qsort(this->arr, n, sizeof(T), T::compNum);
	//qsort(this->arr, n, sizeof(T), T::compDestination);
	qsort(this->arr, n, sizeof(T), comp);
}

template<class T>
inline void MyArr<T>::sort(bool(*comp)(T&, T&))
{
	BubbleSort1(arr, n, comp);
}

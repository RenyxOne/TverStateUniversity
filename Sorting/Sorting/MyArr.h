#pragma once
#include <iostream>
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
	void hoar(T* arr, int right, int(*comp)(const void* a, const void* b), int left = 0, bool start = true);
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
	T* getArr();
	void push_back(T a) {
		
	}

	MyArr<T>& operator = (const MyArr<T>& a);
	MyArr<T> operator + (const MyArr<T>& a);
	T& operator [] (int k);
	void sortQsort(int(*comp)(const void *, const void *));
	void insert_mysort(bool(*comp)(const void* a, const void* b));
	void select_mysort(bool(*comp)(const void* a, const void* b));
	void shell_mysort(bool(*comp)(const void* a, const void* b));
	void hoar_mysort(int(*comp)(const void* a, const void* b));
	void bubble_mysort(bool(*comp)(const void* a, const void* b));

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
inline void MyArr<T>::hoar(T* arr, int right, int(*comp)(const void* a, const void* b), int left, bool start)
{
	if (start) right -= 1;
	T mid = arr[(left + right) / 2];
	int l = left; int r = right;
	do{
		while (comp(&arr[l], &mid) < 0) 
			l++;
		while (comp(&arr[r], &mid) > 0) 
			r--;
		if (l <= r) {
			if (l < r) {
				T help = arr[l];
				arr[l] = arr[r];
				arr[r] = help;
			}
			l++;
			r--;
		}
	} while (l <= r);
	if (l < right)
		hoar(arr, right, comp, l, false);
	if (left < r)
		hoar(arr, r, comp, left, false);
}

template<class T>
inline int MyArr<T>::getSize()
{
	return n;
}

template<class T>
inline T* MyArr<T>::getArr()
{
	return arr;
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
	n = a.n;
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
inline void MyArr<T>::bubble_mysort(bool(*comp)(const void* a, const void* b))
{
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 0; i < n - 1; i++) {
			if (comp(&arr[i], &arr[i + 1])) {
				flag = true;
				T help = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = help;
			}
		}
	}
}

template<class T>
inline void MyArr<T>::insert_mysort(bool(*comp)(const void* a, const void* b))
{
	for (int i = 1; i < n; i++) {
		T help = arr[i];
		int j = i - 1;
		while (j >= 0 && comp(&arr[j], &help)) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = help;
	}
}

template<class T>
inline void MyArr<T>::select_mysort(bool(*comp)(const void* a, const void* b))
{
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (comp(&arr[min], &arr[j])) min = j;
		T help = arr[i];
		arr[i] = arr[min];
		arr[min] = help;
	}
}

template<class T>
inline void MyArr<T>::shell_mysort(bool(*comp)(const void* a, const void *b))
{
	for (int step = n / 2; step > 0; step /= 2)
		for (int now = step; now < n; now++)
			for (int s = now - step; s >= 0 && comp(&arr[s], &arr[s + step]); s -= step) {
				T help = arr[s];
				arr[s] = arr[s + step];
				arr[s + step] = help;
			}
}

template<class T>
inline void MyArr<T>::hoar_mysort(int(*comp)(const void* a, const void* b))
{
	hoar(arr, n, comp);
}


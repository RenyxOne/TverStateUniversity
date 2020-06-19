#pragma once
#include <fstream>
#include <iostream>
using namespace std;

template <class T>
class List {
private:
	template <class T>
	class node {
	public: 
		T info;
		node* next;
		node(T info = T(), node* next = nullptr)
		{
			this->info = info;
			this->next = next;
		}
	};

	int size;
	node<T>* head;

	node<T>* get_node(int n) {
		if (n > this->size) return nullptr;
		node<T>* cur = this->head;
		for (int i = 0; i < n; i++)
			cur = cur->next;
		return cur;
	}
public:
	List<T>() {
		size = 0;
		head = nullptr;
	}

	List<T>(const List& a) {
		node<T>* cur = a.head;
		while (cur) {
			this->push_back(cur->info);
			cur = cur->next;
		}
	}

	~List<T>() {
		this->size = 0;
		while (this -> head) {
			node<T>* toDel = this -> head;
			this->head = this->head->next;
			delete toDel;
		}
	}

	//check list for empty
	bool isEmpty();

	//insert's
	void push_back(T a);
	void push_front(T a);
	void insert(T a, int pos);
	void insert_at_sort(T a, bool(*comp)(T& a, T& b));

	//Поиск
	int search(T a);

	//delete elements
	int del(T del, node<T>* pos = nullptr);

	//size
	int get_size();

	//insertions sort
	void insertion_sort(bool(*comp)(T& a, T& b));
	

	T& operator[](const int index);

	friend ostream& operator<<(ostream& os, const List<T>& a){
		node<T>* cur = a.head;
		while (cur) {
			os << cur->info << '\n';
			cur = cur->next;
		}
		return os;
	}
	friend istream& operator>>(istream& is, List<T>& a) {
		T help;
		is >> help;
		a.push_back(help);
		return is;
	}
	
};

template<class T>
inline bool List<T>::isEmpty()
{
	return !this->size;
}

template<class T>
inline void List<T>::push_back(T a)
{
	if (head == nullptr) head = new node<T>(a);
	else {
		node<T>* cur = this->head;
		while (cur->next != nullptr)
			cur = cur->next;
		cur->next = new node<T>(a);

	}
	size++;
}

template<class T>
inline void List<T>::push_front(T a) {
	node<T>* newHead = new node<T>(a);
	newHead->next = this->head;
	this->head = newHead;
	size++;
}

template<class T>
inline void List<T>::insert(T a, int pos)
{
	if (pos == 0) {
		push_front(a); return;
	}
	if (pos >= this->size) {
		push_back(a); return;
	}
	node<T>* cur = this->head;
	int n = 0;
	while (n < pos - 1) {
		cur = cur->next;
		n++;
	}
	cur->next = new node<T>(a, cur->next);
	size++;
}

template<class T>
inline void List<T>::insert_at_sort(T a, bool(*comp)(T& a, T& b))
{
	node<T>* cur = new node<T>(T(), this->head);
	int pos = 0;
	while (cur->next->next) {
		if (comp(cur->next->info, cur->next->next->info)) { cout << "\nList not sorted\n"; return; }
		if (comp(a,cur->next->info)) pos++;
		cur = cur->next;
	}
	if (pos == this->size - 1 && comp(a, cur->info)) push_back(a);
	else insert(a, pos);
}

template<class T>
inline int List<T>::search(T a)
{
	int i = 0;
	node<T>* cur = this->head;
	while (cur) {
		if (cur->info == a) return i;
		cur = cur->next;
		i++;
	}
	return -1;
}


template<class T>
inline int List<T>::get_size()
{
	return this->size;
}

template<class T>
inline void List<T>::insertion_sort(bool(*comp)(T& a, T& b))
{
	if (this->size < 2) return;

	node<T>* ptr = this->head->next;
	node<T>* prev_ptr = this->head;

	while (ptr) {
		node<T>* temp;
		node<T>* prev_temp;
		for (temp = this->head, prev_temp = nullptr; temp != ptr && comp(temp->info, ptr->info); prev_temp = temp, temp = temp->next);
		if (temp == ptr) {
			prev_ptr = ptr;
			ptr = ptr->next;
		}
		else {
			prev_ptr->next = ptr->next;
			if (prev_temp) prev_temp->next = ptr;
			else this->head = ptr;
			ptr->next = temp;
			ptr = prev_ptr->next;
		}
	}

}

template<class T>
inline T& List<T>::operator[](const int index) {
	return get_node(index)->info;
}

template<class T>
inline int List<T>::del(T del, node<T>* pos)
{
	int deleted = 0;
	while (this->head->info == del && !pos) {
		this->head = this->head->next;
		size--;
		deleted++;
	}

	node<T>* cur = this->head;

	if (pos) cur = pos;
	while (cur->next != nullptr)
	{
		if (cur->next->info == del){
			cur->next = cur->next->next;
			size--;
			deleted++;
		}
		else cur = cur->next;
	}
	return deleted;
}
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

	~List<T>() {}

	//check list for empty
	bool isEmpty();

	//insert's
	void push_back(T a);
	void push_front(T a);
	void insert(T a, int pos);
	void insert_at_sort(T a);

	//Поиск
	int search(T a);

	//delete elements
	int del(T del, node<T>* pos = nullptr);
	void del_at_pos(int pos);
	void DeDupe();

	//size
	int get_size();

	//Var 3
	void place_max_to_start_min_to_end();

	//insertions sort
	void insert_sort();
	void insert_node_at_pos(node<T>* key, int pos);
	

	T& operator[](const int index);

	friend ostream& operator<<(ostream& os, const List<T>& a){
		node<T>* cur = a.head;
		while (cur) {
			os << cur->info << ' ';
			cur = cur->next;
		}
		return os;
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
inline void List<T>::insert_at_sort(T a)
{
	node<T>* cur = new node<T>(NULL, this->head);
	int pos = 0;
	while (cur->next != nullptr) {
		if (cur->next->info > cur->next->info) { cout << "\nList not sorted\n"; return; }
		if (cur->next->info < a) pos++;
		*cur = *(cur->next);
	}
	insert(a, pos);
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
inline void List<T>::place_max_to_start_min_to_end()
{
	if (this->size <= 1) return;

	T value_min;
	T value_max;
	node<T>* help;

	if (this->head->info < this->head->next->info) {
		value_min = this->head->info;
		value_max = this->head->next->info;
	}
	else {
		value_min = this->head->next->info;
		value_max = this->head->info;
	}

	//insert max
	node<T>* cur = this->head;
	while (cur) {
		if (cur->info < value_min) value_min = cur->info;
		else if (cur->info > value_max) value_max = cur->info;
		cur = cur->next;
	}

	int pos = 0;
	cur = this->head;
	while (cur->info != value_max) {
		cur = cur->next;
		pos++;
	}

	help = cur;
	this->del_at_pos(pos);
	help->next = this->head;
	this->head = help;
	this->size++;

	//insert min
	cur = this->head;
	pos = 0;
	while (cur->info != value_min) {
		cur = cur->next;
		pos++;
	}

	help = cur;
	this->del_at_pos(pos);

	while (cur->next != nullptr) cur = cur->next;
	help->next = nullptr;
	cur->next = help;
	size++;
}

template<class T>
inline void List<T>::insert_sort()
{
	if (this->size < 2) return;

	for (int i = 1; i < this->size; i++) {
		node<T>* key = get_node(i);
		del_at_pos(i);
		int j = i - 1;
		while (j >= 0 && (*this)[j] > key->info)
			j = j - 1;
		insert_node_at_pos(key, j + 1);
	}
}

template<class T>
inline void List<T>::insert_node_at_pos(node<T>* key, int pos)
{
	if (pos == 0) {
		key->next = this->head;
		this->head = key;
		this->size++;
		return;
	}
	key->next = nullptr;
	int i = 0;
	node<T>* cur = this->head;
	while (cur->next != nullptr && i < pos - 1) {
		cur = cur->next;
		i++;
	}
	if (i < this->size) key->next = cur->next;
	cur->next = key;
	size++;
}

template<class T>
inline T& List<T>::operator[](const int index) {
	int n = 0;
	node<T>* cur = this->head;
	while (cur != nullptr) {
		if (n == index) {
			return cur->info;
		}
		cur = cur->next;
		n++;
	}
}

template<class T>
inline void List<T>::DeDupe()
{
	node<T>* cur = this->head;
	while (cur)
		if (!del(cur->info, cur))
			cur = cur->next;
}

template<class T>
inline int List<T>::del(T del, node<T>* pos)
{
	int deleted = 0;
	node<T>* cur = this->head;

	if (pos) cur = pos;

	if (this->head->info == del && !pos) {
		this->head = this->head->next;
		size--;
		deleted++;
	}
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

template<class T>
inline void List<T>::del_at_pos(int pos)
{
	if (pos >= size || pos < 0) return;

	if (pos == 0){ 
		this->head = this->head->next;
		this->size--;
		return;
	}

	int now_pos = 0;
	node<T>* cur = this->head;
	while (now_pos < pos - 1) {
		cur = cur->next;
		now_pos++;
	}
	cur->next = cur->next->next;
	this->size--;
}

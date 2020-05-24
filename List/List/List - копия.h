#pragma once
#include <fstream>

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

public:
	List() {
		size = 0;
		head = nullptr;
	}

	void push_back(T a){
		if (head == nullptr) {
			head = new node<T>(a);
		}
		else {
			node<T>* cur = this->head;
			while (cur->next != nullptr)
				cur = cur->next;
			cur->next = new node<T>(a);
			size++;
		}
	}

	void push_front(T a) {
		node<T>* newHead = new node<T>(a);
		newHead->next = this->head;
		this->head = newHead;
		size++;
	}

	void insert(T a, int pos) {
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
	}

	void insert_at_sort(T a) {
		node<T> cur(NULL, *this->head);
		int pos = 0;
		while (cur->next != nullptr) {
			if (cur->next->info > cur->next->info) return;
			if (cur->next->info < a) pos++;
			*cur = *(cur->next);
		}
		insert(a, pos);
	}

	void del_element(T a, node<T>* cur = this->head) {
		while (cur->next != nullptr) {
			if (cur->next->info == a)
				cur->next = cur->next->next;
			cur = cur->next;
		}
	}

	int get_size() {
		return this->size;
	}

	T& operator[](const int index) {
		int n = 0;
		node<T>* cur = this->head;
		while (cur != nullptr)
		{
			if (n == index)
			{
				return cur->info;
			}
			cur = cur->next;
			n++;
		}
	}

};
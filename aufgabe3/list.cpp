#include "list.h"
#include <stdlib.h>
#include <iostream>

template <typename T> List<T>::List() {
	this->head = new elem;
	this->head->next = nullptr;
}

template <typename T> List<T>::List(List &list) {
	this->head = new elem;
	elem* buf;
	elem* lastEl = this->head;

	elem* currFrom = list.head;
	while (currFrom->next != nullptr) {
		currFrom = currFrom->next;

		buf = new elem;
		buf->val = currFrom->val;
		buf->next = nullptr;
		
		lastEl->next = buf;
		
		lastEl = buf;
	}
}

template <typename T> int List<T>::count() {
	int i = 0;
	elem* curr = this->head;
	while (curr->next != nullptr) {
		i++;
		curr = curr->next;
	}
	return i; 
}

template <typename T> void List<T>::insert(T value) {
	elem* newEl = new elem;
	newEl->val = value;
	newEl->next = this->head->next;
	this->head->next = newEl;
}

template <typename T> T List<T>::deleteItem() {
	if (this->head->next == nullptr) throw "No Items to Delete";
	T val = this->head->next->val;
	elem* newSecond = this->head->next->next; 
	delete this->head->next; // delete old second
	this->head->next = newSecond;
	return val;
}

template <typename T> void List<T>::printList() {
	elem* curr = this->head;
	while (curr->next != nullptr) {
		curr = curr->next;
		std::cout << curr->val;
	}
	std::cout << std::endl;
}

template <typename T> void List<T>::operator=(List *list) {
	elem* curr = this->head;
	while (curr->next != nullptr) {
		elem* next = curr->next;
		delete curr;
		curr = next;
	}
	List<T> newList(*list);
	*(this) = newList;
}

template class List<int>;
template class List<float>;
template class List<char>;

#include "list.h"

template <typename T> List<T>::List() {
	this->head = new elem;
	this->head->next = nullptr;
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
	newEl->next = nullptr;

	elem* curr = this->head;
	while (curr->next != nullptr) curr = curr->next;
	curr->next = newEl;
}

template <typename T> T List<T>::deleteItem() {
	if (this->head->next == nullptr) throw "No Items to Delete";
	T val = this->head->next->val;
	elem* newSecond = this->head->next->next; 
	delete this->head->next; // delete old second
	this->head->next = newSecond;
	return val;
}

template class List<int>;
template class List<float>;
template class List<char>;

#include "cvektor.h"
#include <iostream>
#include <utility>

CVektor::CVektor(int n, float val) {
	this->f =  new float[n];
	this->n = n;
	for (int i = 0; i < n; i++) *(this->f + i) = val;
}

CVektor::CVektor() {
	this->f = nullptr;
	this->n = 0;
}

CVektor::CVektor(const CVektor &vector) {
	std::cout << "copy" << std::endl;
	this->n = vector.n;
	this->f =  new float[this->n];
	for (int i = 0; i < this->n; i++) {
		*(this->f + i) = vector.f[i];
	}
}

CVektor::~CVektor() {
	try {
		std::cout << "deleted" << std::endl;
		delete this->f;
	} catch (...) {
		std::cout << "not deleted" << std::endl;
	}
}

float& CVektor::operator[](int x) {
	if (x > this->n || x < 0) throw "Out of bounds Exception";
	return this->f[x];
}

int CVektor::length() {
	return this->n;
}

void CVektor::operator=(CVektor vector) { 
	std::cout << "assign" << std::endl;

	swap(vector);
}

void CVektor::swap(CVektor &other) {
	std::swap(this->f, other.f);
	std::swap(this->n, other.n);
}

CVektor CVektor::operator+(CVektor vector) { 
	const int len = this->length();
	CVektor newVec = CVektor(len + vector.length(), 0);

	for (int i = 0; i < this->n; i++) newVec.operator[](i) = this->operator[](i);
		
	for (int i = len; i < len + vector.length(); i++) newVec.operator[](i) = vector.operator[](i - len);;

	return newVec;
}

void CVektor::operator+=(CVektor vector) { 
	*this = *this + vector;
}


void CVektor::display() {
	for (int i = 0; i < this->n; i++) std::cout << this->f[i] << " ";
	std::cout << std::endl;
}
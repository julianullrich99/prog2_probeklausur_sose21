#include "cvektor.h"
#include <iostream>

CVektor::CVektor(int n, float val) {
	this->f =  new float[n];
	this->n = n;
	for (int i = 0; i < n; i++) *(this->f + i) = val;
}

CVektor::CVektor() {
	CVektor(0,0);
}

CVektor::CVektor(CVektor* vector) {
	this->n = vector->length();
	this->f =  new float[this->n];
	for (int i = 0; i < this->n; i++) {
		*(this->f + i) = vector->operator[](i);
	}
}

CVektor::~CVektor() {
	delete this->f;
}

float& CVektor::operator[](int x) {
	if (x > this->n || x < 0) throw "Out of bounds Exception";
	return this->f[x];
}

int CVektor::length() {
	return this->n;
}

CVektor CVektor::operator=(CVektor &vector) { 
	delete this->f;
	this->n = vector.length();
	this->f =  new float[this->n];
	for (int i = 0; i < this->n; i++) {
		*(this->f + i) = vector.operator[](i);
	}
	return this;
}

CVektor CVektor::operator+(CVektor &vector) { 
	const int len = this->length();
	CVektor newVec = CVektor(len + vector.length(), 0);

	for (int i = 0; i < this->n; i++) newVec.operator[](i) = this->operator[](i);
		
	for (int i = len; i < len + vector.length(); i++) newVec.operator[](i) = vector.operator[](i - len);;

	return newVec;
}

CVektor CVektor::operator+=(CVektor &vector) { 
	CVektor ret = *this + vector;
	*(this) = ret;
	return this;
}


void CVektor::display() {
	for (int i = 0; i < this->n; i++) std::cout << this->f[i] << " ";
	std::cout << std::endl;
}
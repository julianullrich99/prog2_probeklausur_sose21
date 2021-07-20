#include "student.h"
#include <iostream>
#include <string.h>

Student::Student() { }

Student::Student(char* name, int day, int month, int year, float grade) {
	this->setName(name)
			->setDay(day)
			->setMonth(month)
			->setYear(year)
			->setGrade(grade);
}

Student* Student::setName(char* name) {
	if (strlen(name) > 30) return this;
	strcpy(this->name, name);
	return this;
}

Student* Student::setDay(int day) {
	if (day > 31 || day < 1) return this;
	this->day = day;
	return this;
}

Student* Student::setMonth(int month) {
	if (month > 12 || month < 1) return this;
	this->month = month;
	return this;
}

Student* Student::setYear(int year) {
	this->year = year;
	return this;
}

Student* Student::setGrade(float grade) {
	if (grade > 6 || grade < 0) return this;
	this->grade = grade;
	return this;
}

void Student::display() {
	std::cout << this->name << ", " << this->day << "." << this->month << "." << this->year << ", Note " << this->grade << std::endl;
}


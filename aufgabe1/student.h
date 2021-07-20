#ifndef STUDENT_H
#define STUDENT_H

#include <string.h>

class Student {
	public:
		Student();
		Student(char* name, int day, int month, int year, float grade);
		~Student(){};
		Student* setName(char* name);
		Student* setDay(int month);
		Student* setMonth(int month);
		Student* setYear(int year);
		Student* setGrade(float grade);
		void display();

	private:
		char name[30] = "Musterstudent";
		int day = 1;
		int month = 1;
		int year = 1995;
		float grade = 1;
};





#endif
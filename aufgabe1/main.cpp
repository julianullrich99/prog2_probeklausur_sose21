#include <stdlib.h>
#include <string.h>

#include "student.h"


int main() {
	Student student1 = Student();
	Student student2 = Student((char*)"Jannik", 12, 8, 1999, 0.3);
	Student student3 = Student();
	Student student4 = Student((char*)"Paul", 12, 8, 1999, 0.3);

	student3.setName((char*)"Foo Bar")->setDay(4);
	student4.setMonth(3)->setYear(2001)->setGrade(6);

	student1.display();
	student2.display();
	student3.display();
	student4.display();
	
	return 0;
}
#ifndef STUD_
#define STUD_
#include<iostream>

class Student
{
	char name[25], surname[30];
	uint16_t age;
public:
	Student(){}
	~Student() {}
	bool operator==(const Student& s1);
	bool operator!=(const Student& s1);
	friend std::ostream& operator<<(std::ostream& os, const Student& s);
	friend std::istream& operator>>(std::istream& is, Student& s);
};

#endif // !STUD_

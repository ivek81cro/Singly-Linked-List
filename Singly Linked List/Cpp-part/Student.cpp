#include "Student.h"

std::ostream& operator<<(std::ostream& os, const Student& s) {
	return os << s.name << ' ' << s.surname << ' ' << s.age;
}
std::istream& operator>>(std::istream& is, Student& s) {
	return is >> s.name >> s.surname >> s.age;
}
bool Student::operator==(const Student& s1) {
	return !strcmp(s1.name, name) && !strcmp(s1.surname, surname) && age == age;
}
bool Student::operator!=(const Student& s1) {
	return !(!strcmp(s1.name, name) && !strcmp(s1.surname, surname) && age == age);
}
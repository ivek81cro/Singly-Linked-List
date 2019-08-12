#include<fstream>
//#include"listCpp.h"
#include"listCpp3.h"
#include"Student.h"
//test program
int main(int argv, char *argc[])
{
	Student s;
	LinkedList<Student> *list = new LinkedList<Student>();
	if (list == nullptr) return -1;
	std::ifstream infs(argc[1]);
	int i{ 4 };
	while (--i) 
	{
		infs >> s;
		list->insAtEnd(s);
	}
	infs >> s;
	list->insAtPosition(1, s);
	infs >> s;
	list->insAtEnd(s);
	infs.close();	
	list->print();
	list->remove(s);
	list->print();
	delete list;
	list = nullptr;
}
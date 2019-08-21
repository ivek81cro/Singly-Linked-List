#include<fstream>
//#include"listCpp.h"
#include"listCpp3.h"
#include"Student.h"
//test program
int main(int argv, char *argc[])
{
	Student s;
	LinkedList<Student> *list = new LinkedList<Student>();
	if (!list) return -1;

	std::ifstream infs(argc[1]);
	int i{ 4 };
	while (--i) 
	{
		infs >> s;
		list->insAtEnd(s);
	}
	list->print();
	infs >> s;
	list->insAtPosition(2, s);
	infs >> s;
	list->insAtEnd(s);
	infs.close();	
	list->print();
	list->remove(s);
	list->print();
	delete list;
	list = nullptr;
}
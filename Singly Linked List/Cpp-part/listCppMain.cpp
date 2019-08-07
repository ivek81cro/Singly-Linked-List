#include<fstream>
//#include"listCpp.h"
#include"listCpp3.h"
#include"Student.h"

int main(int argv, char *argc[])
{
	Student s;
	LinkedList<Student> *list = new LinkedList<Student>();
	std::ifstream infs(argc[1]);
	int i{ 4 };
	while (--i) 
	{
		infs >> s;
		//list->add(s);
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
}
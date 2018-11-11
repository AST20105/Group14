#ifndef List_h
#define List_h

#include "Node.h"
#include <iostream>
using namespace std;

class List {
public:
	Node * head;

public:
	List();
	~List();
	void fileinput();
	void display();
	filterNode make_Type_List(Node *, string );
	void searchingByID(string x);
	void deletion(string x);
	void searchingByName(string x);
	void InsertionBytitleType(string x);


};

#endif

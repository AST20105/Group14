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
	void createfilNode(string, string, string, string, string, string, Node *);
	void display();
	filterNode make_Type_List(Node *, string );
	void insertion();

};

#endif

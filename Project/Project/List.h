#ifndef List_h
#define List_h

#include "Node.h"
#include <iostream>
#include <fstream> 
using namespace std;

class List {
public:
	Node * head;
	filterNode * filhead;
public:
	List();
	~List();
	void fileinput();
	void searchingByX(string x);
	void deletion_of_node(string x);
	void display();
	void fildisplay();
	List make_Type_List(Node *x, string  condition);

};

#endif

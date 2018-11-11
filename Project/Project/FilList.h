#ifndef FilList_h
#define FilList_h

#include "Node.h"
#include <iostream>
using namespace std;

class FilList {
public:
	filterNode * filhead;

public:
	FilList();
	void searchingByX(string x);
	void deletion_of_node(string x);
	void fildisplay();
	FilList make_Type_List(Node *x, string  condition);
};

#endif

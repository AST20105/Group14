#ifndef FilList_h
#define FilList_h

#include "Node.h"
#include <iostream>
using namespace std;

class FilList {
public:
	filterNode * filhead;
	FilList * next;

public:
	FilList();
	void fildisplay();
	void make_Type_List(Node *x, string  condition);
};

#endif

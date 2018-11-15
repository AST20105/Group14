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
	void fildisplay(int x);
	void make_Type_List(Node *x, string  condition);
	void make_gen_List2(Node* x, string condition1, string condition2);
	void make_gen_List3(Node* x, string condition1, string condition2, string condition3);

};

#endif
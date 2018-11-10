#include "Node.h"

class List {
private:
	Node * head;
	Node * tail;
public:
	List();
	~List();
	//void createNode(string ptconst, string ptitleType, string pprimaryTitle, string pstartYear, string pruntimeMinutes, string pgenres);
	void createfilNode(string, string, string, string, string, string, Node *);
	void display();
	filterNode make_Type_List(Node *, string );
	void insertion();
	void searchingByX;


};

#pragma once

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

	void MakeSearchingChoice();
	void searchingByID();
	void searchingByName();
	//void searchingByYear();
	void searchingByPgType();
	void searchingByType();


	void MakeDeletionChoice();
	void DeletionByID();
	void DeletionByName();
	void DeletionByYear();



};

#endif

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
	void MainDecision(int x);
	filterNode make_Type_List(Node *, string );
	//void InsertionBytitleType(string x);
	void MakeSearchingChoice();
	void searchingByID();
	void searchingByName();
	void searchingByYear();
	void searchingByPgType(string x);
	void searchingByType();


	void MakeDeletionChoice();
	void DeletionByID();
	void DeletionByName();
	void DeletionByYear();
	
	
	void Statistical(string x);

};

#endif

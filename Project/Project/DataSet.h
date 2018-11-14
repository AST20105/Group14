#ifndef DataSet_h
#define DataSet_h


#include <iostream>
#include "List.h"
#include "FilList.h"


using namespace std;

class DataSet
{
public:
	string listname[20];
	List * listSet;
	FilList * filListSet;
	DataSet * next;
public:
	DataSet() {
		for (int i = 0; i < 20; i++) {
			listname[i] = "";
		};
		listSet = new List();
		filListSet = new FilList();
		next = NULL;
	};

};

#endif
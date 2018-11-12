#ifndef DataSet_h
#define DataSet_h


#include <iostream>
#include "List.h"
#include "FilList.h"


using namespace std;

class DataSet
{
public:
	List * listSet;
	FilList * filListSet;
	DataSet * next;
public:
	DataSet() {
		listSet = new List;
		next = NULL;
	};

};

#endif
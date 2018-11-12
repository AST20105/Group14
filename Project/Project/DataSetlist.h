#ifndef DataSetlist_h
#define DataSetlist_h

#include "DataSet.h"
#include <iostream>

using namespace std;

class DataSetlist
{
public:
	DataSet * DataSethead;
public:
	DataSetlist();
	void fileinput();
	void display();



	void MainDecision();

	void MakeSearchingChoice(int x);
	void MangeInDataSetSearch();

	void searchingByID(int x);
	void searchingByName();
	void searchingByYear();
	void searchingByPgType();
	void searchingByType();





	void MakeDeletionChoice();
	void DeletionByID();
	void DeletionByName();
	void DeletionByYear();





};

#endif
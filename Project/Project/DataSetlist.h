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



	void MainDecision();

	void MangeInDataSetSearch();

	void MakeSearchingChoice(int x);
	void MangeInDataSetSearch();
	void MangeInDataSetDelete();

	//void searchingByID();
	Node *searchingByID(DataSet * CurrNode, Node * CurrNode1, string pID, int counter);
	void searchingByName();
	void searchingByYear();
	void searchingByPgType();
	//void searchingByType();





	void MakeDeletionChoice();
	void DeletionByID();
	void DeletionByName();
	void DeletionByYear();





};

#endif
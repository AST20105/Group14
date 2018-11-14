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

	void MakeSearchingChoice(int x);
	void MangeInDataSetSearch();
	void MangeInDataSetDelete();

	void searchingByID(int x);
	void searchingByName(int x);
	void searchingByYear(int x);
	void searchingByPgType(int y);
	void searchingByType();





	void MakeDeletionChoice(int x);
	void DeletionByID(int x);
	void DeletionByName(int x);
	void DeletionByYear();





};

#endif
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
	void MangeInDataSetCombine(bool firsttime);




	void searchingByID(int x);
	void searchingByName(int x);
	void searchingByYear(int x);
	void searchingByPgType(int y);

	void NumberOfType(int x);
	void searchingByType1(int x);
	void searchingByType2(int x);
	void searchingByType3(int x);




	void MakeDeletionChoice(int x);
	void DeletionByID(int x);
	void DeletionByName(int x);
	void DeletionByYear(int x);
	void DeletionByPgType(int x);

	void NumberOfTypeDel(int x);
	void DeleteByType1(int x);
	void DeleteByType2(int x);
	void DeleteByType3(int x);
	




	void MakeCombineChoice(int x, bool firsttime);
	void combineByID(int x, bool firsttime);
	void combineByName(int x, bool firsttime);
	void combineByYear(int x, bool firsttime);
	void combineByPgType(int x, bool firsttime);

	void combineNumberOfType(int x, bool firsttime);
	void combineByType1(int x, bool firsttime);
	void combineByType2(int x, bool firsttime);
	void combineByType3(int x, bool firsttime);



};

#endif
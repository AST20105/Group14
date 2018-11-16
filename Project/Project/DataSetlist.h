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
	void searchingByID(int x);
	void searchingByName(int x);
	void searchingByYear(int x);
	void searchingByPgType(int y);
	void NumberOfType(int x);
	void searchingByType1(int x);
	void searchingByType2(int x);
	void searchingByType3(int x);



	void MangeInDataSetModify();
	void MakeModifyingChoice(int x);
	void ModifyingByID(int x);
	void ModifyingByName(int x);
	void ModifyingByYear(int x);
	void ModifyingByPgType(int x);
	//void NumberOfTypeMod(int x);
	void modifyingByType(int x);
	//void modifyingByType2(int x);
	//void modifyingByType3(int x);




	void MangeInDataSetDelete();
	void MakeDeletionChoice(int x);
	void DeletionByID(int x);
	void DeletionByName(int x);
	void DeletionByYear(int x);
	void DeletionByPgType(int x);
	void NumberOfTypeDel(int x);
	void DeleteByType1(int x);
	void DeleteByType2(int x);
	void DeleteByType3(int x);





};

#endif
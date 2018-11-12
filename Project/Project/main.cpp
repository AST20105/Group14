#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include "DataSetlist.h"

using namespace std;

int main() {
	DataSetlist* n1= new DataSetlist();
	n1->fileinput();
	//n1->DataSethead->listSet->display();
	//n1->display();
	n1->DataSethead->filListSet->make_Type_List(n1->DataSethead->listSet->head,"short");
	//n1->DataSethead->filListSet->fildisplay();
	n1->DataSethead->filListSet->make_Type_List(n1->DataSethead->listSet->head, "movie");
	n1->DataSethead->filListSet->fildisplay();
	n1->fileinput();
	n1->DataSethead->next->filListSet->make_Type_List(n1->DataSethead->next->listSet->head, "short");
	n1->DataSethead->next->filListSet->make_Type_List(n1->DataSethead->next->listSet->head, "movie");
	n1->DataSethead->next->filListSet->fildisplay();
	//n1->DataSethead->listSet->display();
	
	//n1->DataSethead->next->listSet->display();
	
	//n1->DataSethead->next->next->listSet->display();
	system("pause");
	return 0;

}
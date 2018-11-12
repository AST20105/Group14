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
	n1->display();
	n1->fileinput();
	n1->display();
	n1->fileinput();
	n1->display();
	/*string type;
	cout << "intput type: ";
	cin >> type;
	n2 = &(n2->make_Type_List(n1->head, type));
	system("pause");
	system("cls"); 
	//n2->fildisplay();*/
	system("pause");
	return 0;

}
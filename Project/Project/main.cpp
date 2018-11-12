#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include "DataSetlist.h"



using namespace std;

int main() {
	List* n1 = new List();
	n1->fileinput();
	n1->display();
	system("pause");
	return 0;
}
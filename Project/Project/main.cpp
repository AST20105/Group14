#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include "List.h"

using namespace std;

int main() {
	List* n1 = new List();
	n1->fileinput();
	n1->display();
	string id;
	cout << "intput id: ";
	cin >> id;
	n1->deletion(id);
	system("pause");
	system("cls");
	n1->display();
	system("pause");
	return 0;

}
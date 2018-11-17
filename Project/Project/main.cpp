#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include <list>
#include "DataSetlist.h"



using namespace std;

int main() {
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	DataSetlist* n1 = new DataSetlist();
	n1->MainDecision();
	system("pause");
	return 0;
}
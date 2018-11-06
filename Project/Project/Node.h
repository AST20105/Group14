#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Node
{
public:
	string tconst;
	string titleType;
	string primaryTitle;
	string startYear;
	string runtimeMinutes;
	string genres[3];
	// To make a pointer pointing to the next set of data, linking process
	Node * next;
};


class filterNode
{
public:
	string tconst;
	string titleType;
	string primaryTitle;
	string startYear;
	string runtimeMinutes;
	string genres[3];
	Node * next;
	// To make a pointer pointing to the next set of data, linking process
	filterNode * filnext;
};
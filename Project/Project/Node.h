#ifndef Node_h
#define Node_h

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

public:
	Node(string ptconst, string ptitleType, string pprimaryTitle, string pstartYear, string pruntimeMinutes, string pgenres) {
		this->tconst = ptconst;
		this->titleType = ptitleType;
		this->primaryTitle = pprimaryTitle;
		this->startYear = pstartYear;
		this->runtimeMinutes = pruntimeMinutes;
		this->genres[0] = pgenres;
		this->genres[1] = pgenres;
		this->genres[2] = pgenres;
		this->next = NULL;
	};
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

#endif
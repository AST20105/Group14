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
	Node(string ptconst, string ptitleType, string pprimaryTitle, string pstartYear, string pruntimeMinutes, string pgenres0, string pgenres1, string pgenres2) {
		this->tconst = ptconst;
		this->titleType = ptitleType;
		this->primaryTitle = pprimaryTitle;
		this->startYear = pstartYear;
		this->runtimeMinutes = pruntimeMinutes;
		this->genres[0] = pgenres0;
		this->genres[1] = pgenres1;
		this->genres[2] = pgenres2;
		this->next = NULL;
	};
};


class filterNode
{
public:
	string ftconst;
	string ftitleType;
	string fprimaryTitle;
	string fstartYear;
	string fruntimeMinutes;
	string fgenres[3];
	Node * fnext;
	filterNode * filnext;
public:
	filterNode(string ptconst, string ptitleType, string pprimaryTitle, string pstartYear, string pruntimeMinutes, string pgenres0, string pgenres1, string pgenres2, Node * next) {
		this->ftconst = ptconst;
		this->ftitleType = ptitleType;
		this->fprimaryTitle = pprimaryTitle;
		this->fstartYear = pstartYear;
		this->fruntimeMinutes = pruntimeMinutes;
		this->fgenres[0] = pgenres0;
		this->fgenres[1] = pgenres1;
		this->fgenres[2] = pgenres2;
		this->fnext = next;
		this->filnext = NULL;
	};
};

#endif
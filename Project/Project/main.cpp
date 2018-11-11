#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include "List.h"


using namespace std;

class Node {
protected:
	// All the data member (Attributes)
	string tconst;
	string titleType;
	string primaryTitle;
	string startYear;
	string runtimeMinutes;
	string genres[3];
	// To make a pointer pointing to the next set of data, linking process
	Node * next;
public:
	//Default constructor
	Node() {
		tconst = " ";
		titleType = " ";
		primaryTitle = " ";
		startYear = " ";
		runtimeMinutes = " ";
		genres[0] = " ";
		genres[1] = " ";
		genres[2] = " ";
		next = NULL;
	};
	//Accessor & Mutator
	Node(string tconst, string titleType, string primaryTitle, string startYear, string runtimeMinutes, string genre) {
		this->tconst = tconst;
		this->titleType = titleType;
		this->primaryTitle = primaryTitle;
		this->startYear = startYear;
		this->runtimeMinutes = runtimeMinutes;
		this->genres[0] = genre;
		this->genres[1] = genre;
		this->genres[2] = genre;
		next = NULL;
	};
	string get_tconst() {
		return tconst;
	};
	string get_titleType() {
		return titleType;
	};
	string get_primaryTitle() {
		return primaryTitle;
	};
	string get_startYear() {
		return startYear;
	};
	string get_runtimeMinutes() {
		return runtimeMinutes;
	};
	string get_genres(int index) {
		return genres[index];
	};

	void set_tconst(string tconst) {

	};
	void set_titleType(string titleType) {

	};
	void set_primaryTitle(string primaryTitle) {

	};
	void set_startYear(string startYear) {

	};
	void set_runtimeMinutes(string runtimeMinutes) {

	};
	/*ifstream for inputting DataSet, a console user interface
	TODO::
	1. Userinput of filename to read file
	2. Separate the dataset into different attributes
	3. A little demonstration of printing out the whole DataSet
	*/
};


int main() {
	List* n1 = new List();
	n1->fileinput();
	n1->display();
	system("pause");
	return 0;

}
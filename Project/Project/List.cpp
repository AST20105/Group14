/*#include "List.h"

List::List() {
	//create an empty list
	head = NULL;
	tail = NULL;

};

List::~List() {

};

void List::createNode(string ptconst, string ptitleType, string pprimaryTitle, string pstartYear, string pruntimeMinutes, string pgenres) {
	Node * temp = new Node;
	temp->tconst = ptconst;
	temp->titleType = ptitleType;
	temp->primaryTitle = pprimaryTitle;
	temp->startYear = pstartYear;
	temp->runtimeMinutes = pruntimeMinutes;
	temp->genres[0] = pgenres;
	temp->genres[1] = pgenres;
	temp->genres[2] = pgenres;
	temp->next = head;
	head = temp;

	//determine if the list is empty
	if (head == NULL) {
		head = temp;
		tail = temp;
		temp = NULL;
	}
};

void List::display() {
	if (head == NULL) {
		cout << "Empty list is provided" << endl;
	}
	Node * displaynode = head;
	while (displaynode != NULL) {
		cout << displaynode->tconst << "\t" << displaynode->titleType << "\t" << displaynode->primaryTitle << "\t" << displaynode->startYear << "\t" << displaynode->runtimeMinutes << "\t" << displaynode->genres[0] << "\t" << displaynode->genres[1] << "\t" << displaynode->genres[2] << endl;
		displaynode = displaynode->next;
	}
	cout << endl;

};

void List::insertion() {

}
*/
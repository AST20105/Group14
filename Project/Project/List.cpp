#include "List.h"

List::List() {

	head = NULL;
};

void List::display() {
	Node * displaynode = head;
	if (displaynode == NULL) {
		cout << "Empty list is provided" << endl;
	}
		while (displaynode != NULL) {
			cout << displaynode->tconst << "\t" << displaynode->titleType << "\t" << displaynode->primaryTitle << "\t" << displaynode->startYear << "\t" << displaynode->runtimeMinutes << "\t" << displaynode->genres[0] << "\t" << displaynode->genres[1] << "\t" << displaynode->genres[2] << endl;
			displaynode = displaynode->next;
			cout << endl;
		}

	cout << endl;

}
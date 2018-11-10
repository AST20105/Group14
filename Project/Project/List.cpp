#include "List.h"

List::List() {
	//create an empty list
	head = NULL;
	tail = NULL;

};


List::~List() {

};

/*void List::createNode(string ptconst, string ptitleType, string pprimaryTitle, string pstartYear, string pruntimeMinutes, string pgenres) {
	Node * temp = new Node;
	temp->tconst = ptconst;
	temp->titleType = ptitleType;
	temp->primaryTitle = pprimaryTitle;
	temp->startYear = pstartYear;
	temp->runtimeMinutes = pruntimeMinutes;
	temp->genres[0] = pgenres;
	temp->genres[1] = pgenres;
	temp->genres[2] = pgenres;
	temp->next = NULL;

	//determine if the list is empty
	if (head == NULL) {
		head = temp;
		tail = temp;
		temp = NULL;
	}
};*/

void List::insertion(string ptconst, string ptitleType, string pprimaryTitle, string pstartYear, string pruntimeMinutes, string pgenres) {
	Node* NewNode = new Node(ptconst, ptitleType, pprimaryTitle, pstartYear, pruntimeMinutes, pgenres);
	if (head == NULL) {
		head = NewNode
	}
	else {
		Node* CurrNode = head;
		for (; CurrNode->next; CurrNode = CurrNode->next);
		CurrNode->next = NewNode;
	}
}

void List::searchingByX(string x) {
	Node* CurrNode = head;
	int counter = 0;
	for (CurrNode = head; CurrNode != NULL; CurrNode = CurrNode->next) {
		if (CurrNode->tconst == x) {
			cout << CurrNode << endl;
			counter++;
		}
	}if (counter == 0) {
		cout << "No data match" << endl;
	}
	else {
		cout << "Number of Data: " << counter << endl;
	}
}

void List::deletion(int x) {
	Node* CurrNode = head, *preNode = NULL;
	for (; CurrNode != NULL && CurrNode->tconst != x; preNode = currNode, CurrNode = CurrNode->next) {
		if (CurrNode->tconst != x) {
			cout << "Data cannot find" << endl;
		}
		else
		{
			preNode->next = CurrNode->next;
			delete CurrNode;
			cout << "Data has been deleted" << endl;
		}
	}
}


	

void List::createfilNode(string ptconst, string ptitleType, string pprimaryTitle, string pstartYear, string pruntimeMinutes, string pgenres, Node * next) {
	filterNode * temp = new filterNode;
	temp->tconst = ptconst;
	temp->titleType = ptitleType;
	temp->primaryTitle = pprimaryTitle;
	temp->startYear = pstartYear;
	temp->runtimeMinutes = pruntimeMinutes;
	temp->genres[0] = pgenres;
	temp->genres[1] = pgenres;
	temp->genres[2] = pgenres;
	temp->next = next;
	temp->filnext = NULL;
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

}

filterNode List::make_Type_List(Node* x, string condition){
	Node *innernodelist = x;
	filterNode * temp = new filterNode;
	for (; innernodelist != NULL;innernodelist=innernodelist->next) {
		if (condition == "short") {
			if (innernodelist->titleType==condition) {
				
			}

		}
	}
	Node *create_table = new Node(innernodelist->tconst, innernodelist->titleType, innernodelist->primaryTitle, innernodelist->startYear, innernodelist->runtimeMinutes, innernodelist->genres);


	return create_table,create_table;
}







void List::insertion() {

}

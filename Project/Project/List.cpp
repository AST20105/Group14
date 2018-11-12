#include "List.h"

List::List() {

	head = NULL;
};

void List::searchingByX(string x) {
	Node* CurrNode = head;
	int counter = 0;
	for (; CurrNode != NULL; CurrNode = CurrNode->next) {
		if (CurrNode->tconst == x) {
			cout << CurrNode->tconst<< "\t" << CurrNode->titleType<< "\t" << CurrNode->primaryTitle<< "\t" << CurrNode->startYear<< "\t" << CurrNode->runtimeMinutes<< "\t" << CurrNode->genres[0]<< "\t" << CurrNode->genres[1]<< "\t" << CurrNode->genres[2] << endl;
			counter++;
		}
	}if (counter == 0) {
		cout << "No data match" << endl;
	}
	else {
		cout << "Number of Data: " << counter << endl;
	}
}

void List::deletion_of_node(string x) {
	Node* CurrNode = head;
	Node *preNode = NULL;
	for (; CurrNode != NULL; preNode = CurrNode, CurrNode = CurrNode->next) {
		if (CurrNode->next == NULL && CurrNode->tconst != x) {
			cout << "Data cannot find" << endl;
			return;
		}
		else if(CurrNode->tconst == x)
		{
			if (CurrNode == head) {
				head = CurrNode->next;
				delete CurrNode;
				cout << "First Data has been deleted" << endl;
				return;
			}
			else {
				preNode->next = CurrNode->next;
				delete CurrNode;
				cout << "Data has been deleted" << endl;
				return;
			}
		}
	}
}


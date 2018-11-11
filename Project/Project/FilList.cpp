#include "FilList.h"
FilList::FilList() {
	filhead = NULL;
}

void FilList::searchingByX(string x) {
	filterNode* CurrNode = filhead;
	int counter = 0;
	for (; CurrNode != NULL; CurrNode = CurrNode->filnext) {
		if (CurrNode->ftconst == x) {
			cout << CurrNode->ftconst << "\t" << CurrNode->ftitleType << "\t" << CurrNode->fprimaryTitle << "\t" << CurrNode->fstartYear << "\t" << CurrNode->fruntimeMinutes << "\t" << CurrNode->fgenres[0] << "\t" << CurrNode->fgenres[1] << "\t" << CurrNode->fgenres[2] << endl;
			counter++;
		}
	}if (counter == 0) {
		cout << "No data match" << endl;
	}
	else {
		cout << "Number of Data: " << counter << endl;
	}
}
void FilList::deletion_of_node(string x) {
	filterNode* CurrNode = filhead;
	filterNode *preNode = NULL;
	for (; CurrNode != NULL; preNode = CurrNode, CurrNode = CurrNode->filnext) {
		if (CurrNode->filnext == NULL && CurrNode->ftconst != x) {
			cout << "Data cannot find" << endl;
			return;
		}
		else if (CurrNode->ftconst == x)
		{
			if (CurrNode == filhead) {
				filhead = CurrNode->filnext;
				delete CurrNode;
				cout << "First Data has been deleted" << endl;
				return;
			}
			else {
				preNode->filnext = CurrNode->filnext;
				delete CurrNode;
				cout << "Data has been deleted" << endl;
				return;
			}
		}
	}
}


void FilList::fildisplay() {
	if (filhead == NULL) {
		cout << "Empty list is provided" << endl;
	}
	filterNode * displaynode = filhead;
	while (displaynode != NULL) {
		cout << displaynode->ftconst << "\t" << displaynode->ftitleType << "\t" << displaynode->fprimaryTitle << "\t" << displaynode->fstartYear << "\t" << displaynode->fruntimeMinutes << "\t" << displaynode->fgenres[0] << "\t" << displaynode->fgenres[1] << "\t" << displaynode->fgenres[2] << endl;
		displaynode = displaynode->filnext;
	}
	cout << endl;

}

FilList FilList::make_Type_List(Node* x, string condition) {
	Node *innernodelist = x;
	FilList *filterNode_list = new FilList();
	filterNode *innerfilhead = filterNode_list->filhead;
	int i = 0;
	for (; innernodelist != NULL; innernodelist = innernodelist->next) {
		if (condition == "short") {
			if (innernodelist->titleType == condition) {
				if (innerfilhead == NULL) {
					filterNode * filterlist = new filterNode(innernodelist->tconst, innernodelist->titleType, innernodelist->primaryTitle, innernodelist->startYear, innernodelist->runtimeMinutes, innernodelist->genres[0], innernodelist->genres[1], innernodelist->genres[2], innernodelist->next);
					filterNode_list->filhead = filterlist;
					innerfilhead = filterNode_list->filhead;
					i++;
				}
				else {
					filterNode * filterlist = new filterNode(innernodelist->tconst, innernodelist->titleType, innernodelist->primaryTitle, innernodelist->startYear, innernodelist->runtimeMinutes, innernodelist->genres[0], innernodelist->genres[1], innernodelist->genres[2], innernodelist->next);
					innerfilhead->filnext = filterlist;
					innerfilhead = innerfilhead->filnext;
					i++;
				}
			}

		}
	}
	cout << i << endl;
	return *(filterNode_list);
}
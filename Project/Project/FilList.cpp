#include "FilList.h"
FilList::FilList() {
	filhead = NULL;
	next = NULL;
}

void FilList::fildisplay(int x) {
	
	filterNode * innerhead = filhead;
	FilList * innernext = next;
	FilList * now = next;
	int targetpos = x;
	if (innerhead == NULL) {
		cout << "Empty list is provided" << endl;
	}
	for (int i = 1; i < targetpos;i++ ){
		if (now != NULL) {
		innerhead = now->filhead;
		now = now->next;
		}
		
		 }//can change to looping to target list
	filterNode * displaynode = innerhead;
	for (int i =0; innerhead!=NULL; innerhead = innerhead->filnext,i++) {
		//if (i == 0) {
			while (displaynode != NULL) {
				cout << displaynode->ftconst << "\t" << displaynode->ftitleType << "\t" << displaynode->fprimaryTitle << "\t" << displaynode->fstartYear << "\t" << displaynode->fruntimeMinutes << "\t" << displaynode->fgenres[0] << "\t" << displaynode->fgenres[1] << "\t" << displaynode->fgenres[2] << endl;
				displaynode = displaynode->filnext;
				cout << endl;
			}
	}
}



void FilList::make_Type_List(Node* x, string condition) {
	Node *innernodelist = x;
	filterNode * innerfilhead = filhead;
	FilList * innernext = next;
	int i = 0;
	
		for (; innernodelist != NULL; innernodelist = innernodelist->next) {
			if (condition == innernodelist->tconst || condition == innernodelist->titleType|| condition == innernodelist->primaryTitle|| condition == innernodelist->startYear || condition == innernodelist->runtimeMinutes||condition == innernodelist->genres[0] || condition == innernodelist->genres[1] || condition == innernodelist->genres[2]) {
					if (filhead == NULL) {
						filterNode * filterlist = new filterNode(innernodelist->tconst, innernodelist->titleType, innernodelist->primaryTitle, innernodelist->startYear, innernodelist->runtimeMinutes, innernodelist->genres[0], innernodelist->genres[1], innernodelist->genres[2], innernodelist->next);
						innerfilhead = filterlist;
						filhead = innerfilhead;
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
	
	if (i==0) {
		filterNode * filterlist = new filterNode("", "", "", "", "", "", "", "", NULL);
		filhead = filterlist;
	}

	
	cout << i << endl;
}

void FilList::make_gen_List2(Node* x, string condition1, string condition2) {
	Node *innernodelist = x;
	filterNode * innerfilhead = filhead;
	FilList * innernext = next;
	int i = 0;

	for (; innernodelist != NULL; innernodelist = innernodelist->next) {
		if ( condition1 == innernodelist->genres[0] || condition1 == innernodelist->genres[1] || condition1 == innernodelist->genres[2] || condition2 == innernodelist->genres[0] || condition2 == innernodelist->genres[1] || condition2 == innernodelist->genres[2]) {
			if (filhead == NULL) {
				filterNode * filterlist = new filterNode(innernodelist->tconst, innernodelist->titleType, innernodelist->primaryTitle, innernodelist->startYear, innernodelist->runtimeMinutes, innernodelist->genres[0], innernodelist->genres[1], innernodelist->genres[2], innernodelist->next);
				innerfilhead = filterlist;
				filhead = innerfilhead;
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

	if (i == 0) {
		filterNode * filterlist = new filterNode("", "", "", "", "", "", "", "", NULL);
		filhead = filterlist;
	}


	cout << i << endl;
}

void FilList::make_gen_List3(Node* x, string condition1, string condition2, string condition3) {
	Node *innernodelist = x;
	filterNode * innerfilhead = filhead;
	FilList * innernext = next;
	int i = 0;

	for (; innernodelist != NULL; innernodelist = innernodelist->next) {
		if (condition1 == innernodelist->genres[0] || condition1 == innernodelist->genres[1] || condition1 == innernodelist->genres[2] || condition2 == innernodelist->genres[0] || condition2 == innernodelist->genres[1] || condition2 == innernodelist->genres[2]|| condition3 == innernodelist->genres[0] || condition3 == innernodelist->genres[1] || condition3 == innernodelist->genres[2]) {
			if (filhead == NULL) {
				filterNode * filterlist = new filterNode(innernodelist->tconst, innernodelist->titleType, innernodelist->primaryTitle, innernodelist->startYear, innernodelist->runtimeMinutes, innernodelist->genres[0], innernodelist->genres[1], innernodelist->genres[2], innernodelist->next);
				innerfilhead = filterlist;
				filhead = innerfilhead;
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

	if (i == 0) {
		filterNode * filterlist = new filterNode("", "", "", "", "", "", "", "", NULL);
		filhead = filterlist;
	}


	cout << i << endl;
}
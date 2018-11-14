#include "FilList.h"
FilList::FilList() {
	filhead = NULL;
	next = NULL;
}

void FilList::fildisplay() {

	filterNode * innerhead = filhead;
	int targetpos = 1;
	if (innerhead == NULL) {
		cout << "Empty list is provided" << endl;
	}
	for (int i = 1; i < targetpos; innerhead = next->filhead) { i++; }//can change to looping to target list
	filterNode * displaynode = innerhead;
	while (displaynode != NULL) {
		cout << displaynode->ftconst << "\t" << displaynode->ftitleType << "\t" << displaynode->fprimaryTitle << "\t" << displaynode->fstartYear << "\t" << displaynode->fruntimeMinutes << "\t" << displaynode->fgenres[0] << "\t" << displaynode->fgenres[1] << "\t" << displaynode->fgenres[2] << endl;
		displaynode = displaynode->filnext;
		cout << endl;
	}
}



void FilList::make_Type_List(Node* x, string condition) {
	Node *innernodelist = x;
	filterNode * innerfilhead = filhead;
	FilList * innernext = next;
	int i = 0;
	if (innerfilhead == NULL) {
		for (; innernodelist != NULL; innernodelist = innernodelist->next) {
			if (condition == "short") {
				if (innernodelist->titleType == condition) {
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
			if (condition == "movie") {
				if (innernodelist->titleType == condition) {
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
		}
	}
	else {
		for (; next != NULL; next = next->next) {}
		FilList * newlist = new FilList();
		filterNode * innernewlisthead = newlist->filhead;
		if (newlist->filhead == NULL) {
			for (; innernodelist != NULL; innernodelist = innernodelist->next) {
				if (condition == "short") {
					if (innernodelist->titleType == condition) {
						if (newlist->filhead == NULL) {
							filterNode * filterlist = new filterNode(innernodelist->tconst, innernodelist->titleType, innernodelist->primaryTitle, innernodelist->startYear, innernodelist->runtimeMinutes, innernodelist->genres[0], innernodelist->genres[1], innernodelist->genres[2], innernodelist->next);
							innernewlisthead = filterlist;
							newlist->filhead = innernewlisthead;
							i++;
						}
						else {
							filterNode * filterlist = new filterNode(innernodelist->tconst, innernodelist->titleType, innernodelist->primaryTitle, innernodelist->startYear, innernodelist->runtimeMinutes, innernodelist->genres[0], innernodelist->genres[1], innernodelist->genres[2], innernodelist->next);
							innernewlisthead->filnext = filterlist;
							innernewlisthead = innernewlisthead->filnext;
							i++;
						}
					}
				}
				if (condition == "movie") {
					if (innernodelist->titleType == condition) {
						if (newlist->filhead == NULL) {
							filterNode * filterlist = new filterNode(innernodelist->tconst, innernodelist->titleType, innernodelist->primaryTitle, innernodelist->startYear, innernodelist->runtimeMinutes, innernodelist->genres[0], innernodelist->genres[1], innernodelist->genres[2], innernodelist->next);
							innernewlisthead = filterlist;
							newlist->filhead = innernewlisthead;
							i++;
						}
						else {
							filterNode * filterlist = new filterNode(innernodelist->tconst, innernodelist->titleType, innernodelist->primaryTitle, innernodelist->startYear, innernodelist->runtimeMinutes, innernodelist->genres[0], innernodelist->genres[1], innernodelist->genres[2], innernodelist->next);
							innernewlisthead->filnext = filterlist;
							innernewlisthead = innernewlisthead->filnext;
							i++;
						}
					}
				}
				next = newlist;
			}
		}
	}
	cout << i << endl;
}
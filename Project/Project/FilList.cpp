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
		innerhead = now->filhead;
		now = now->next;
		 }//can change to looping to target list
	filterNode * displaynode = innerhead;
	for (int i =0; innerhead!=NULL; innerhead = innerhead->filnext,i++) {
		//if (i == 0) {
			while (displaynode != NULL) {
				cout << displaynode->ftconst << "\t" << displaynode->ftitleType << "\t" << displaynode->fprimaryTitle << "\t" << displaynode->fstartYear << "\t" << displaynode->fruntimeMinutes << "\t" << displaynode->fgenres[0] << "\t" << displaynode->fgenres[1] << "\t" << displaynode->fgenres[2] << endl;
				displaynode = displaynode->filnext;
				cout << endl;
			}
		//}
		/*else {
			if (innernext->filhead != NULL) {
				displaynode = innernext->filhead;
				//while (displaynode != NULL) {
					cout << displaynode->ftconst << "\t" << displaynode->ftitleType << "\t" << displaynode->fprimaryTitle << "\t" << displaynode->fstartYear << "\t" << displaynode->fruntimeMinutes << "\t" << displaynode->fgenres[0] << "\t" << displaynode->fgenres[1] << "\t" << displaynode->fgenres[2] << endl;
					displaynode = displaynode->filnext;
					cout << endl;
				//}
				innernext = innernext->next;
			}
		}*/
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

	/*else {
		for (; next != NULL; next = next->next) {}
		FilList * newlist = new FilList();
		filterNode * innernewlisthead = newlist->filhead;
		if (newlist->filhead == NULL) {
			for (; innernodelist != NULL; innernodelist = innernodelist->next) {
				if (condition == innernodelist->tconst || condition == innernodelist->titleType || condition == innernodelist->primaryTitle || condition == innernodelist->startYear || condition == innernodelist->runtimeMinutes || condition == innernodelist->genres[0] || condition == innernodelist->genres[1] || condition == innernodelist->genres[2]) {
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
							next = newlist;
						}
				}
			
			}
			if (i == 0) {
				filterNode * filterlist = new filterNode("", "", "", "", "", "", "", "", NULL);
				innerfilhead = filterlist;
			}
		}
	}*/
	cout << i << endl;
}


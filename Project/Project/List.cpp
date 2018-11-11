#include "List.h"
#include "Node.h"

List::List() {

	head = NULL;

};


List::~List() {

};


void List::fileinput() {
	Node * innerhead = head;
	string tconst;
	string titleType;
	string primaryTitle;
	string startYear;
	string runtimeMinutes;
	string genres[3];
	ifstream dataSet;
	string filename = " ";
	cout << "Which dataSet you want to input?" << endl;
	cout << "Filename: ";
	cin >> filename;
	cout << endl;

	dataSet.open(filename);
	if (!(dataSet.is_open())) {
		cerr << "Error. The file doesn't open correctly." << endl;
	}
	else {
		do
		{
			getline(dataSet, tconst, '\t');
			getline(dataSet, titleType, '\t');
			getline(dataSet, primaryTitle, '\t');
			getline(dataSet, startYear, '\t');
			getline(dataSet, runtimeMinutes, '\t');
			string originalgenre = " ";
			string symbol = "\"";
			string symbolofnothing = "\N";
			getline(dataSet, originalgenre, '\n');
			if ((originalgenre.substr(0, 1) != symbol) && (originalgenre.substr(0, 2) != symbolofnothing)) {
				genres[0] = originalgenre;
				genres[1] = " ";
				genres[2] = " ";
			}
			else if (originalgenre.substr(1, 2) == symbolofnothing) {
				genres[0] = " ";
				genres[1] = " ";
				genres[2] = " ";
			}
			else {
				int count = 0;
				for (int i = 0; i < originalgenre.size(); i++) {
					if (originalgenre[i] == ',') {
						count++;
					}
				}
				if (count == 1) {
					int remPos = 0;
					remPos = originalgenre.find(",");
					genres[0] = originalgenre.substr(1, remPos - 1);
					genres[1] = originalgenre.substr(remPos + 1, originalgenre.length() - remPos - 2);
					genres[2] = " ";
				}
				else if (count == 2) {
					int remPos = 0;
					remPos = originalgenre.find(",");
					genres[0] = originalgenre.substr(1, remPos - 1);

					int remPos2 = 0;
					remPos2 = originalgenre.find_last_of(",");
					genres[1] = originalgenre.substr(remPos + 1, remPos2 - remPos - 1);


				}
			}
			if (head == NULL) {
				Node * mainlist = new Node(tconst, titleType, primaryTitle, startYear, runtimeMinutes, genres[0], genres[1], genres[2]);
				head = mainlist;
				innerhead = head;
			}
			else {
				Node * mainlist = new Node(tconst, titleType, primaryTitle, startYear, runtimeMinutes, genres[0], genres[1], genres[2]);
				innerhead->next = mainlist;
				innerhead = innerhead->next;
			}
		} while (!dataSet.eof());
	}
};


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

void List::deletion(string x) {
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

/*filterNode List::make_Type_List(Node* x, string condition){
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

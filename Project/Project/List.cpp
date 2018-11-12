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






















void List::MainDecision(int x) {
	switch (x)
	{
	case 0: return;
	case 1:	cout << "xxx";
	case 2:	List::MakeSearchingChoice;
	case 3: List::MakeDeletionChoice;
	default: MainDecision(x);
	}
}



void List::MakeSearchingChoice() {
	int y;
	cout << "1. By ID		2. By Name		3. By Year		4. By Programe Type		5.By Movie Type		0. Stop Searching" << endl;
	cin >> y;
	switch (y)
	{
	case 0: return;
	case 1: searchingByID;
	case 2: searchingByName;
	case 3: searchingByYear;
	case 4: searchingByPgType;
	case 5: //
	default: MakeSearchingChoice;
	}
}



void List::searchingByID() {
	string x;
	cout << "Enter the ID of the data" << endl;
	cin >> x;
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


void List::searchingByName() {
	string x;
	cout << "Enter the Name of the data" << endl;
	cin >> x;
	Node* CurrNode = head;
	int counter = 0;
	for (CurrNode = head; CurrNode != NULL; CurrNode = CurrNode->next) {
		if (CurrNode->primaryTitle.find(x) != string::npos) {
			cout << CurrNode << endl;
		}
	}if (counter == 0) {
		cout << "No data match" << endl;
	}
	else {
		cout << "Number of Data: " << counter << endl;
	}
}


void List::searchingByYear() {
	string x;
	cout << "Enter the Year of the data" << endl;
	cin >> x;
	Node* CurrNode = head;
	int counter = 0;
	for (CurrNode = head; CurrNode != NULL; CurrNode = CurrNode->next) {
		if (CurrNode->startYear == x) {
			cout << CurrNode;
			counter++;
		}
	}
	if (counter == 0) {
		cout << "No data match" << endl;
	}
	else {
		cout << "Number of Data: " << counter << endl;
	}
}


void List::searchingByPgType() {
	int x;
	cout << "Which programme type?" << endl;
	cout << "1. short	2. movie	3. tvseries		4. tvepisode	5. video	0. End" << endl;
	cin >> x;
	switch (x)
	{
	case 0: return;
	case 1: cout << ""; //shortlist
	case 2: cout << ""; //movielist
	case 3: cout << ""; //tvserieslist
	case 4: cout << ""; //tvepisode
	case 5:	cout << ""; //videolist
	default: searchingByPgType();
	}
}

void List::searchingByType() {
	string x;
	cout << "Enter the Type of the data" << endl;
	cin >> x;
	Node* CurrNode = head;
	int counter = 0;
	for (CurrNode = head; CurrNode != NULL; CurrNode = CurrNode->next) {
		for (int i = 0; i < sizeof(CurrNode->genres); i++) {
			if (CurrNode->genres[i] == x) {
				cout << CurrNode;
				counter++;
			}
		}
	}
	if (counter == 0) {
		cout << "No data match" << endl;
	}
	else {
		cout << "Number of Data: " << counter << endl;
	}
}


void List::MakeDeletionChoice() {
	int x;
	cout << "1. By ID		2. By Name		3. By Year		4. By Programe Type		5.By Movie Type		0. Stop Searching" << endl;
	cin >> x;
	switch (x)	
	{
	case 0: return;
	case 1: DeletionByID;
	case 2: DeletionByName;
	case 3: DeletionByYear;
	case 4: //
	case 5: //
	default: MakeDeletionChoice;
	}
}


void List::DeletionByID() {
	string x;
	cout << "Enter the ID of the data" << endl;
	cin >> x;
	Node* CurrNode = head, *preNode = NULL;
	for (; CurrNode != NULL && CurrNode->tconst != x; preNode = CurrNode, CurrNode = CurrNode->next);
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

void List::DeletionByName() {
	string x;
	cout << "Enter the Name of the data" << endl;
	cin >> x;
	Node* CurrNode = head, *preNode = NULL;
	for (; CurrNode != NULL && CurrNode->primaryTitle != x; preNode = CurrNode, CurrNode = CurrNode->next);
	if (CurrNode->primaryTitle != x) {
		cout << "Data cannot find" << endl;
	}
	else {
		preNode->next = CurrNode->next;
		delete CurrNode;
		cout << "Data hase been deleted" << endl;
	}
}


void List::DeletionByYear() {
	string x;
	cout << "Enter the Year of the data" << endl;
	cin >> x;
	Node* CurrNode = head, *preNode = NULL;
	int counter = 0;
	for (CurrNode = head; CurrNode->next != NULL; preNode = CurrNode, CurrNode = CurrNode->next) {
		if (CurrNode->startYear == x) {
			preNode->next = CurrNode->next;
			delete CurrNode;
			counter++;
		}
	}
	if (counter == 0) {
		cout << "No data match" << endl;
	}
	else {
		cout << "Number of data deleted: " << counter << endl;
	}
}



/*void List::Statistical(string x){
	Node * CurrNode = head;
	int counter = 0;
	for (; CurrNode->next != NULL; CurrNode = CurrNode->next) {
		if (CurrNode->titleType == x) {
			counter++;
		}
	}
	if (counter == 0) {
		cout << "No data match" << endl;
	}
	else {
		cout << "There are total " << counter << " movie for " << x << endl;
	}
}*/






/*void List::InsertionBytitleType(string x) {
	Node * CurrNode = head;
	Node * TypeNode = NULL;
	int counter = 0;
	for (; CurrNode->next != NULL; CurrNode = CurrNode->next) {
		if (CurrNode->primaryTitle == x) {
			TypeNode = new Node (CurrNode->tconst, CurrNode->titleType, CurrNode->primaryTitle, CurrNode->startYear, CurrNode->runtimeMinutes, CurrNode->genres[0], CurrNode->genres[1], CurrNode->genres[2]);
			TypeNode = TypeNode->next;
			counter++;
		}
	}if (counter == 0) {
		cout << "No data match" << endl;
	}
	else {
		cout << "Number of data inserted: " << counter << endl;
	}
}*/




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
*/


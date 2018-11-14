#include "List.h"
#include "Node.h"

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





















/*void List::MainDecision() {
	int choice;
	cout << "*************************************************************" << endl;
	cout << "Welcome to the program, it use for searching and update data." << endl;
	cout << "*************************************************************" << endl;
	cout << "Choose What function you want to do " << endl;
	cout << "0. End		1. Insertion		2. Searching		3. Deletion" << endl;
	cin >> choice;
	switch (choice)
	{
	case 0: return;
	case 1:	fileinput(); MainDecision();
	case 2:	MakeSearchingChoice();
	case 3: MakeDeletionChoice();
	default: cout << "wrong input" << endl;	system("pause"); system("cls"); MainDecision();
	}
}



void List::MakeSearchingChoice() {
	int y;
	cout << "1. By ID		2. By Name		3. By Year		4. By Programe Type		5.By Movie Type		0. Stop Searching" << endl;
	cin >> y;
	switch (y)
	{
	case 0: return;
	case 1: searchingByID();
	case 2: searchingByName();
	//case 3: searchingByYear;
	case 4: searchingByPgType();
	case 5: //
	default: MakeSearchingChoice();
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
	case 1: DeletionByID();
	case 2: DeletionByName();
	case 3: DeletionByYear();
	case 4: //
	case 5: //
	default: MakeDeletionChoice();
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
}*/





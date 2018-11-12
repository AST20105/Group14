#include "DataSetlist.h"



DataSetlist::DataSetlist()
{
	DataSethead = new DataSet();
}

void DataSetlist::fileinput() {
	DataSet * outerhead = DataSethead;
	Node * innerhead = DataSethead->listSet->head;
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
		if (DataSethead->listSet->head == NULL) {
			do
			{
				getline(dataSet, tconst, '\t');
				getline(dataSet, titleType, '\t');
				getline(dataSet, primaryTitle, '\t');
				getline(dataSet, startYear, '\t');
				getline(dataSet, runtimeMinutes, '\t');

				string originalgenre = " ";
				string symbol = "\"";
				string symbolofnothing = symbol;


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

						genres[2] = originalgenre.substr(remPos2 + 1, originalgenre.length() - remPos2 - 2);

					}
				}
				if (innerhead == NULL) {
					Node * mainlist = new Node(tconst, titleType, primaryTitle, startYear, runtimeMinutes, genres[0], genres[1], genres[2]);
					DataSethead->listSet->head = mainlist;
					innerhead = DataSethead->listSet->head;
				}
				else {
					Node * mainlist = new Node(tconst, titleType, primaryTitle, startYear, runtimeMinutes, genres[0], genres[1], genres[2]);
					innerhead->next = mainlist;
					innerhead = innerhead->next;
				}
			} while (!dataSet.eof());
		}
		else {

			for (; outerhead->next != NULL; outerhead = outerhead->next) {}
			DataSet * newset = new DataSet();
			Node * innernewset = newset->listSet->head;
			do
			{
				getline(dataSet, tconst, '\t');
				getline(dataSet, titleType, '\t');
				getline(dataSet, primaryTitle, '\t');
				getline(dataSet, startYear, '\t');
				getline(dataSet, runtimeMinutes, '\t');

				string originalgenre = " ";
				string symbol = "\"";
				string symbolofnothing = symbol;


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

						genres[2] = originalgenre.substr(remPos2 + 1, originalgenre.length() - remPos2 - 2);

					}
				}
				if (newset->listSet->head == NULL) {
					Node * mainlist = new Node(tconst, titleType, primaryTitle, startYear, runtimeMinutes, genres[0], genres[1], genres[2]);
					newset->listSet->head = mainlist;
					innernewset = newset->listSet->head;
				}
				else {
					Node * mainlist = new Node(tconst, titleType, primaryTitle, startYear, runtimeMinutes, genres[0], genres[1], genres[2]);
					innernewset->next = mainlist;
					innernewset = innernewset->next;
				}
			} while (!dataSet.eof());
			outerhead->next = newset;
		}
	}
};

void DataSetlist::display() {
	Node * displaynode = DataSethead->listSet->head;
	if (displaynode == NULL) {
		cout << "Empty list is provided" << endl;
	}
	if (DataSethead != NULL) {
		while (displaynode != NULL) {
			cout << displaynode->tconst << "\t" << displaynode->titleType << "\t" << displaynode->primaryTitle << "\t" << displaynode->startYear << "\t" << displaynode->runtimeMinutes << "\t" << displaynode->genres[0] << "\t" << displaynode->genres[1] << "\t" << displaynode->genres[2] << endl;
			displaynode = displaynode->next;
			cout << endl;
		}
		DataSet * displayset1 = DataSethead->next;
		while (displayset1 != NULL) {
			Node * displaynode1 = displayset1->listSet->head;
			while (displaynode1 != NULL) {
				cout << displaynode1->tconst << "\t" << displaynode1->titleType << "\t" << displaynode1->primaryTitle << "\t" << displaynode1->startYear << "\t" << displaynode1->runtimeMinutes << "\t" << displaynode1->genres[0] << "\t" << displaynode1->genres[1] << "\t" << displaynode1->genres[2] << endl;
				displaynode1 = displaynode1->next;
				cout << endl;
			}
			displayset1 = displayset1->next;
		}
	}
	cout << endl;


}

void DataSetlist::MainDecision(){
	int choice;
	cout << "*************************************************************" << endl;
	cout << "Welcome to the program, it use for searching and update data." << endl;
	cout << "*************************************************************" << endl;
	cout << "Choose What function you want to do " << endl;
	cout << "0. End		1. Insertion	2. Searching	3. Deletion" << endl;
	cin >> choice;
	switch (choice)
	{
	case 0: return;
	case 1:	fileinput(); display(); system("pause"); system("cls"); MainDecision();
	case 2:	MangeInDataSetSearch(); system("pause"); system("cls"); MainDecision();
	case 3: MangeInDataSetDelete(); system("pause"); system("cls"); MainDecision();
	default: cout << "wrong input" << endl;	system("pause"); system("cls"); MainDecision(); 
	}
}



void DataSetlist::MangeInDataSetSearch() {
	int counter = 0;
	int x;
	bool check = false;
	DataSet* CurrNode = DataSethead;
	cout << "which DataSet you want to modify" << endl;
	for (CurrNode = DataSethead; CurrNode != NULL; CurrNode=CurrNode->next) {
		counter++;
		cout << "DataSet " << counter << endl;
	}
	cin >> x;
	counter = 0;
	for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
		counter++;
		if (counter == x) {
			check = true;
			break;
		}
	}
	if (check == false) {
		cout << "Wrong input" << endl;
		MangeInDataSetSearch();
	}
	else {
		MakeSearchingChoice(x);
	}
}



void DataSetlist::MangeInDataSetDelete() {
	int counter = 0;
	int x;
	bool check = false;
	DataSet* CurrNode = DataSethead;
	cout << "which DataSet you want to modify" << endl;
	for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
		counter++;
		cout << "DataSet " << counter << endl;
	}
	cin >> x;
	counter = 0;
	for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
		counter++;
		if (counter == x) {
			check = true;
			break;
		}
	}
	if (check == false) {
		cout << "Wrong input" << endl;
		MangeInDataSetSearch();
	}
	else {
		MakeDeletionChoice(x);
	}
}



void DataSetlist::MakeSearchingChoice(int x) {
	int y;
	cout << "1. By ID	2. By Name	3. By Year	4. By Programe Type	 5.By Movie Type	0. Stop Searching" << endl;
	cin >> y;
	switch (y)
	{
	case 0: return;
	case 1: searchingByID(x); MainDecision();
	case 2: searchingByName(); MainDecision();
	case 3: searchingByYear(); MainDecision();
	case 4: searchingByPgType(); MainDecision();
	case 5: //
	default: MakeSearchingChoice(x); MainDecision();
	}
}




void DataSetlist::searchingByID(int x) {
	string y;
	cout << "Enter the ID of the data" << endl;
	cin >> y;
	cout << "*************************************************************" << endl;
	int counter = 0;
	DataSet* CurrNode = DataSethead;
	for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
		counter++;
		if (counter == x) {
			break;
		}
	}


	counter = 0;
	Node* CurrNode1 = CurrNode->listSet->head;
	for (CurrNode1 = CurrNode->listSet->head; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		if (CurrNode1->tconst == y) {
			cout << CurrNode1->tconst<<"\t"<<CurrNode1->titleType<<"\t"<< CurrNode1->primaryTitle<<"\t"<< CurrNode1->startYear<<"\t"<< CurrNode1->runtimeMinutes<<"\t"<< CurrNode1->genres[0]<<"\t"<< CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			counter++;
		}
	}if (counter == 0) {
		cout << "No data match" << endl;
	}
	else {
		cout << "Number of Data: " << counter << endl;
	}
}



void DataSetlist::searchingByName() {
	string x;
	cout << "Enter the Name of the data" << endl;
	cin >> x;
	Node* CurrNode = DataSethead->listSet->head;
	int counter = 0;
	for (CurrNode = DataSethead->listSet->head; CurrNode != NULL; CurrNode = CurrNode->next) {
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


void DataSetlist::searchingByYear() {
	string x;
	cout << "Enter the Year of the data" << endl;
	cin >> x;
	Node* CurrNode = DataSethead->listSet->head;
	int counter = 0;
	for (CurrNode = DataSethead->listSet->head; CurrNode != NULL; CurrNode = CurrNode->next) {
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


void DataSetlist::searchingByPgType() {
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


void DataSetlist::searchingByType() {
	string x;
	cout << "Enter the Type of the data" << endl;
	cin >> x;
	Node* CurrNode = DataSethead->listSet->head;
	int counter = 0;
	for (CurrNode = DataSethead->listSet->head; CurrNode != NULL; CurrNode = CurrNode->next) {
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




void DataSetlist::MakeDeletionChoice(int x) {
	int y;
	cout << "1. By ID		2. By Name		3. By Year		4. By Programe Type		5.By Movie Type		0. Stop Searching" << endl;
	cin >> y;
	switch (y)
	{
	case 0: return;
	case 1: DeletionByID(x); MainDecision();
	case 2: DeletionByName(); MainDecision();
	case 3: DeletionByYear(); MainDecision();
	case 4: //
	case 5: //
	default: MakeDeletionChoice(x);
	}
}



void DataSetlist::DeletionByID(int x) {
	string y;
	cout << "Enter the ID of the data" << endl;
	cin >> y;
	cout << "*************************************************************" << endl;
	int counter = 0;
	DataSet* CurrNode = DataSethead;
	for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
		counter++;
		if (counter == x) {
			break;
		}
	}
	Node* CurrNode1 = CurrNode->listSet->head;
	Node *preNode = NULL;
	for (; CurrNode1 != NULL && CurrNode1->tconst != y; preNode = CurrNode1, CurrNode1 = CurrNode1->next);
	if (CurrNode1->tconst != y) {
		cout << "Data cannot find" << endl;
	}
	else
	{
		if (preNode == NULL && CurrNode1->tconst == y) {
			CurrNode->listSet->head = CurrNode1->next;
			cout << "Data has been deleted" << endl;
		}
		else {
			preNode->next = CurrNode1->next;
			delete CurrNode1;
			cout << "Data has been deleted" << endl;
		}
	}
	for (CurrNode1 = CurrNode->listSet->head; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
	}
}


void DataSetlist::DeletionByName() {
	string x;
	cout << "Enter the Name of the data" << endl;
	cin >> x;
	Node* CurrNode = DataSethead->listSet->head, *preNode = NULL;
	for (CurrNode = DataSethead->listSet->head; CurrNode != NULL && CurrNode->primaryTitle != x; preNode = CurrNode, CurrNode = CurrNode->next);
	if (CurrNode->primaryTitle != x) {
		cout << "Data cannot find" << endl;
	}
	else {
		preNode->next = CurrNode->next;
		delete CurrNode;
		cout << "Data hase been deleted" << endl;
	}
}


void DataSetlist::DeletionByYear() {
	string x;
	cout << "Enter the Year of the data" << endl;
	cin >> x;
	Node* CurrNode = DataSethead->listSet->head, *preNode = NULL;
	int counter = 0;
	for (CurrNode = DataSethead->listSet->head; CurrNode->next != NULL; preNode = CurrNode, CurrNode = CurrNode->next) {
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
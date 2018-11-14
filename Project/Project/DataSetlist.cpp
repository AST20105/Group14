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

	int lastdatasetpos = 0;


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
}



void DataSetlist::MainDecision(){
	DataSet * InnerDataSetHead = DataSethead;
	int choice;
	cout << "*************************************************************" << endl;
	cout << "Welcome to the program, it use for searching and update data." << endl;
	cout << "*************************************************************" << endl;
	cout << "Choose What function you want to do " << endl;
	cout << "0. End		1. Insertion	2. Searching	3. Deletion" << endl;
	cin >> choice;
	switch (choice)
	{
	case 0: system("cls"); cout << "Thanks for using our program!!" << endl; system("pause"); exit(0);
	case 1:	fileinput(); for (; InnerDataSetHead->next != NULL; InnerDataSetHead = InnerDataSetHead->next); InnerDataSetHead->listSet->display(); system("pause"); InnerDataSetHead->filListSet->make_Type_List(InnerDataSetHead->listSet->head, "short"); InnerDataSetHead->filListSet->fildisplay(); system("pause"); system("cls"); MainDecision();
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
	cout << "*************************************************************" << endl;
	cin >> x;
	cout << "*************************************************************" << endl;
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
		MakeDeletionChoice();
	}
}



void DataSetlist::MakeSearchingChoice(int x) {
	int y;
	cout << "1. By ID	2. By Name	3. By Year	4. By Programe Type	 5.By Movie Type	0. Stop Searching" << endl;
	cin >> y;
	switch (y)
	{
	case 0: return;
	case 1: searchingByID(); MainDecision();
	case 2: searchingByName(); MainDecision();
	case 3: searchingByYear(); MainDecision();
	//case 4: searchingByPgType(); MainDecision();
	case 5: //
	default: MakeSearchingChoice(x); MainDecision();
	}
}




/*void DataSetlist::searchingByID() {
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
	for (; CurrNode1 != NULL && CurrNode1->tconst != y; CurrNode1 = CurrNode1->next);
		if (CurrNode1->tconst == y) {
			cout << CurrNode1->tconst<<"\t"<<CurrNode1->titleType<<"\t"<< CurrNode1->primaryTitle<<"\t"<< CurrNode1->startYear<<"\t"<< CurrNode1->runtimeMinutes<<"\t"<< CurrNode1->genres[0]<<"\t"<< CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			counter++;
		}
	if (counter == 0) {
		cout << "*************************************************************" << endl;
		cout << "No data match" << endl;
	}
	else {
		cout << "*************************************************************" << endl;
		cout << "Number of Data: " << counter << endl;
	}
}*/

Node* DataSetlist::searchingByID(DataSet * CurrNode, Node * CurrNode1, string pID, int counter) {
	if (CurrNode1 != NULL && CurrNode1->tconst != pID && CurrNode1->tconst == pID) {
		CurrNode1 = CurrNode->listSet->head;
		cout << CurrNode1->tconst<<"\t"<<CurrNode1->titleType<<"\t"<< CurrNode1->primaryTitle<<"\t"<< CurrNode1->startYear<<"\t"<< CurrNode1->runtimeMinutes<<"\t"<< CurrNode1->genres[0]<<"\t"<< CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
		CurrNode1 = CurrNode1->next;
		counter++;
		return CurrNode1;
	}
		CurrNode1->next = searchingByID(CurrNode->next, CurrNode1->next, pID, counter + 1);
		return CurrNode1;
}


void DataSetlist::searchingByName() {

	string y;
	cout << "Enter the Name of the data" << endl;
	cin.ignore();
	getline(cin, y);
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
	for (; CurrNode1 != NULL && CurrNode1->primaryTitle != y; CurrNode1 = CurrNode1->next);
		if (CurrNode1->primaryTitle == y) {
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			counter++;
		}
	if (counter == 0) {
		cout << "*************************************************************" << endl;
		cout << "No data match" << endl;
	}
	else {
		cout << "*************************************************************" << endl;
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


void DataSetlist::MakeDeletionChoice() {
	int y;
	cout << "1. By ID		2. By Name		3. By Year		4. By Programe Type		5.By Movie Type		0. Stop Searching" << endl;
	cin >> y;
	switch (y)
	{
	case 0: return;
	case 1: DeletionByID(); MainDecision();
	case 2: DeletionByName(); MainDecision();
	case 3: DeletionByYear(); MainDecision();
	case 4: //
	case 5: //
	default: MakeDeletionChoice();
	}
}



void DataSetlist::DeletionByID() {
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
		cout << "*************************************************************" << endl;
		cout << "Data cannot find" << endl;
	}
	else
	{
		if (preNode == NULL && CurrNode1->tconst == y) {
			CurrNode->listSet->head = CurrNode1->next;
			cout << "*************************************************************" << endl;
			cout << "Data has been deleted" << endl;
		}
		else {
			preNode->next = CurrNode1->next;
			delete CurrNode1;
			cout << "*************************************************************" << endl;
			cout << "Data has been deleted" << endl;
		}
	}
	for (CurrNode1 = CurrNode->listSet->head; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
	}
}

void DataSetlist::DeletionByName() {
	string y;
	cout << "Enter the Name of the data" << endl;
	cin.ignore();
	getline(cin,y);
	cout << "*************************************************************" << endl;
	int counter = 0;
	DataSet* CurrNode = DataSethead;
	/*for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
		counter++;
		if (counter == x) {
			break;
		}
	}*/
	Node* CurrNode1 = CurrNode->listSet->head;
	Node *preNode = NULL;
	for (; CurrNode1 != NULL &&CurrNode1->primaryTitle != y; preNode = CurrNode1, CurrNode1 = CurrNode1->next);
	if (CurrNode1->primaryTitle != y) {
		cout << "*************************************************************" << endl;
		cout << "Data cannot find" << endl;
	}
	else
	{
		if (preNode == NULL && CurrNode1->primaryTitle == y) {
			CurrNode->listSet->head = CurrNode1->next;
			cout << "*************************************************************" << endl;
			cout << "Data has been deleted" << endl;
		}
		else {
			preNode->next = CurrNode1->next;
			delete CurrNode1;
			cout << "*************************************************************" << endl;
			cout << "Data has been deleted" << endl;
		}
	}
	for (CurrNode1 = CurrNode->listSet->head; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
	}
}


void DataSetlist::DeletionByYear() {
	string x;
	cout << "Enter the Year of the data" << endl;
	cin >> x;
	Node * CurrNode = DataSethead->listSet->head, *preNode = NULL;
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
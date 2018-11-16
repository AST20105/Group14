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
	case 1:	fileinput(); /*for (; InnerDataSetHead->next != NULL; InnerDataSetHead = InnerDataSetHead->next); InnerDataSetHead->listSet->display(); system("pause"); InnerDataSetHead->filListSet->make_Type_List(InnerDataSetHead->listSet->head, "short"); InnerDataSetHead->filListSet->fildisplay();*/ system("pause"); system("cls"); MainDecision();
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


void DataSetlist::MakeSearchingChoice(int x) {
	int y;
	cout << "1. By ID	2. By Name	3. By Year	4. By Programe Type	 5.By Movie Type	0. Stop Searching" << endl;
	cin >> y;
	switch (y)
	{
	case 0: return;
	case 1: searchingByID(x); MainDecision();
	case 2: searchingByName(x); MainDecision();
	case 3: searchingByYear(x); MainDecision();
	//case 4: searchingByPgType(); MainDecision();
	case 5: NumberOfType(x); MainDecision();
	default: cout << "wrong input." << endl; MakeSearchingChoice(x); MainDecision();
	}
}




void DataSetlist::searchingByID(int x) {
	string y;
	cout << "Enter the ID of the data" << endl;
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
	for (; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		if (y.compare(CurrNode1->tconst) == 0) {
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			counter++;
			break;
		}
	}
	if (counter == 0) {
		cout << "No data found" << endl;
	}
	else {
		cout << "Number of Data: " << counter << endl;
	}
}



void DataSetlist::searchingByName(int x) {
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
	for (; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		if (y.compare(CurrNode1->primaryTitle) == 0) {
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			counter++;
			break;
		}
	}
	if (counter == 0) {
		cout << "No data found" << endl;
	}
	else {
		cout << "Number of data: " << counter << endl;
	}

}



void DataSetlist::searchingByYear(int x) {
	string y;
	cout << "Enter the Year of the data" << endl;
	cin >> y;
	cout << "*************************************************************" << endl;
	int	counter = 0;
	DataSet* CurrNode = DataSethead;
	for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
		counter++;
		if (counter == x) {
			break;
		}
	}

	counter = 0;
	Node* CurrNode1 = CurrNode->listSet->head;
	for (; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		if (y.compare(CurrNode1->startYear) == 0) {
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			counter++;
		}
	}
	if (counter == 0) {
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

void DataSetlist::NumberOfType(int x) {
	int y;
	cout << "How many type U want to input? Maximun: 3. " << endl;
	cin >> y;
	switch (y) {
	case 1: searchingByType1(x); MainDecision();
	case 2: searchingByType2(x); MainDecision();
	case 3: searchingByType3(x); MainDecision();
	default: NumberOfType(x);
	}

}

void DataSetlist::searchingByType1(int x) {
	string y;
	cout << "Enter the type of the data: " << endl;
	cin.ignore();
	getline(cin, y);
	cout << "*************************************************************" << endl;
	int	counter = 0;
	DataSet* CurrNode = DataSethead;
	for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
		counter++;
		if (counter == x) {
			break;
		}
	}

	counter = 0;
	Node * CurrNode1 = CurrNode->listSet->head;
	for (; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		for (int i = 0; i < 3; i++) {
			if (y.compare(CurrNode1->genres[i]) == 0) {
				cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
				counter++;
				break;
			}
		}
	}
	if (counter == 0) {
		cout << "No data match" << endl;
		cout << "*************************************************************" << endl;
	}
	else {
		cout << "Number of Data: " << counter << endl;
		cout << "*************************************************************" << endl;
	}
}

void DataSetlist::searchingByType2(int x) {
	string j,k;
	cout << "Enter the first type of the data: " << endl;
	cin.ignore();
	getline(cin, j);
	cout << "*************************************************************" << endl;
	cout << "Enter the second type of the data: " << endl;
	getline(cin, k);
	cout << "*************************************************************" << endl;
	int	counter = 0;
	DataSet* CurrNode = DataSethead;
	for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
		counter++;
		if (counter == x) {
			break;
		}
	}

	counter = 0;
	Node * CurrNode1 = CurrNode->listSet->head;
	for (; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		for (unsigned int i = 0; i < 3; i++) {
			if ((j.compare(CurrNode1->genres[i]) == 0)|| (k.compare(CurrNode1->genres[i]) == 0)) {
				cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
				counter++;
				break;
			}
		}
	}
	if (counter == 0) {
		cout << "No data match" << endl;
		cout << "*************************************************************" << endl;
	}
	else {
		cout << "Number of Data: " << counter << endl;
		cout << "*************************************************************" << endl;
	}
}

void DataSetlist::searchingByType3(int x) {
	string j, k,l;
	cout << "Enter the first type of the data: " << endl;
	cin.ignore();
	getline(cin, j);
	cout << "*************************************************************" << endl;
	cout << "Enter the second type of the data: " << endl;
	getline(cin, k);
	cout << "*************************************************************" << endl;
	cout << "Enter the third type of the data: " << endl;
	getline(cin, l);
	cout << "*************************************************************" << endl;
	int	counter = 0;
	DataSet* CurrNode = DataSethead;
	for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
		counter++;
		if (counter == x) {
			break;
		}
	}

	counter = 0;
	Node * CurrNode1 = CurrNode->listSet->head;
	for (; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		for (unsigned int i = 0; i < 3; i++) {
			if (j.compare(CurrNode1->genres[i]) == 0 || k.compare(CurrNode1->genres[i]) == 0 || l.compare(CurrNode1->genres[i]) == 0) {
				cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
				counter++;
				break;
			}
		}
	}
	if (counter == 0) {
		cout << "No data match" << endl;
		cout << "*************************************************************" << endl;
	}
	else {
		cout << "Number of Data: " << counter << endl;
		cout << "*************************************************************" << endl;
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

void DataSetlist::MakeDeletionChoice(int x) {
	int y;
	cout << "1. By ID		2. By Name		3. By Year		4. By Programe Type		5.By Movie Type		0. Stop Searching" << endl;
	cin >> y;
	switch (y)
	{
	case 0: return;
	case 1: DeletionByID(x); MainDecision();
	case 2: DeletionByName(x); MainDecision();
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
	for (; CurrNode1 != NULL; preNode = CurrNode1, CurrNode1 = CurrNode1->next) {
		if (preNode == NULL && y.compare(CurrNode1->tconst) == 0) {
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			CurrNode->listSet->head = CurrNode1->next;
			cout << "*************************************************************" << endl;
			cout << "Data has been deleted" << endl;
			counter++;
			break;
		}
		else if (preNode != NULL && y.compare(CurrNode1->tconst) == 0) {
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			preNode->next = CurrNode1->next;
			delete CurrNode1;
			cout << "*************************************************************" << endl;
			cout << "Data has been deleted" << endl;
			counter++;
			break;
		}
		/*if (!y.compare(CurrNode1->tconst)) {
			cout << "*************************************************************" << endl;
			cout << "Data cannot find" << endl;
		else
		{
			if (preNode == NULL && y.compare(CurrNode1->tconst) == 0) {
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
		}
		*/
	}
	if (counter == 0) {
		cout << "Data not found" << endl;
	}
	for (CurrNode1 = CurrNode->listSet->head; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
	}
}


void DataSetlist::DeletionByName(int x) {
	string y;
	cout << "Enter the Name of the data" << endl;
	cin.ignore();
	getline(cin,y);
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
	cout << "*********************" << endl;
	int counter = 0;
	Node* CurrNode = DataSethead->listSet->head, *prevNode = NULL;
	for (; CurrNode; CurrNode = CurrNode->next)
		if (CurrNode->startYear == x)
			counter++;
	for (int i = 0; i < counter; i++) {
		for (CurrNode = DataSethead->listSet->head; CurrNode&&CurrNode->startYear != x; CurrNode = CurrNode->next)
			prevNode = CurrNode;
		if (CurrNode) {
			if (prevNode == NULL)
				DataSethead->listSet->head = CurrNode->next;
			else
				prevNode->next = CurrNode->next;
			delete CurrNode;
		}
	}

	for (CurrNode = DataSethead->listSet->head; CurrNode; CurrNode = CurrNode->next)
		cout << CurrNode->tconst << "\t" << CurrNode->titleType << "\t" << CurrNode->primaryTitle << "\t" << CurrNode->startYear << "\t" << CurrNode->runtimeMinutes << "\t" << CurrNode->genres[0] << "\t" << CurrNode->genres[1] << "\t" << CurrNode->genres[2] << endl;

	if (counter == 0) {
		cout << "No data match" << endl;
	}
	else {
		cout << "Number of data deleted: " << counter << endl;
	}


}
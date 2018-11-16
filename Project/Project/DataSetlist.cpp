#include "DataSetlist.h"



DataSetlist::DataSetlist()
{
	DataSethead = new DataSet();
};
	


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

	int i = 0;


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
					i++;
				}
				else {
					Node * mainlist = new Node(tconst, titleType, primaryTitle, startYear, runtimeMinutes, genres[0], genres[1], genres[2]);
					innerhead->next = mainlist;
					innerhead = innerhead->next;
					i++;
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
					i++;
				}
				else {
					Node * mainlist = new Node(tconst, titleType, primaryTitle, startYear, runtimeMinutes, genres[0], genres[1], genres[2]);
					innernewset->next = mainlist;
					innernewset = innernewset->next;
					i++;
				}
			} while (!dataSet.eof());
			outerhead->next = newset;
		}
	}
	cout << i << endl;
}



void DataSetlist::MainDecision(){
	DataSet * InnerDataSetHead = DataSethead;
	DataSet * IninnerDataSetHead = DataSethead;
	int choice;
	cout << "*************************************************************" << endl;
	cout << "Welcome to the program, it use for searching and update data." << endl;
	cout << "*************************************************************" << endl;
	cout << "Choose What function you want to do " << endl;
	cout << "0. End		1. Insertion	2. Searching	3. Deletion	4.combination	5.Modify" << endl;
	cin >> choice;
	switch (choice)
	{
	case 0: system("cls"); cout << "Thanks for using our program!!" << endl; system("pause"); exit(0);
	case 1:	{fileinput();
		for (; InnerDataSetHead->next != NULL; InnerDataSetHead = InnerDataSetHead->next);
		system("pause");
		FilList * innerfillist = InnerDataSetHead->filListSet;
		for (int i = 0; i < 10; i++) {
			if (innerfillist->filhead == NULL) {
				innerfillist->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
			}
			else {
				innerfillist->next = new FilList();
				innerfillist->next->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
				innerfillist = innerfillist->next;
			}
		}

		//InnerDataSetHead->filListSet->make_Type_List(InnerDataSetHead->listSet->head, "short");
		InnerDataSetHead->filListSet->fildisplay(); system("pause"); system("cls"); MainDecision();
	}
	case 2:	MangeInDataSetSearch(); system("pause"); system("cls"); MainDecision();
	case 3: MangeInDataSetDelete(); system("pause"); system("cls"); MainDecision();
	case 4: MangeInDataSetCombine(true,0);system("pause"); system("cls"); MainDecision();
	
	case 5: MangeInDataSetModify(); system("pause"); system("cls"); MainDecision();
	case 6:for (int i = 0; i < 20; i++) {
		cout << i + 1 << "." << DataSethead->typelist[i] << endl;
	} system("pause"); system("cls"); MainDecision();
	case 7: for (; IninnerDataSetHead != NULL; IninnerDataSetHead = IninnerDataSetHead->next) {
		for (int i = 1; i <= 11; i++) {
			IninnerDataSetHead->filListSet->fildisplay(i);
		}
	}system("pause"); system("cls"); MainDecision();
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
		MainDecision();
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
	case 4: searchingByPgType(x); MainDecision();
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

		}
	}
	if (counter == 0) {
		cout << "No data found" << endl;
	}
	else {
		cout << "Number of data: " << counter << endl;
	}

}

void DataSetlist::searchingByYear(int x) {// add number of data which is equal to the year that user want to search
	string y;
	cout << "Enter the Year of the data" << endl;
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

	int i = 0;
	for (; i < 20; i++) {
		if (CurrNode->typelist[i] == y) {
			CurrNode->filListSet->next->fildisplay(i); system("pause"); system("cls"); MainDecision();
		}
		if (CurrNode->typelist[i] == "") {
			CurrNode->typelist[i] = y;
			break;
		}
	}
	FilList * innerfillist = CurrNode->filListSet;
	FilList * newfillist = new FilList();
	for (; innerfillist->next != NULL; innerfillist = innerfillist->next) {}
	cout << "Number of data match: ";
	newfillist->make_Type_List(CurrNode->listSet->head, y);
	innerfillist->next = newfillist;
	innerfillist->next->fildisplay(i); system("pause"); system("cls"); MainDecision();
}

void DataSetlist::searchingByPgType(int y) {
	int x;
	cout << "Which programme type?" << endl;
	cout << "1. movie		2. short	3. tvEpisode	4. tvMiniSeries		5. tvMovie	" << endl;
	cout << "6. tvSeries	7. tvShort	8. tvSpecial	9. video			10. videoGame	" << endl;
	cout << "0. End" << endl;
	cin >> x;
	int	counter = 0;
	DataSet* CurrNode = DataSethead;
	for (; CurrNode != NULL; CurrNode = CurrNode->next) {
		counter++;
		if (counter == y) {
			break;
		}
	}
		switch (x)
		{
		case 0: return;
		case 1: CurrNode->filListSet->fildisplay(1); system("pause"); system("cls"); MainDecision();  //shortlist
		case 2: CurrNode->filListSet->fildisplay(2); system("pause"); system("cls"); MainDecision(); //movielist
		case 3: CurrNode->filListSet->fildisplay(3); system("pause"); system("cls"); MainDecision(); //tvserieslist
		case 4: CurrNode->filListSet->fildisplay(4); system("pause"); system("cls"); MainDecision(); //tvepisode
		case 5:	CurrNode->filListSet->fildisplay(5); system("pause"); system("cls"); MainDecision(); //videolist
		case 6:	CurrNode->filListSet->fildisplay(6); system("pause"); system("cls"); MainDecision();
		case 7:	CurrNode->filListSet->fildisplay(7); system("pause"); system("cls"); MainDecision();
		case 8:	CurrNode->filListSet->fildisplay(8); system("pause"); system("cls"); MainDecision();
		case 9:	CurrNode->filListSet->fildisplay(9); system("pause"); system("cls"); MainDecision();
		case 10:	CurrNode->filListSet->fildisplay(10); system("pause"); system("cls"); MainDecision();
		default: searchingByPgType(y);
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
	default: cout << "wrong input" << endl; NumberOfType(x);
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

	int i = 0;
	for (; i < 20; i++) {
		if (CurrNode->typelist[i] == y) {
			CurrNode->filListSet->next->fildisplay(i); system("pause"); system("cls"); MainDecision();
		}
		if (CurrNode->typelist[i] == "") {
			CurrNode->typelist[i] = y;
			break;
		}
	}
	FilList * innerfillist = CurrNode->filListSet;
	FilList * newfillist = new FilList();
	for (; innerfillist->next != NULL; innerfillist = innerfillist->next) {}
	cout << "Number of data match: ";
	newfillist->make_Type_List(CurrNode->listSet->head, y);
	innerfillist->next = newfillist;
	innerfillist->next->fildisplay(i); system("pause"); system("cls"); MainDecision();
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

	int i = 0;
	for (; i < 20; i++) {
		if ((CurrNode->typelist[i] == j+","+k)|| (CurrNode->typelist[i] == k + "," + j)) {
			CurrNode->filListSet->next->fildisplay(i); 
			system("pause"); system("cls"); MainDecision();
		}
		if (CurrNode->typelist[i] == "") {
			CurrNode->typelist[i] = j+","+k;
			break;
		}
	}
	FilList * innerfillist = CurrNode->filListSet;
	FilList * newfillist = new FilList();
	for (; innerfillist->next != NULL; innerfillist = innerfillist->next) {}
	newfillist->make_gen_List2(CurrNode->listSet->head, j , k);
	innerfillist->next = newfillist;
	innerfillist->next->fildisplay(i); system("pause"); system("cls"); MainDecision();
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

	int i = 0;
	for (; i < 20; i++) {
		if ((CurrNode->typelist[i] == j+","+k+","+l)|| (CurrNode->typelist[i] == j + "," + l + "," + k)|| (CurrNode->typelist[i] == k + "," + j + "," + l)|| (CurrNode->typelist[i] == k + "," + l + "," + j)|| (CurrNode->typelist[i] == l + "," + k + "," + j)|| (CurrNode->typelist[i] == l + "," + j + "," + k)) {
			CurrNode->filListSet->next->fildisplay(i); 
			system("pause"); system("cls"); MainDecision();
		}
		if (CurrNode->typelist[i] == "") {
			CurrNode->typelist[i] = j + "," + k+","+l;
			break;
		}
	}
	FilList * innerfillist = CurrNode->filListSet;
	FilList * newfillist = new FilList();
	for (; innerfillist->next != NULL; innerfillist = innerfillist->next) {}
	newfillist->make_gen_List3(CurrNode->listSet->head, j, k ,l);
	innerfillist->next = newfillist;
	innerfillist->next->fildisplay(i); system("pause"); system("cls"); MainDecision();
}



void DataSetlist::MangeInDataSetModify(){
	int counter = 0;
	int x;
	bool check = false;
	DataSet* CurrNode = DataSethead;
	cout << "which DataSet you want to modify" << endl;
	for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
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
		MainDecision();;
	}
	else {
		MakeModifyingChoice(x);
	}
}


void DataSetlist::MakeModifyingChoice(int x){
	int y;
	cout << "1. By ID	2. By Name	3. By Year	4. By Programe Type	 5.By Movie Type	0. Stop Searching" << endl;
	cin >> y;
	switch (y)
	{
	case 0: return;
	case 1: ModifyingByID(x); MainDecision();
	case 2: ModifyingByName(x); MainDecision();
	case 3: ModifyingByYear(x); MainDecision();
	case 4: ModifyingByPgType(x); MainDecision();
	case 5: modifyingByType(x); MainDecision();
	default: cout << "wrong input." << endl; MakeSearchingChoice(x); MainDecision();
	}
}

void DataSetlist::ModifyingByID(int x) {
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
			cout << "Enter the programme title" << endl;
			cout << "movie		short	  tvEpisode	  tvMiniSeries	 tvMovie	" << endl;
			cout << "tvSeries	tvShort	  tvSpecial	  video		     videoGame " << endl;
			cin >> CurrNode1->titleType;
			cout << "Enter the name of the data" << endl; cin >> CurrNode1->primaryTitle;
			cout << "Enter the year" << endl; cin >> CurrNode1->startYear;
			cout << "Enter the duration(H)" << endl; cin >> CurrNode1->runtimeMinutes;
			for (int i = 0; i < 3; i++) {
					cout << "Enter the " << i + 1 << "type of data(If nothing, just input /.) : " << endl; cin >> CurrNode1->genres[i];
			}
			counter++;
			break;
		}
	}
	if (counter == 0) {
		cout << "No data found" << endl;
	}
	else {
		cout << "Number of Data change: " << counter << endl;
	}
	delete CurrNode->filListSet;
	CurrNode->filListSet = new FilList();
	DataSet * InnerDataSetHead = CurrNode;
	FilList * innerfillist = InnerDataSetHead->filListSet;
	for (int i = 0; i < 10; i++) {
		if (innerfillist->filhead == NULL) {
			innerfillist->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
		}
		else {
			innerfillist->next = new FilList();
			innerfillist->next->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
			innerfillist = innerfillist->next;
		}
	}
}

void DataSetlist::ModifyingByName(int x){
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
			cout << "Enter the programme title" << endl;
			cout << "movie		short	  tvEpisode	  tvMiniSeries	 tvMovie	" << endl;
			cout << "tvSeries	tvShort	  tvSpecial	  video		     videoGame " << endl;
			cin >> CurrNode1->titleType;
			cout << "Enter the name of the data" << endl;cin >> CurrNode1->primaryTitle;
			cout << "Enter the year" << endl; cin >> CurrNode1->startYear;
			cout << "Enter the duration(H)" << endl; cin >> CurrNode1->runtimeMinutes;
			for (int i = 0; i < 3; i++) {
				if (CurrNode1->genres[i] != " ") {
					cout << "Enter the " << i + 1 << "type of data" << endl; cin >> CurrNode1->genres[i];
				}
			}
			counter++;
			break;
		}
	}
	if (counter == 0) {
		cout << "No data found" << endl;
	}
	else {
		cout << "Number of Data change: " << counter << endl;
	}
	delete CurrNode->filListSet;
	CurrNode->filListSet = new FilList();
	DataSet * InnerDataSetHead = CurrNode;
	FilList * innerfillist = InnerDataSetHead->filListSet;
	for (int i = 0; i < 10; i++) {
		if (innerfillist->filhead == NULL) {
			innerfillist->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
		}
		else {
			innerfillist->next = new FilList();
			innerfillist->next->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
			innerfillist = innerfillist->next;
		}
	}
}

void DataSetlist::ModifyingByYear(int x){
	string y,z;
	cout << "Enter the Year of the data" << endl;
	cin.ignore();
	getline(cin, y);
	cout << "*************************************************************" << endl;
	cout << "Changing to what year? (YYYY)" << endl;
	getline(cin, z);
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
			CurrNode1->startYear = z;
			//cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			counter++;
		}
	}

	for (CurrNode1 = CurrNode->listSet->head; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		if (z.compare(CurrNode1->startYear) == 0) {
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
		}
	}
	
	if (counter == 0) {
		cout << "No data match" << endl;
	}
	else {
		cout << "*************************************************************" << endl;
		cout << "Number of Data change: " << counter << endl;
	}
	delete CurrNode->filListSet;
	CurrNode->filListSet = new FilList();
	DataSet * InnerDataSetHead = CurrNode;
	FilList * innerfillist = InnerDataSetHead->filListSet;
	for (int i = 0; i < 10; i++) {
		if (innerfillist->filhead == NULL) {
			innerfillist->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
		}
		else {
			innerfillist->next = new FilList();
			innerfillist->next->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
			innerfillist = innerfillist->next;
		}
	}
}

void DataSetlist::ModifyingByPgType(int x){
	string y, z;
	cout << "Enter the programme of the data" << endl;
	cin.ignore();
	getline(cin, y);
	cout << "*************************************************************" << endl;
	cout << "Changing to whtat programme type?" << endl;
	cout << "movie		short	  tvEpisode	  tvMiniSeries	 tvMovie	" << endl;
	cout << "tvSeries	tvShort	  tvSpecial	  video		     videoGame " << endl;
	cout << "*************************************************************" << endl;
	getline(cin, z);
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
		if (y.compare(CurrNode1->titleType) == 0) {
			counter++;
			CurrNode1->titleType = z;
			//cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
		}
	}
	for (CurrNode1 = CurrNode->listSet->head; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		if (z.compare(CurrNode1->titleType) == 0) {
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
		}
	}

	if (counter == 0) {
		cout << "No data match" << endl;
	}
	else {
		cout << "*************************************************************" << endl;
		cout << "Number of Data change: " << counter << endl;
	}
	delete CurrNode->filListSet;
	CurrNode->filListSet = new FilList();
	DataSet * InnerDataSetHead = CurrNode;
	FilList * innerfillist = InnerDataSetHead->filListSet;
	for (int i = 0; i < 10; i++) {
		if (innerfillist->filhead == NULL) {
			innerfillist->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
		}
		else {
			innerfillist->next = new FilList();
			innerfillist->next->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
			innerfillist = innerfillist->next;
		}
	}

}

void DataSetlist::modifyingByType(int x){
	string y,a;
	cout << "Enter the type of the data: " << endl;
	cin.ignore();
	getline(cin, y);
	cout << "*************************************************************" << endl;
	cout << "Enter the type of the data u want to replace : " << endl;
	getline(cin, a);
	cout << "*************************************************************" << endl;
	int	counter = 0;
	DataSet* CurrNode = DataSethead;
	for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
		counter++;
		if (counter == x) {
			break;
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
				break;
			}
		}
	}
	for (CurrNode1 = CurrNode->listSet->head; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		for (int i = 0; i < 3; i++) {
			if (a.compare(CurrNode1->genres[i]) == 0) {
				cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
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
	delete CurrNode->filListSet;
	CurrNode->filListSet = new FilList();
	DataSet * InnerDataSetHead = CurrNode;
	FilList * innerfillist = InnerDataSetHead->filListSet;
	for (int i = 0; i < 10; i++) {
		if (innerfillist->filhead == NULL) {
			innerfillist->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
		}
		else {
			innerfillist->next = new FilList();
			innerfillist->next->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
			innerfillist = innerfillist->next;
		}
	}
}*/


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
		MainDecision();
	}
	else {
		MakeDeletionChoice(x);
	}
}

void DataSetlist::MakeDeletionChoice(int x) {
	int y;
	cout << "1. By ID   2. By Name   3. By Year   4. By Programe Type   5.By Movie Type   0. Stop Searching" << endl;
	cin >> y;
	switch (y)
	{
	case 0: return;
	case 1: DeletionByID(x); MainDecision();
	case 2: DeletionByName(x); MainDecision();
	case 3: DeletionByYear(x); MainDecision();
	case 4: DeletionByPgType(x); MainDecision();
	case 5: NumberOfTypeDel(x); MainDecision();
	default: MakeDeletionChoice(x);
	}
}

void DataSetlist::DeletionByID(int x) {
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
	}
	if (counter == 0) {
		cout << "Data not found" << endl;
	}
	for (CurrNode1 = CurrNode->listSet->head; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
	}
	delete CurrNode->filListSet;
	CurrNode->filListSet = new FilList();
	DataSet * InnerDataSetHead = CurrNode;
	FilList * innerfillist = InnerDataSetHead->filListSet;
	for (int i = 0; i < 10; i++) {
		if (innerfillist->filhead == NULL) {
			innerfillist->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
		}
		else {
			innerfillist->next = new FilList();
			innerfillist->next->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
			innerfillist = innerfillist->next;
		}
	}
}

void DataSetlist::DeletionByName(int x) {
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
	Node *preNode = NULL;
	for (; CurrNode1 != NULL; preNode = CurrNode1, CurrNode1 = CurrNode1->next) {
		if (preNode == NULL && y.compare(CurrNode1->primaryTitle) == 0) {
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			CurrNode->listSet->head = CurrNode1->next;
			cout << "*************************************************************" << endl;
			cout << "Data has been deleted" << endl;
			counter++;
			break;
		}
		else if (preNode != NULL && y.compare(CurrNode1->primaryTitle) == 0) {
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			preNode->next = CurrNode1->next;
			delete CurrNode1;
			cout << "*************************************************************" << endl;
			cout << "Data has been deleted" << endl;
			counter++;
			break;
		}
	}
	if (counter == 0) {
		cout << "Data not found" << endl;
	}
	for (CurrNode1 = CurrNode->listSet->head; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
	}
	delete CurrNode->filListSet;
	CurrNode->filListSet = new FilList();
	DataSet * InnerDataSetHead = CurrNode;
	FilList * innerfillist = InnerDataSetHead->filListSet;
	for (int i = 0; i < 10; i++) {
		if (innerfillist->filhead == NULL) {
			innerfillist->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
		}
		else {
			innerfillist->next = new FilList();
			innerfillist->next->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
			innerfillist = innerfillist->next;
		}
	}
}

void DataSetlist::DeletionByYear(int x) {
	string y;
	cout << "Enter the Year of the data" << endl;
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
	Node * newlist = NULL;


	Node* CurrNode1 = CurrNode->listSet->head;
	CurrNode->listSet->head = NULL;
	Node *innerhead = CurrNode->listSet->head;
	for (; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		if (y.compare(CurrNode1->startYear)) {
			if (innerhead == NULL) {
				Node* newlist1 = new Node(CurrNode1->tconst, CurrNode1->titleType, CurrNode1->primaryTitle, CurrNode1->startYear, CurrNode1->runtimeMinutes, CurrNode1->genres[0], CurrNode1->genres[1], CurrNode1->genres[2]);
				innerhead = newlist1;
				CurrNode->listSet->head = innerhead;
			}
			else {
				Node* newlist1 = new Node(CurrNode1->tconst, CurrNode1->titleType, CurrNode1->primaryTitle, CurrNode1->startYear, CurrNode1->runtimeMinutes, CurrNode1->genres[0], CurrNode1->genres[1], CurrNode1->genres[2]);
				innerhead->next = newlist1;
				innerhead = innerhead->next;
			}
		}
		else {
			counter++;
		}
	}
	CurrNode1 = CurrNode->listSet->head;
	if (counter == 0) {
		cout << "No data match" << endl;
	}
	else {
		for (; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
		}
		cout << "Number of Datad deleted: " << counter << endl;
	}
	delete CurrNode->filListSet;
	CurrNode->filListSet = new FilList();
	DataSet * InnerDataSetHead = CurrNode;
	FilList * innerfillist = InnerDataSetHead->filListSet;
	for (int i = 0; i < 10; i++) {
		if (innerfillist->filhead == NULL) {
			innerfillist->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
		}
		else {
			innerfillist->next = new FilList();
			innerfillist->next->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
			innerfillist = innerfillist->next;
		}
	}
}

void DataSetlist::DeletionByPgType(int x) {
	string y;
	cout << "Enter the programe type of the data" << endl;
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
	Node * newlist = NULL;


	Node* CurrNode1 = CurrNode->listSet->head;
	CurrNode->listSet->head = NULL;
	Node *innerhead = CurrNode->listSet->head;
	for (; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		if (y.compare(CurrNode1->titleType)) {
			if (innerhead == NULL) {
				Node* newlist1 = new Node(CurrNode1->tconst, CurrNode1->titleType, CurrNode1->primaryTitle, CurrNode1->startYear, CurrNode1->runtimeMinutes, CurrNode1->genres[0], CurrNode1->genres[1], CurrNode1->genres[2]);
				innerhead = newlist1;
				CurrNode->listSet->head = innerhead;
			}
			else {
				Node* newlist1 = new Node(CurrNode1->tconst, CurrNode1->titleType, CurrNode1->primaryTitle, CurrNode1->startYear, CurrNode1->runtimeMinutes, CurrNode1->genres[0], CurrNode1->genres[1], CurrNode1->genres[2]);
				innerhead->next = newlist1;
				innerhead = innerhead->next;
			}
		}
		else {
			counter++;
		}
	}
	CurrNode1 = CurrNode->listSet->head;
	if (counter == 0) {
		cout << "No data match" << endl;
	}
	else {
		for (; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
		}
		cout << "Number of Datad deleted: " << counter << endl;
	}
	delete CurrNode->filListSet;
	CurrNode->filListSet = new FilList();
	DataSet * InnerDataSetHead = CurrNode;
	FilList * innerfillist = InnerDataSetHead->filListSet;
	for (int i = 0; i < 10; i++) {
		if (innerfillist->filhead == NULL) {
			innerfillist->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
		}
		else {
			innerfillist->next = new FilList();
			innerfillist->next->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
			innerfillist = innerfillist->next;
		}
	}
}

void DataSetlist::NumberOfTypeDel(int x) {
	int y;
	cout << "How many type U want to input? Maximun: 3. " << endl;
	cin >> y;
	switch (y) {
	case 1: DeleteByType1(x); MainDecision();
	case 2: DeleteByType2(x); MainDecision();
	case 3: DeleteByType3(x); MainDecision();
	default: NumberOfType(x);
	}

}

void DataSetlist::DeleteByType1(int x) {
	bool check = false;
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
	Node * newlist = NULL;


	Node* CurrNode1 = CurrNode->listSet->head;
	CurrNode->listSet->head = NULL;
	Node *innerhead = CurrNode->listSet->head;

	for (; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		check = false;
		for (int i = 0; i < 3; i++) {
			if (y.compare(CurrNode1->genres[i])) {
				check = true;
			}
			else {
				check = false;
				break;
			}
		}
			if (check == true) {
				if (innerhead == NULL) {
					Node* newlist1 = new Node(CurrNode1->tconst, CurrNode1->titleType, CurrNode1->primaryTitle, CurrNode1->startYear, CurrNode1->runtimeMinutes, CurrNode1->genres[0], CurrNode1->genres[1], CurrNode1->genres[2]);
					innerhead = newlist1;
					CurrNode->listSet->head = innerhead;
				}
				else {
					Node* newlist1 = new Node(CurrNode1->tconst, CurrNode1->titleType, CurrNode1->primaryTitle, CurrNode1->startYear, CurrNode1->runtimeMinutes, CurrNode1->genres[0], CurrNode1->genres[1], CurrNode1->genres[2]);
					innerhead->next = newlist1;
					innerhead = innerhead->next;

				}
			}
			else {
				counter++;
			}
	}
	CurrNode1 = CurrNode->listSet->head;
	if (counter == 0) {
		cout << "No data match" << endl;
	}
	else {
		for (; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
		}
		cout << "Number of Datad deleted: " << counter << endl;
	}
	delete CurrNode->filListSet;
	CurrNode->filListSet = new FilList();
	DataSet * InnerDataSetHead = CurrNode;
	FilList * innerfillist = InnerDataSetHead->filListSet;
	for (int i = 0; i < 10; i++) {
		if (innerfillist->filhead == NULL) {
			innerfillist->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
		}
		else {
			innerfillist->next = new FilList();
			innerfillist->next->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
			innerfillist = innerfillist->next;
		}
	}
}

void DataSetlist::DeleteByType2(int x) {
	bool check = false;
	string j, k;
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
	Node * newlist = NULL;


	Node* CurrNode1 = CurrNode->listSet->head;
	CurrNode->listSet->head = NULL;
	Node *innerhead = CurrNode->listSet->head;

	for (; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		check = false;
		for (int i = 0; i < 3; i++) {
			if (j.compare(CurrNode1->genres[i]) && k.compare(CurrNode1->genres[i])) {
				check = true;
			}
			else {
				check = false;
				break;
			}
		}
		if (check == true) {
			if (innerhead == NULL) {
				Node* newlist1 = new Node(CurrNode1->tconst, CurrNode1->titleType, CurrNode1->primaryTitle, CurrNode1->startYear, CurrNode1->runtimeMinutes, CurrNode1->genres[0], CurrNode1->genres[1], CurrNode1->genres[2]);
				innerhead = newlist1;
				CurrNode->listSet->head = innerhead;
			}
			else {
				Node* newlist1 = new Node(CurrNode1->tconst, CurrNode1->titleType, CurrNode1->primaryTitle, CurrNode1->startYear, CurrNode1->runtimeMinutes, CurrNode1->genres[0], CurrNode1->genres[1], CurrNode1->genres[2]);
				innerhead->next = newlist1;
				innerhead = innerhead->next;

			}
		}
		else {
			counter++;
		}
	}
	CurrNode1 = CurrNode->listSet->head;
	if (counter == 0) {
		cout << "No data match" << endl;
	}
	else {
		for (; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
		}
		cout << "Number of Datad deleted: " << counter << endl;
	}
	delete CurrNode->filListSet;
	CurrNode->filListSet = new FilList();
	DataSet * InnerDataSetHead = CurrNode;
	FilList * innerfillist = InnerDataSetHead->filListSet;
	for (int i = 0; i < 10; i++) {
		if (innerfillist->filhead == NULL) {
			innerfillist->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
		}
		else {
			innerfillist->next = new FilList();
			innerfillist->next->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
			innerfillist = innerfillist->next;
		}
	}
}
void DataSetlist::DeleteByType3(int x) {
	bool check = false;
	string j, k, l;
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
	Node * newlist = NULL;


	Node* CurrNode1 = CurrNode->listSet->head;
	CurrNode->listSet->head = NULL;
	Node *innerhead = CurrNode->listSet->head;

	for (; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		check = false;
		for (int i = 0; i < 3; i++) {
			if (j.compare(CurrNode1->genres[i]) && k.compare(CurrNode1->genres[i]) && l.compare(CurrNode1->genres[i])) {
				check = true;
			}
			else {
				check = false;
				break;
			}
		}
		if (check == true) {
			if (innerhead == NULL) {
				Node* newlist1 = new Node(CurrNode1->tconst, CurrNode1->titleType, CurrNode1->primaryTitle, CurrNode1->startYear, CurrNode1->runtimeMinutes, CurrNode1->genres[0], CurrNode1->genres[1], CurrNode1->genres[2]);
				innerhead = newlist1;
				CurrNode->listSet->head = innerhead;
			}
			else {
				Node* newlist1 = new Node(CurrNode1->tconst, CurrNode1->titleType, CurrNode1->primaryTitle, CurrNode1->startYear, CurrNode1->runtimeMinutes, CurrNode1->genres[0], CurrNode1->genres[1], CurrNode1->genres[2]);
				innerhead->next = newlist1;
				innerhead = innerhead->next;

			}
		}
		else {
			counter++;
		}
	}
	CurrNode1 = CurrNode->listSet->head;
	if (counter == 0) {
		cout << "No data match" << endl;
	}
	else {
		for (; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
		}
		cout << "Number of Datad deleted: " << counter << endl;
	}
	delete CurrNode->filListSet;
	CurrNode->filListSet = new FilList();
	DataSet * InnerDataSetHead = CurrNode;
	FilList * innerfillist = InnerDataSetHead->filListSet;
	for (int i = 0; i < 10; i++) {
		if (innerfillist->filhead == NULL) {
			innerfillist->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
		}
		else {
			innerfillist->next = new FilList();
			innerfillist->next->make_Type_List(InnerDataSetHead->listSet->head, InnerDataSetHead->typelist[i]);
			innerfillist = innerfillist->next;
		}
	}
}

void DataSetlist::MangeInDataSetCombine(bool firsttime , int targetpos){
	int counter = 0;
	int x;
	bool check = false;
	DataSet* CurrNode = DataSethead;
	if (firsttime == true) {
		cout << "Which DataSet you want to combine?" << endl;
		cout << "Reminder:This DataSet will be the path of the list)" << endl;
		for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
			counter++;
			cout << "DataSet " << counter << endl;
		}
		cout << "*************************************************************" << endl;
		cin >> x;
		targetpos = x;
		cout << "*************************************************************" << endl;
		counter = 0;
		for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
			counter++;
			if (counter == x) {
				check = true;
				break;
			}
		}
	}
	else {
		cout << "Which DataSet you want to combine?" << endl;
		cout << "Reminder:This will not be the path of the list)" << endl;
		for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
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
	}

	if (check == false) {
		cout << "Here is no such a DataSet" << endl;
		cout << "Now return to lobby" << endl;
		system("pause");
		system("cls");
		MainDecision();
	}
	else {
		MakeCombineChoice(x, firsttime, targetpos);
	}
};

void DataSetlist::MakeCombineChoice(int x, bool firsttime, int targetpos) {
	int y;
	cout << "1. By ID	2. By Name	3. By Year	4. By Programe Type	 5.By Movie Type	0. Stop Searching" << endl;
	cin >> y;
	switch (y)
	{
	case 0: return;
	case 1: combineByID(x , firsttime, targetpos);
	case 2: combineByName(x , firsttime, targetpos);
	case 3: combineByYear(x , firsttime, targetpos);
	case 4: combineByPgType(x , firsttime, targetpos);
	case 5: combineNumberOfType(x , firsttime, targetpos);
	default: cout << "wrong input." << endl; system("pause"); system("cls"); MainDecision();
	}
}

void DataSetlist::combineNumberOfType(int x, bool firsttime, int targetpos) {
	int y;
	cout << "How many type U want to input? Maximun: 3. " << endl;
	cin >> y;
	switch (y) {
	case 1: combineByType1(x, firsttime, targetpos);
	case 2: combineByType2(x, firsttime, targetpos);
	case 3: combineByType3(x, firsttime, targetpos);
	default: combineNumberOfType(x, firsttime, targetpos);
	}
}

void DataSetlist::combineByID(int x, bool firsttime, int targetpos) {
	string y;
	cout << "Enter the ID of the data" << endl;
	cin.ignore();
	getline(cin, y);
	cout << "*************************************************************" << endl;
	int counter = 0;
	int i = 0;
	DataSet* CurrNode = DataSethead;
	DataSet* CurrNode1 = DataSethead;
	if (firsttime == true) {
		for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
			counter++;
			if (counter == x) {
				break;
			}
		}
		for (; i < 20; i++) {
			if (CurrNode->typelist[i] == "") {
				CurrNode->typelist[i] = y;
				break;
			}
		}
		FilList * innerfillist = CurrNode->filListSet;
		FilList * newfillist = new FilList();
		for (; innerfillist->next != NULL; innerfillist = innerfillist->next) {}
		newfillist->make_Type_List(CurrNode->listSet->head, y);
		innerfillist->next = newfillist;
		innerfillist->next->fildisplay(i); system("pause"); system("cls"); MangeInDataSetCombine(false, targetpos);
	}
	else {
		for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
			counter++;
			if (counter == targetpos) {
				break;
			}
		}
		counter = 0;
		for (CurrNode1 = DataSethead; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
			counter++;
			if (counter == x) {
				break;
			}
		}
		for (; i < 20; i++) {
			if (CurrNode->typelist[i+1] == "") {
				CurrNode->typelist[i] = CurrNode->typelist[i]+","+y;
				break;
			}
		}
		FilList * innerfillist = CurrNode->filListSet;
		FilList * newfillist = new FilList();
		for (; innerfillist->next != NULL; innerfillist = innerfillist->next) {}
		filterNode * innerfillisthead = innerfillist->filhead;
		for (; innerfillisthead->filnext != NULL; innerfillisthead = innerfillisthead->filnext) {}
		newfillist->make_Type_List(CurrNode1->listSet->head, y);
		innerfillisthead->filnext = newfillist->filhead;
		innerfillist->fildisplay(i); system("pause"); system("cls"); MainDecision();
	}
}

void DataSetlist::combineByName(int x, bool firsttime, int targetpos) {
	string y;
	cout << "Enter the Name of the data" << endl;
	cin.ignore();
	getline(cin, y);
	cout << "*************************************************************" << endl;
	int counter = 0;
	int i = 0;
	DataSet* CurrNode = DataSethead;
	if (firsttime == true) {
		for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
			counter++;
			if (counter == x) {
				break;
			}
		}
		for (; i < 20; i++) {
			if (CurrNode->typelist[i] == "") {
				CurrNode->typelist[i] = y;
				break;
			}
		}
		FilList * innerfillist = CurrNode->filListSet;
		FilList * newfillist = new FilList();
		for (; innerfillist->next != NULL; innerfillist = innerfillist->next) {}
		newfillist->make_Type_List(CurrNode->listSet->head, y);
		innerfillist->next = newfillist;
		innerfillist->next->fildisplay(i); system("pause"); system("cls"); MangeInDataSetCombine(false, targetpos);
	}
	else {
		for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
			counter++;
			if (counter == targetpos) {
				break;
			}
		}
		for (; i < 20; i++) {
			if (CurrNode->typelist[i + 1] == "") {
				CurrNode->typelist[i] = CurrNode->typelist[i] + "," + y;
				break;
			}
		}
		FilList * innerfillist = CurrNode->filListSet;
		FilList * newfillist = new FilList();
		for (; innerfillist->next != NULL; innerfillist = innerfillist->next) {}
		filterNode * innerfillisthead = innerfillist->filhead;
		for (; innerfillisthead->filnext != NULL; innerfillisthead = innerfillisthead->filnext) {}
		newfillist->make_Type_List(CurrNode->listSet->head, y);
		innerfillisthead->filnext = newfillist->filhead;
		innerfillist->fildisplay(i); system("pause"); system("cls"); MainDecision();
	}
}

void DataSetlist::combineByYear(int x, bool firsttime, int targetpos){
	string y;
	cout << "Enter the Year of the data" << endl;
	cin.ignore();
	getline(cin, y);
	cout << "*************************************************************" << endl;
	int	counter = 0;
	int i = 0;
	DataSet* CurrNode = DataSethead;
	for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
		counter++;
		if (counter == x) {
			break;
		}
	}
	if (firsttime == true) {
		for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
			counter++;
			if (counter == x) {
				break;
			}
		}
		for (; i < 20; i++) {
			if (CurrNode->typelist[i] == "") {
				CurrNode->typelist[i] = y;
				break;
			}
		}
		FilList * innerfillist = CurrNode->filListSet;
		FilList * newfillist = new FilList();
		for (; innerfillist->next != NULL; innerfillist = innerfillist->next) {}
		newfillist->make_Type_List(CurrNode->listSet->head, y);
		innerfillist->next = newfillist;
		innerfillist->next->fildisplay(i); system("pause"); system("cls"); MangeInDataSetCombine(false, targetpos);
	}
	else {
		for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
			counter++;
			if (counter == targetpos) {
				break;
			}
		}
		for (; i < 20; i++) {
			if (CurrNode->typelist[i + 1] == "") {
				CurrNode->typelist[i] = CurrNode->typelist[i] + "," + y;
				break;
			}
		}
		FilList * innerfillist = CurrNode->filListSet;
		FilList * newfillist = new FilList();
		for (; innerfillist->next != NULL; innerfillist = innerfillist->next) {}
		filterNode * innerfillisthead = innerfillist->filhead;
		for (; innerfillisthead->filnext != NULL; innerfillisthead = innerfillisthead->filnext) {}
		newfillist->make_Type_List(CurrNode->listSet->head, y);
		innerfillisthead->filnext = newfillist->filhead;
		innerfillist->fildisplay(i); system("pause"); system("cls"); MainDecision();
	}
}

void DataSetlist::combineByPgType(int x, bool firsttime, int targetpos) {
	int y;
	cout << "Which programme type?" << endl;
	cout << "1. movie		2. short	3. tvEpisode	4. tvMiniSeries		5. tvMovie	" << endl;
	cout << "6. tvSeries	7. tvShort	8. tvSpecial	9. video			10. videoGame	" << endl;
	cout << "0. End" << endl;
	cin >> y;
	int	counter = 0;
	int i = 0;
	DataSet* CurrNode = DataSethead;
	if (firsttime == true) {
		for (; CurrNode != NULL; CurrNode = CurrNode->next) {
			counter++;
			if (counter == x) {
				break;
			}
		}
		for (; i < 20; i++) {
			if (CurrNode->typelist[i] == "") {
				CurrNode->typelist[i] = CurrNode->typelist[y-1];
				break;
			}
		}
		FilList * innerfillist = CurrNode->filListSet;
		FilList * newfillist = new FilList();
		for (; innerfillist->next != NULL; innerfillist = innerfillist->next) {}
		newfillist->make_Type_List(CurrNode->listSet->head, CurrNode->typelist[y-1]);
		innerfillist->next = newfillist;
		innerfillist->next->fildisplay(i); system("pause"); system("cls"); MangeInDataSetCombine(false, targetpos);
	}
	else {
		for (; CurrNode != NULL; CurrNode = CurrNode->next) {
			counter++;
			if (counter == targetpos){
				break;
			}
		}
		for (; i < 20; i++) {
			if (CurrNode->typelist[i + 1] == "") {
				CurrNode->typelist[i] = CurrNode->typelist[i] + "," + CurrNode->typelist[y-1];
				break;
			}
		}
		FilList * innerfillist = CurrNode->filListSet;
		FilList * newfillist = new FilList();
		for (; innerfillist->next != NULL; innerfillist = innerfillist->next) {}
		filterNode * innerfillisthead = innerfillist->filhead;
		for (; innerfillisthead->filnext != NULL; innerfillisthead = innerfillisthead->filnext) {}
		newfillist->make_Type_List(CurrNode->listSet->head, CurrNode->typelist[y-1]);
		innerfillisthead->filnext = newfillist->filhead;
		innerfillist->fildisplay(i); system("pause"); system("cls"); MainDecision();
	}
}

void DataSetlist::combineByType1(int x, bool firsttime, int targetpos) {
	string y;
	cout << "Enter the type of the data: " << endl;
	cin.ignore();
	getline(cin, y);
	cout << "*************************************************************" << endl;
	int	counter = 0;
	int i = 0;
	DataSet* CurrNode = DataSethead;
	if (firsttime == true) {
		for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
			counter++;
			if (counter == x) {
				break;
			}
		}
		for (; i < 20; i++) {
			if (CurrNode->typelist[i] == "") {
				CurrNode->typelist[i] = y;
				break;
			}
		}
		FilList * innerfillist = CurrNode->filListSet;
		FilList * newfillist = new FilList();
		for (; innerfillist->next != NULL; innerfillist = innerfillist->next) {}
		newfillist->make_Type_List(CurrNode->listSet->head, y);
		innerfillist->next = newfillist;
		innerfillist->next->fildisplay(i); system("pause"); system("cls"); MangeInDataSetCombine(false, targetpos);
	}
	else {
		for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
			counter++;
			if (counter == targetpos) {
				break;
			}
		}
		for (; i < 20; i++) {
			if (CurrNode->typelist[i + 1] == "") {
				CurrNode->typelist[i] = CurrNode->typelist[i] + "," + y;
				break;
			}
		}
		FilList * innerfillist = CurrNode->filListSet;
		FilList * newfillist = new FilList();
		for (; innerfillist->next != NULL; innerfillist = innerfillist->next) {}
		filterNode * innerfillisthead = innerfillist->filhead;
		for (; innerfillisthead->filnext != NULL; innerfillisthead = innerfillisthead->filnext) {}
		newfillist->make_Type_List(CurrNode->listSet->head, y);
		innerfillisthead->filnext = newfillist->filhead;
		innerfillist->fildisplay(i); system("pause"); system("cls"); MainDecision();
	}
}

void DataSetlist::combineByType2(int x, bool firsttime, int targetpos) {
	string j, k;
	cout << "Enter the first type of the data: " << endl;
	cin.ignore();
	getline(cin, j);
	cout << "*************************************************************" << endl;
	cout << "Enter the second type of the data: " << endl;
	getline(cin, k);
	cout << "*************************************************************" << endl;
	int	counter = 0;
	int i = 0;
	DataSet* CurrNode = DataSethead;
	if (firsttime == true) {
		for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
			counter++;
			if (counter == x) {
				break;
			}
		}
		for (; i < 20; i++) {
			if (CurrNode->typelist[i] == "") {
				CurrNode->typelist[i] = j+","+k;
				break;
			}
		}
		FilList * innerfillist = CurrNode->filListSet;
		FilList * newfillist = new FilList();
		for (; innerfillist->next != NULL; innerfillist = innerfillist->next) {}
		newfillist->make_gen_List2(CurrNode->listSet->head, j , k);
		innerfillist->next = newfillist;
		innerfillist->next->fildisplay(i); system("pause"); system("cls"); MangeInDataSetCombine(false, targetpos);
	}
	else {
		for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
			counter++;
			if (counter == targetpos) {
				break;
			}
		}
		for (; i < 20; i++) {
			if (CurrNode->typelist[i + 1] == "") {
				CurrNode->typelist[i] = CurrNode->typelist[i] + "," + j + "," + k;
				break;
			}
		}
		FilList * innerfillist = CurrNode->filListSet;
		FilList * newfillist = new FilList();
		for (; innerfillist->next != NULL; innerfillist = innerfillist->next) {}
		filterNode * innerfillisthead = innerfillist->filhead;
		for (; innerfillisthead->filnext != NULL; innerfillisthead = innerfillisthead->filnext) {}
		newfillist->make_gen_List2(CurrNode->listSet->head, j,k);
		innerfillisthead->filnext = newfillist->filhead;
		innerfillist->fildisplay(i); system("pause"); system("cls"); MainDecision();
	}
}

void DataSetlist::combineByType3(int x, bool firsttime, int targetpos) {
	string j, k, l;
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
	int i = 0;
	DataSet* CurrNode = DataSethead;
	if (firsttime == true) {
		for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
			counter++;
			if (counter == x) {
				break;
			}
		}
		for (; i < 20; i++) {
			if (CurrNode->typelist[i] == "") {
				CurrNode->typelist[i] = j + "," + k + "," + l;
				break;
			}
		}
		FilList * innerfillist = CurrNode->filListSet;
		FilList * newfillist = new FilList();
		for (; innerfillist->next != NULL; innerfillist = innerfillist->next) {}
		newfillist->make_gen_List3(CurrNode->listSet->head, j, k, l);
		innerfillist->next = newfillist;
		innerfillist->next->fildisplay(i); system("pause"); system("cls"); MangeInDataSetCombine(false, targetpos);
	}
	else {
		for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
			counter++;
			if (counter == targetpos) {
				break;
			}
		}
		for (; i < 20; i++) {
			if (CurrNode->typelist[i + 1] == "") {
				CurrNode->typelist[i] = CurrNode->typelist[i] + "," + j + "," + k + "," + l;
				break;
			}
		}
		FilList * innerfillist = CurrNode->filListSet;
		FilList * newfillist = new FilList();
		for (; innerfillist->next != NULL; innerfillist = innerfillist->next) {}
		filterNode * innerfillisthead = innerfillist->filhead;
		for (; innerfillisthead->filnext != NULL; innerfillisthead = innerfillisthead->filnext) {}
		newfillist->make_gen_List3(CurrNode->listSet->head, j, k, l);
		innerfillisthead->filnext = newfillist->filhead;
		innerfillist->fildisplay(i); system("pause"); system("cls"); MainDecision();
	}
}
#include "DataSetlist.h"
#include <windows.h>

typedef enum FG_COLORS //foreground colors
{
	FG_BLACK = 0,
	FG_BLUE = 1,
	FG_GREEN = 2,
	FG_CYAN = 3,
	FG_RED = 4,
	FG_MAGENTA = 5,
	FG_BROWN = 6,
	FG_LIGHTGRAY = 7,
	FG_GRAY = 8,
	FG_LIGHTBLUE = 9,
	FG_LIGHTGREEN = 10,
	FG_LIGHTCYAN = 11,
	FG_LIGHTRED = 12,
	FG_LIGHTMAGENTA = 13,
	FG_YELLOW = 14,
	FG_WHITE = 15
}FG_COLORS;

typedef enum BG_COLORS //backfround colors
{
	BG_NAVYBLUE = 16,
	BG_GREEN = 32,
	BG_TEAL = 48,
	BG_MAROON = 64,
	BG_PURPLE = 80,
	BG_OLIVE = 96,
	BG_SILVER = 112,
	BG_GRAY = 128,
	BG_BLUE = 144,
	BG_LIME = 160,
	BG_CYAN = 176,
	BG_RED = 192,
	BG_MAGENTA = 208,
	BG_YELLOW = 224,
	BG_WHITE = 240
}BG_COLORS;

WORD GetConsoleTextAttribute(HANDLE hCon) //color
{
	CONSOLE_SCREEN_BUFFER_INFO con_info;
	GetConsoleScreenBufferInfo(hCon, &con_info);
	return con_info.wAttributes;
}

DataSetlist::DataSetlist()
{
	DataSethead = new DataSet();
	typelist[0] =  "movie";
	typelist[1] = "short";
	typelist[2] = "tvEpisode";
	typelist[3] = "tvMiniSeries";
	typelist[4] = "tvMovie";
	typelist[5] = "tvSeries";
	typelist[6] = "tvShort";
	typelist[7] = "tvSpecial";
	typelist[8] = "video";
	typelist[9] = "videoGame";
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
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	DataSet * InnerDataSetHead = DataSethead;
	int choice;
	SetConsoleTextAttribute(hConsole, BG_OLIVE | FG_GREEN | BG_LIME);

	cout << "_______ _______ _______         _______    _______ _______ _______________________ ________________  " << endl;
	cout << "(  ____ (  ____ (  ___  |\\     /(  ____ )  (  ____ (  ____ (  ___  \__    _(  ____ (  ____ \\__   __/  " << endl;
	cout << "| (    \\| (    )| (   ) | )   ( | (    )|  | (    )| (    )| (   ) |  )  ( | (    \\| (    \\/  ) (    " << endl;
	cout << "| |     | (____)| |   | | |   | | (____)|  | (____)| (____)| |   | |  |  | | (__   | |        | |    " << endl;
	cout << "| | ____|     __| |   | | |   | |  _____)  |  _____|     __| |   | |  |  | |  __)  | |        | |    " << endl;
	cout << "| | \\_  | (\\ (  | |   | | |   | | (        | (     | (\\ (  | |   | |  |  | | (     | |        | |    " << endl;
	cout << "| (___) | ) \\ \\_| (___) | (___) | )        | )     | ) \\ \\_| (___) |\\_)  ) | (____/| (____/\\  | |    " << endl;
	cout << "(_______|/   \\__(_______(_______|/         |/      |/   \\__(_______(____/  (_______(_______/  )_(    " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	cout << "*************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Welcome to Search and Update data here :) " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	cout << "*************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Choose What function you want to do (Please input number '0 ~ 4') " << endl << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_YELLOW | FOREGROUND_INTENSITY);
	cout << "1:Insertion 2:Searching 3:Deletion " ;	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
	cout << "0:Exit Program" << endl << endl; 	SetConsoleTextAttribute(hConsole, saved_colors);

	
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin >> choice;  cout << endl; SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	if (choice == 1)
		cout << "You chose Insertion" << endl << endl;
	if (choice == 2)
		cout << "You chose Searching" << endl << endl;
	if (choice == 3)
		cout << "You chose Deletion" << endl << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);

	switch (choice)
	{
	case 0: system("cls");	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
		cout << "Thanks for using our program ! Hope you can give us a praise after that." << endl;	SetConsoleTextAttribute(hConsole, saved_colors);
		system("pause"); exit(0);
	case 1:	{fileinput();
		for (; InnerDataSetHead->next != NULL; InnerDataSetHead = InnerDataSetHead->next);
		InnerDataSetHead->listSet->display(); system("pause");
		FilList * IninnerfillistHead = InnerDataSetHead->filListSet;
		for (int i = 0; i < 10; i++) {
			if (InnerDataSetHead->filListSet->filhead == NULL) {
				FilList * newfillist = new FilList();
				newfillist->make_Type_List(InnerDataSetHead->listSet->head, typelist[i]);
				InnerDataSetHead->filListSet->filhead = newfillist->filhead;
			}
			else {
				FilList * newfillist = new FilList();
				newfillist->make_Type_List(InnerDataSetHead->listSet->head, typelist[i]);
				IninnerfillistHead->next = newfillist;
				IninnerfillistHead = IninnerfillistHead->next;
			}
		}

		//InnerDataSetHead->filListSet->make_Type_List(InnerDataSetHead->listSet->head, "short");
		InnerDataSetHead->filListSet->fildisplay(); system("pause"); system("cls"); MainDecision();
	}
	case 2:	MangeInDataSetSearch(); system("pause"); system("cls"); MainDecision();
	case 3: MangeInDataSetDelete(); system("pause"); system("cls"); MainDecision();
	default: SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);  cout << "Please input a proper NUMBER !" << endl;	SetConsoleTextAttribute(hConsole, saved_colors);  system("pause"); system("cls"); MainDecision();
	}
}



void DataSetlist::MangeInDataSetSearch() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	int counter = 0;
	int x;
	bool check = false;
	DataSet* CurrNode = DataSethead;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Which DataSet you want to modify ? " << endl << endl ;
	SetConsoleTextAttribute(hConsole, saved_colors);
	///////////////////////TOBY 11.14 edited////////////////////////////
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
	case 2: searchingByName(x); MainDecision();
	case 3: searchingByYear(x); MainDecision();
	//case 4: searchingByPgType(); MainDecision();
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
		if (CurrNode1->startYear == y) {
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			counter++;
		}
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


/*void DataSetlist::searchingByType() {
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
}*/




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
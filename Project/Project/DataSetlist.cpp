#include "DataSetlist.h"
#include <cstdio>
#include <ctime>
#include <windows.h>
#include <fstream>

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
};
	


void DataSetlist::fileinput() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
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

	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Which dataSet you want to input?" << endl;
	cout << "Filename: ";
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin >> filename;
	SetConsoleTextAttribute(hConsole, saved_colors);
	clock_t start;
	double duration;
	start = clock();
	cout << endl;

	dataSet.open(filename);
	if (!(dataSet.is_open())) {
		SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
		cerr << "Error. The file doesn't open correctly." << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
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
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	cout << i << endl;
}



void DataSetlist::MainDecision(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	DataSet * InnerDataSetHead = DataSethead;
	DataSet * IninnerDataSetHead = DataSethead;
	int choice;
	SetConsoleTextAttribute(hConsole, FG_LIGHTGREEN );
	cout << "                                                       #      #####   #######       #####     ###      #      ###    #######                       " << endl;
	cout << "                                                      # #    #     #     #         #     #   #   #    ##     #   #   #                             " << endl;
	cout << "                                                     #   #   #           #               #  #     #  # #    #     #  #                             " << endl;
	cout << "                                                    #     #   #####      #          #####   #     #    #    #     #  ######                        " << endl;
	cout << "                                                    #######        #     #         #        #     #    #    #     #        #                       " << endl;
	cout << "                                                    #     #  #     #     #         #         #   #     #     #   #   #     #                       " << endl;
	cout << "                                                    #     #   #####      #         #######    ###    #####    ###     #####                        " << endl;
	cout << "                                                                                                                                                   " << endl;
	cout << "                                                          #####                                         #    #                                     " << endl;
	cout << "                                                        #     #  #####    ####   #    #  #####        ##    #    #                                 " << endl;
	cout << "                                                        #        #    #  #    #  #    #  #    #      # #    #    #                                 " << endl;
	cout << "                                                        #  ####  #    #  #    #  #    #  #    #        #    #    #                                 " << endl;
	cout << "                                                        #     #  #####   #    #  #    #  #####         #    #######                                " << endl;
	cout << "                                                        #     #  #   #   #    #  #    #  #             #         #                                 " << endl;
	cout << "                                                         #####   #    #   ####    ####   #           #####       #                                 " << endl;
	cout << "                                                                                                                                                   " << endl;
	cout << "                             ######                                  ######                                                                        " << endl;
	cout << "                             #     #    ##    #####    ##            #     #  #####    ####    ####   ######   ####    ####   #  #    #   ####     " << endl;
	cout << "                             #     #   #  #     #     #  #           #     #  #    #  #    #  #    #  #       #       #       #  ##   #  #    #    " << endl;
	cout << "                             #     #  #    #    #    #    #          ######   #    #  #    #  #       #####    ####    ####   #  # #  #  #         " << endl;
	cout << "                             #     #  ######    #    ######          #        #####   #    #  #       #            #       #  #  #  # #  #  ###    " << endl;
	cout << "                             #     #  #    #    #    #    #          #        #   #   #    #  #    #  #       #    #  #    #  #  #   ##  #    #    " << endl;
	cout << "                             ######   #    #    #    #    #          #        #    #   ####    ####   ######   ####    ####   #  #    #   ####     " << endl;
	cout << "                                                                                                                                                   " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);

	cout << "*************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, FG_LIGHTGREEN);
	cout << "Welcome to the program, it use for searching and update data." << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	cout << "*************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, FG_LIGHTGREEN);
	cout << "Choose What function you want to do " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
	cout << "0. End		" ;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_YELLOW | FOREGROUND_INTENSITY);
	cout << "1. Insertion	2. Searching	3. Deletion	4.combination	5.Modify" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin >> choice;
	SetConsoleTextAttribute(hConsole, saved_colors);
	switch (choice)
	{
	case 0: system("cls"); SetConsoleTextAttribute(hConsole, FG_LIGHTGREEN); cout << "Thanks for using our program!!" << endl; SetConsoleTextAttribute(hConsole, saved_colors); system("pause"); exit(0);
	case 1:	{
		fileinput();
		for (; InnerDataSetHead->next != NULL; InnerDataSetHead = InnerDataSetHead->next);
		system("pause");
		clock_t start;
		double duration;
		start = clock();
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
		//InnerDataSetHead->filListSet->fildisplay(); 
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;
		cout << "Program Run time: " << duration << "s" << '\n';
		SetConsoleTextAttribute(hConsole, saved_colors);
		system("pause"); system("cls"); MainDecision();
	}
	case 2:	MangeInDataSetSearch(); system("pause"); system("cls"); MainDecision();
	case 3: MangeInDataSetDelete(); system("pause"); system("cls"); MainDecision();
	case 4: MangeInDataSetCombine(true,0);system("pause"); system("cls"); MainDecision();
	
	case 5: MangeInDataSetModify(); system("pause"); system("cls"); MainDecision();
	case 6:for (int i = 0; i < 20; i++) {
		SetConsoleTextAttribute(hConsole, FG_LIGHTGREEN);
		cout << i + 1 << "." << DataSethead->typelist[i] << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
	} system("pause"); system("cls"); MainDecision();
	case 7: for (; IninnerDataSetHead != NULL; IninnerDataSetHead = IninnerDataSetHead->next) {
		for (int i = 1; i <= 11; i++) {
			IninnerDataSetHead->filListSet->fildisplay(i);
		}
	}system("pause"); system("cls"); MainDecision();
	default: SetConsoleTextAttribute(hConsole, FG_RED |   FOREGROUND_INTENSITY); cout << "Wrong input" << endl;	SetConsoleTextAttribute(hConsole, saved_colors);system("pause");
		 system("cls"); MainDecision();
	}
}



void DataSetlist::MangeInDataSetSearch() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	int counter = 0;
	int x;
	bool check = false;
	DataSet* CurrNode = DataSethead;
	SetConsoleTextAttribute(hConsole, FG_LIGHTGREEN);
	cout << "which DataSet you want to modify" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	for (CurrNode = DataSethead; CurrNode != NULL; CurrNode=CurrNode->next) {
		counter++;
		SetConsoleTextAttribute(hConsole, FG_LIGHTGREEN);
		cout << "DataSet " << counter << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
	}
	cout << "*************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin >> x;
	SetConsoleTextAttribute(hConsole, saved_colors);
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
		SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
		cout << "Wrong input" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
		MainDecision();
	}
	else {
		MakeSearchingChoice(x);
	}
}

void DataSetlist::MakeSearchingChoice(int x) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	int y;

	SetConsoleTextAttribute(hConsole, FG_YELLOW | FOREGROUND_INTENSITY);
	cout << "1. By ID	2. By Name	3. By Year	4. By Programe Type	 5.By Movie Type	";
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
	cout << "0. Stop Searching" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin >> y;
	SetConsoleTextAttribute(hConsole, saved_colors);
	switch (y)
	{
	case 0: return;
	case 1: searchingByID(x); system("pause"); system("cls"); MainDecision();
	case 2: searchingByName(x); system("pause"); system("cls"); MainDecision();
	case 3: searchingByYear(x); system("pause"); system("cls"); MainDecision();
	case 4: searchingByPgType(x); system("pause"); system("cls"); MainDecision();
	case 5: NumberOfType(x); system("pause"); system("cls"); MainDecision();
	default: SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY); cout << "Wrong input." << endl; SetConsoleTextAttribute(hConsole, saved_colors); MakeSearchingChoice(x);
	}
}

void DataSetlist::searchingByID(int x) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	string y;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the ID of the data" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, y);
	SetConsoleTextAttribute(hConsole, saved_colors);
	clock_t start;
	double duration;
	start = clock();
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
			SetConsoleTextAttribute(hConsole, FG_WHITE | FOREGROUND_INTENSITY);
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);
			counter++;
			break;
		}
	}

	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors); system("pause");

	if (counter == 0) {
		SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
		cout << "No data found" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
	}
	else {
		SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
		cout << "Number of Data: " << counter << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
	}

}

void DataSetlist::searchingByName(int x) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	string y;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the Name of the data" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, y);
	SetConsoleTextAttribute(hConsole, saved_colors);
	clock_t start;
	double duration;
	start = clock();
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
			SetConsoleTextAttribute(hConsole, FG_WHITE | FOREGROUND_INTENSITY);
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);
			counter++;

		}
	}

	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors); system("pause");

	if (counter == 0) {
		SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
		cout << "No data found" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
	}
	else {
		SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
		cout << "Number of data: " << counter << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
	}

}

void DataSetlist::searchingByYear(int x) {// add number of data which is equal to the year that user want to search
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	string y;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the Year of the data" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	cin.ignore();
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	getline(cin, y);
	SetConsoleTextAttribute(hConsole, saved_colors);
	clock_t start;
	double duration;
	start = clock();
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
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Number of data match: ";
	SetConsoleTextAttribute(hConsole, saved_colors);
	newfillist->make_Type_List(CurrNode->listSet->head, y);
	innerfillist->next = newfillist;
	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors); system("pause");
	innerfillist->next->fildisplay(i); system("pause"); system("cls"); MainDecision();
}

void DataSetlist::searchingByPgType(int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	int x;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Which programme type?" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);

	SetConsoleTextAttribute(hConsole, FG_YELLOW | FOREGROUND_INTENSITY);
	cout << "1. movie		2. short	3. tvEpisode	4. tvMiniSeries		5. tvMovie	" << endl;
	cout << "6. tvSeries	7. tvShort	8. tvSpecial	9. video			10. videoGame	" << endl;
	SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
	cout << "0. End" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin >> x;

	clock_t start;
	double duration;
	start = clock();
	SetConsoleTextAttribute(hConsole, saved_colors);
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
		case 1: SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				cout << "Program Run time: " << duration << "s" << '\n'; system("pause");
				CurrNode->filListSet->fildisplay(1); system("pause"); system("cls"); MainDecision();  //shortlist
		case 2: SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				cout << "Program Run time: " << duration << "s" << '\n'; system("pause");
				CurrNode->filListSet->fildisplay(2); system("pause"); system("cls"); MainDecision(); //movielist
		case 3: SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				cout << "Program Run time: " << duration << "s" << '\n'; system("pause");
				CurrNode->filListSet->fildisplay(3); system("pause"); system("cls"); MainDecision(); //tvserieslist
		case 4: SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				cout << "Program Run time: " << duration << "s" << '\n'; system("pause");
				CurrNode->filListSet->fildisplay(4); system("pause"); system("cls"); MainDecision(); //tvepisode
		case 5:	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				cout << "Program Run time: " << duration << "s" << '\n'; system("pause");
				CurrNode->filListSet->fildisplay(5); system("pause"); system("cls"); MainDecision(); //videolist
		case 6:	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				cout << "Program Run time: " << duration << "s" << '\n'; system("pause");
				CurrNode->filListSet->fildisplay(6); system("pause"); system("cls"); MainDecision();
		case 7:	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				cout << "Program Run time: " << duration << "s" << '\n'; system("pause");
				CurrNode->filListSet->fildisplay(7); system("pause"); system("cls"); MainDecision();
		case 8:	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				cout << "Program Run time: " << duration << "s" << '\n'; system("pause");
				CurrNode->filListSet->fildisplay(8); system("pause"); system("cls"); MainDecision();
		case 9:	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				cout << "Program Run time: " << duration << "s" << '\n'; system("pause");
				CurrNode->filListSet->fildisplay(9); system("pause"); system("cls"); MainDecision();
		case 10:SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				cout << "Program Run time: " << duration << "s" << '\n'; system("pause");
				CurrNode->filListSet->fildisplay(10); system("pause"); system("cls"); MainDecision();
		default: searchingByPgType(y);
		}
}

void DataSetlist::NumberOfType(int x) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	int y;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "How many type you want to input? Maximun: 3. " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin >> y;
	SetConsoleTextAttribute(hConsole, saved_colors);
	switch (y) {
	case 1: searchingByType1(x); MainDecision();
	case 2: searchingByType2(x); MainDecision();
	case 3: searchingByType3(x); MainDecision();
		SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
	default: cout << "Wrong input" << endl; NumberOfType(x);
		SetConsoleTextAttribute(hConsole, saved_colors);

	}
}

void DataSetlist::searchingByType1(int x) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	string y;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the type of the data: " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, y);
	SetConsoleTextAttribute(hConsole, saved_colors);

	clock_t start;
	double duration;
	start = clock();
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
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	SetConsoleTextAttribute(hConsole, saved_colors);

	cout << "Number of data match: ";
	newfillist->make_Type_List(CurrNode->listSet->head, y);
	innerfillist->next = newfillist;
	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);
	system("pause");
	innerfillist->next->fildisplay(i); system("pause"); system("cls"); MainDecision();
}

void DataSetlist::searchingByType2(int x) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	string j,k;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the first type of the data: " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, j);
	SetConsoleTextAttribute(hConsole, saved_colors);
	cout << "*************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the second type of the data: " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	getline(cin, k);
	clock_t start;
	double duration;
	start = clock();
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
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);
	innerfillist->next->fildisplay(i); system("pause"); system("cls"); MainDecision();
	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);

}

void DataSetlist::searchingByType3(int x) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	string j, k,l;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the first type of the data: " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, j);
	SetConsoleTextAttribute(hConsole, saved_colors);
	cout << "*************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the second type of the data: " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	getline(cin, k);
	SetConsoleTextAttribute(hConsole, saved_colors);
	cout << "*************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the third type of the data: " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	getline(cin, l);
	SetConsoleTextAttribute(hConsole, saved_colors);

	clock_t start;
	double duration;
	start = clock();
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
	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);
	innerfillist->next->fildisplay(i); system("pause"); system("cls"); MainDecision();
}



void DataSetlist::MangeInDataSetModify(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	int counter = 0;
	int x;
	bool check = false;
	DataSet* CurrNode = DataSethead;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Which DataSet you want to modify ?" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
		counter++;
		SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
		cout << "DataSet " << counter << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
	}
	cout << "*************************************************************" << endl;
	cin >> x;
	clock_t start;
	double duration;
	start = clock();
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
		SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
		cout << "Wrong input" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
		MainDecision();;
	}
	else {
		MakeModifyingChoice(x);
	}
	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);

}

void DataSetlist::MakeModifyingChoice(int x){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	int y;
	SetConsoleTextAttribute(hConsole, FG_YELLOW | FOREGROUND_INTENSITY);
	cout << "1. By ID	2. By Name	3. By Year	4. By Programe Type	 5.By Movie Type	";
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
	cout << "0. Stop Searching" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA| FOREGROUND_INTENSITY);
	cin >> y;
	SetConsoleTextAttribute(hConsole, saved_colors);
	switch (y)
	{
	case 0: return;
	case 1: ModifyingByID(x); system("pause"); system("cls"); MainDecision();
	case 2: ModifyingByName(x); system("pause"); system("cls"); MainDecision();
	case 3: ModifyingByYear(x); system("pause"); system("cls"); MainDecision();
	case 4: ModifyingByPgType(x); system("pause"); system("cls"); MainDecision();
	case 5: modifyingByType(x); system("pause"); system("cls"); MainDecision();
		SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
	default: cout << "Wrong input." << endl; system("pause"); system("cls"); MakeSearchingChoice(x);
		SetConsoleTextAttribute(hConsole, saved_colors);
	}
}

void DataSetlist::ModifyingByID(int x) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	string y;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the ID of the data" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, y);
	SetConsoleTextAttribute(hConsole, saved_colors);
	clock_t start;
	double duration;
	start = clock();
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
			SetConsoleTextAttribute(hConsole, FG_WHITE | FOREGROUND_INTENSITY);
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);
			SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
			cout << "Enter the programme title" << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);
			SetConsoleTextAttribute(hConsole, FG_YELLOW | FOREGROUND_INTENSITY);
			cout << "movie		short	  tvEpisode	  tvMiniSeries	 tvMovie	" << endl;
			cout << "tvSeries	tvShort	  tvSpecial	  video		     videoGame " << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);
			SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
			cin >> CurrNode1->titleType;
			SetConsoleTextAttribute(hConsole, saved_colors);
			SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
			cout << "Enter the name of the data" << endl; 
			SetConsoleTextAttribute(hConsole, saved_colors);
			SetConsoleTextAttribute(hConsole, FG_MAGENTA| FOREGROUND_INTENSITY);
			cin >> CurrNode1->primaryTitle;
			SetConsoleTextAttribute(hConsole, saved_colors);
			SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
			cout << "Enter the year" << endl; 
			SetConsoleTextAttribute(hConsole, saved_colors);
			SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
			cin >> CurrNode1->startYear;
			SetConsoleTextAttribute(hConsole, saved_colors);
			SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
			cout << "Enter the duration(H)" << endl; 
			SetConsoleTextAttribute(hConsole, saved_colors);
			SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
			cin >> CurrNode1->runtimeMinutes;
			SetConsoleTextAttribute(hConsole, saved_colors);
			for (int i = 0; i < 3; i++) {
				SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
					cout << "Enter the " << i + 1 << "type of data(If nothing, just input /.) : " << endl; 
					SetConsoleTextAttribute(hConsole, saved_colors);
					SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
					cin >> CurrNode1->genres[i];
					SetConsoleTextAttribute(hConsole, saved_colors);
			}
			counter++;
			break;
		}
	}

	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);

	if (counter == 0) {
		SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
		cout << "No data found" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
	}
	else {
		SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
		cout << "Number of Data change: " << counter << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	string y;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the Name of the data" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, y);
	SetConsoleTextAttribute(hConsole, saved_colors);
	clock_t start;
	double duration;
	start = clock();
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
			SetConsoleTextAttribute(hConsole, FG_WHITE | FOREGROUND_INTENSITY);
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);
			SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
			cout << "Enter the programme title" << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);
			SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
			cout << "movie		short	  tvEpisode	  tvMiniSeries	 tvMovie	" << endl;
			cout << "tvSeries	tvShort	  tvSpecial	  video		     videoGame " << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);
			SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
			cin >> CurrNode1->titleType;
			SetConsoleTextAttribute(hConsole, saved_colors);
			SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
			cout << "Enter the name of the data" << endl;cin >> CurrNode1->primaryTitle;
			SetConsoleTextAttribute(hConsole, saved_colors);
			SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
			cout << "Enter the year" << endl; 
			SetConsoleTextAttribute(hConsole, saved_colors);
			SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
			cin >> CurrNode1->startYear;
			SetConsoleTextAttribute(hConsole, saved_colors);
			SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
			cout << "Enter the duration(H)" << endl;
			SetConsoleTextAttribute(hConsole, saved_colors); 
			SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
			cin >> CurrNode1->runtimeMinutes;
			SetConsoleTextAttribute(hConsole, saved_colors);
			for (int i = 0; i < 3; i++) {
				if (CurrNode1->genres[i] != " ") {
					SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
					cout << "Enter the ";
					SetConsoleTextAttribute(hConsole, saved_colors);
					SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
					cout << i + 1 ;
					SetConsoleTextAttribute(hConsole, saved_colors);
					SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
					cout << "type of data" << endl;
					SetConsoleTextAttribute(hConsole, saved_colors);
					SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
					cin >> CurrNode1->genres[i];
					SetConsoleTextAttribute(hConsole, saved_colors);
				}
			}
			counter++;
			break;
		}
	}

	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);

	if (counter == 0) {
		SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
		cout << "No data found" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
	}
	else {
		SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
		cout << "Number of Data change: " << counter << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	string y,z;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the Year of the data" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, y);
	SetConsoleTextAttribute(hConsole, saved_colors);
	cout << "*************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Changing to what year? (YYYY)" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	getline(cin, z);
	SetConsoleTextAttribute(hConsole, saved_colors);
	clock_t start;
	double duration;
	start = clock();
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

	
	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);

	if (counter == 0) {
		SetConsoleTextAttribute(hConsole, FG_RED| FOREGROUND_INTENSITY);
		cout << "No data match" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
	}
	else {
		cout << "*************************************************************" << endl;
		SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
		cout << "Number of Data change: " << counter << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
	}
	system("pause");

	for (CurrNode1 = CurrNode->listSet->head; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		if (z.compare(CurrNode1->startYear) == 0) {
			SetConsoleTextAttribute(hConsole, FG_WHITE | FOREGROUND_INTENSITY);
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);
		}
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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	string y, z;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the programme of the data" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, y);
	SetConsoleTextAttribute(hConsole, saved_colors);

	cout << "*************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Changing to whtat programme type?" << endl;
	cout << "movie		short	  tvEpisode	  tvMiniSeries	 tvMovie	" << endl;
	cout << "tvSeries	tvShort	  tvSpecial	  video		     videoGame " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	cout << "*************************************************************" << endl;
	
	SetConsoleTextAttribute(hConsole, FG_MAGENTA| FOREGROUND_INTENSITY);
	getline(cin, z);
	SetConsoleTextAttribute(hConsole, saved_colors);
	clock_t start;
	double duration;
	start = clock();
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

	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);

	if (counter == 0) {
		SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
		cout << "No data match" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

	}
	else {
		cout << "*************************************************************" << endl;
		SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
		cout << "Number of Data change: " << counter << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

	}
	system("pause");

	for (CurrNode1 = CurrNode->listSet->head; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {

		if (z.compare(CurrNode1->titleType) == 0) {
			SetConsoleTextAttribute(hConsole, FG_WHITE | FOREGROUND_INTENSITY);
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);

		}
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

void DataSetlist::modifyingByType(int x) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	string y, a;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the type of the data: " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, y);
	SetConsoleTextAttribute(hConsole, saved_colors);
	cout << "*************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the type of the data you want to replace : " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	getline(cin, a);
	SetConsoleTextAttribute(hConsole, saved_colors);

	clock_t start;
	double duration;
	start = clock();
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
				CurrNode1->genres[i] = a;
				//cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
				counter++;
				break;
			}
		}
	}

	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);

	if (counter == 0) {
		SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);

		cout << "No data match" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

		cout << "*************************************************************" << endl;
	}
	else {
		SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
		cout << "Number of Data: " << counter << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
		cout << "*************************************************************" << endl;
	}
	system("pause");

	for (CurrNode1 = CurrNode->listSet->head; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		for (int i = 0; i < 3; i++) {
			if (a.compare(CurrNode1->genres[i]) == 0) {
				SetConsoleTextAttribute(hConsole, FG_WHITE | FOREGROUND_INTENSITY);
				cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
				SetConsoleTextAttribute(hConsole, saved_colors);
				break;
			}
		}
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




void DataSetlist::MangeInDataSetDelete() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	int counter = 0;
	int x;
	bool check = false;
	DataSet* CurrNode = DataSethead;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Which DataSet you want to modify? " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);

	for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
		counter++;
		SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
		cout << "DataSet " << counter << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

	}
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin >> x;
	SetConsoleTextAttribute(hConsole, saved_colors);

	counter = 0;
	for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
		counter++;
		if (counter == x) {
			check = true;
			break;
		}
	}
	if (check == false) {
		SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
		cout << "Wrong input" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

		MainDecision();
	}
	else {
		MakeDeletionChoice(x);
	}
}

void DataSetlist::MakeDeletionChoice(int x) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	int y;
	SetConsoleTextAttribute(hConsole, FG_YELLOW | FOREGROUND_INTENSITY);
	cout << "1. By ID   2. By Name   3. By Year   4. By Programe Type   5.By Movie Type   ";
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
	cout << "0. Stop Searching" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin >> y;
	SetConsoleTextAttribute(hConsole, saved_colors);

	switch (y)
	{
	case 0: return;
	case 1: DeletionByID(x); system("pause"); system("cls"); MainDecision();
	case 2: DeletionByName(x); system("pause"); system("cls"); MainDecision();
	case 3: DeletionByYear(x); system("pause"); system("cls"); MainDecision();
	case 4: DeletionByPgType(x); system("pause"); system("cls"); MainDecision();
	case 5: NumberOfTypeDel(x); system("pause"); system("cls"); MainDecision();
	default: system("cls"); MakeDeletionChoice(x);
	}
}

void DataSetlist::DeletionByID(int x) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	string y;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the ID of the data" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);

	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, y);
	SetConsoleTextAttribute(hConsole, saved_colors);

	clock_t start;
	double duration;
	start = clock();
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
			SetConsoleTextAttribute(hConsole, FG_WHITE | FOREGROUND_INTENSITY);
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			CurrNode->listSet->head = CurrNode1->next;
			SetConsoleTextAttribute(hConsole, saved_colors);

			cout << "*************************************************************" << endl;
			SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
			cout << "Data has been deleted" << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);

			counter++;
			break;
		}
		else if (preNode != NULL && y.compare(CurrNode1->tconst) == 0) {
			SetConsoleTextAttribute(hConsole, FG_WHITE | FOREGROUND_INTENSITY);
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			preNode->next = CurrNode1->next;
			SetConsoleTextAttribute(hConsole, saved_colors);

			delete CurrNode1;
			cout << "*************************************************************" << endl;
			SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
			cout << "Data has been deleted" << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);

			counter++;
			break;
		}
	}

	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);
	system("pause");

	if (counter == 0) {
		SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
		cout << "Data not found" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

	}

	for (CurrNode1 = CurrNode->listSet->head; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		SetConsoleTextAttribute(hConsole, FG_WHITE | FOREGROUND_INTENSITY);
		cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	string y;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the Name of the data" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, y);
	SetConsoleTextAttribute(hConsole, saved_colors);

	clock_t start;
	double duration;
	start = clock();
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
			SetConsoleTextAttribute(hConsole, FG_WHITE | FOREGROUND_INTENSITY);
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			CurrNode->listSet->head = CurrNode1->next;
			SetConsoleTextAttribute(hConsole, saved_colors);

			cout << "*************************************************************" << endl;
			SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
			cout << "Data has been deleted" << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);

			counter++;
			break;
		}
		else if (preNode != NULL && y.compare(CurrNode1->primaryTitle) == 0) {
			SetConsoleTextAttribute(hConsole, FG_WHITE | FOREGROUND_INTENSITY);
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			preNode->next = CurrNode1->next;
			SetConsoleTextAttribute(hConsole, saved_colors);

			delete CurrNode1;
			cout << "*************************************************************" << endl;
			SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
			cout << "Data has been deleted" << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);

			counter++;
			break;
		}
	}

	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);
	system("pause");

	if (counter == 0) {
		SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
		cout << "Data not found" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

	}
	for (CurrNode1 = CurrNode->listSet->head; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
		SetConsoleTextAttribute(hConsole, FG_WHITE | FOREGROUND_INTENSITY);
		cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	string y;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the Year of the data" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, y);
	SetConsoleTextAttribute(hConsole, saved_colors);

	clock_t start;
	double duration;
	start = clock();
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

	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);
	system("pause");

	if (counter == 0) {
		SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
		cout << "No data match" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

	}
	else {
		for (; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
			//SetConsoleTextAttribute(hConsole, FG_WHITE | FOREGROUND_INTENSITY);
			//cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			//SetConsoleTextAttribute(hConsole, saved_colors);

		}
		SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
		cout << "Number of Datad deleted: " << counter << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	string y;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the programe type of the data" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, y);
	SetConsoleTextAttribute(hConsole, saved_colors);

	clock_t start;
	double duration;
	start = clock();
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

	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);
	system("pause");

	if (counter == 0) {
		SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
		cout << "No data match" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

	}
	else {
		for (; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
			SetConsoleTextAttribute(hConsole, FG_WHITE | FOREGROUND_INTENSITY);
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);

		}
		SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
		cout << "Number of Datad deleted: " << counter << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	int y;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "How many type U want to input? Maximun: 3. " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA| FOREGROUND_INTENSITY);
	cin >> y;
	SetConsoleTextAttribute(hConsole, saved_colors);

	switch (y) {
	case 1: DeleteByType1(x); MainDecision();
	case 2: DeleteByType2(x); MainDecision();
	case 3: DeleteByType3(x); MainDecision();
	default: NumberOfType(x);
	}

}

void DataSetlist::DeleteByType1(int x) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	bool check = false;
	string y;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the type of the data: " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, y);
	SetConsoleTextAttribute(hConsole, saved_colors);

	clock_t start;
	double duration;
	start = clock();
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

	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);
	system("pause");

	if (counter == 0) {
		SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
		cout << "No data match" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

	}
	else {
		for (; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
			SetConsoleTextAttribute(hConsole, FG_WHITE | FOREGROUND_INTENSITY);
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);

		}
		SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
		cout << "Number of Datad deleted: " << counter << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	bool check = false;
	string j, k;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the first type of the data: " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA| FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, j);
	SetConsoleTextAttribute(hConsole, saved_colors);

	cout << "*************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the second type of the data: " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	getline(cin, k);
	SetConsoleTextAttribute(hConsole, saved_colors);

	clock_t start;
	double duration;
	start = clock();
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

	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);
	system("pause");

	if (counter == 0) {
		SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
		cout << "No data match" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

	}
	else {
		for (; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
			SetConsoleTextAttribute(hConsole, FG_WHITE | FOREGROUND_INTENSITY);
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);

		}
		SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
		cout << "Number of Datad deleted: " << counter << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	bool check = false;
	string j, k, l;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the first type of the data: " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, j);
	SetConsoleTextAttribute(hConsole, saved_colors);

	cout << "*************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the second type of the data: " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	getline(cin, k);
	SetConsoleTextAttribute(hConsole, saved_colors);

	cout << "*************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the third type of the data: " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	getline(cin, l);
	SetConsoleTextAttribute(hConsole, saved_colors);

	clock_t start;
	double duration;
	start = clock();
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

	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);
	system("pause");

	if (counter == 0) {
		SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
		cout << "No data match" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

	}
	else {
		for (; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
			SetConsoleTextAttribute(hConsole, FG_WHITE | FOREGROUND_INTENSITY);
			cout << CurrNode1->tconst << "\t" << CurrNode1->titleType << "\t" << CurrNode1->primaryTitle << "\t" << CurrNode1->startYear << "\t" << CurrNode1->runtimeMinutes << "\t" << CurrNode1->genres[0] << "\t" << CurrNode1->genres[1] << "\t" << CurrNode1->genres[2] << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);

		}
		SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
		cout << "Number of Datad deleted: " << counter << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	int counter = 0;
	int x;
	bool check = false;
	DataSet* CurrNode = DataSethead;
	clock_t start;
	double duration;
	start = clock();
	if (firsttime == true) {
		SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
		cout << "Which DataSet you want to combine?" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
		SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
		cout << "Reminder:This DataSet will be the path of the list)" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

		for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
			counter++;
			SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
			cout << "DataSet " << counter << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);

		}
		cout << "*************************************************************" << endl;
		SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
		cin >> x;
		SetConsoleTextAttribute(hConsole, saved_colors);

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
		SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
		cout << "Which DataSet you want to combine?" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
		SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
		cout << "Reminder:This will not be the path of the list)" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

		for (CurrNode = DataSethead; CurrNode != NULL; CurrNode = CurrNode->next) {
			counter++;
			SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
			cout << "DataSet " << counter << endl;
			SetConsoleTextAttribute(hConsole, saved_colors);

		}
		cout << "*************************************************************" << endl;
		SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
		cin >> x;
		SetConsoleTextAttribute(hConsole, saved_colors);


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
		SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
		cout << "Here is no such a DataSet" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);
		SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
		cout << "Now return to lobby" << endl;
		SetConsoleTextAttribute(hConsole, saved_colors);

		system("pause");
		system("cls");
		MainDecision();
	}
	else {
		MakeCombineChoice(x, firsttime, targetpos);
	}
	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);

};

void DataSetlist::MakeCombineChoice(int x, bool firsttime, int targetpos) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	int y;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "1. By ID	2. By Name	3. By Year	4. By Programe Type	 5.By Movie Type	";
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
	cout << "0. Stop Searching" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin >> y;
	SetConsoleTextAttribute(hConsole, saved_colors);

	switch (y)
	{
	case 0: return;
	case 1: combineByID(x, firsttime, targetpos); system("pause"); system("cls"); MainDecision();
	case 2: combineByName(x , firsttime, targetpos); system("pause"); system("cls"); MainDecision();
	case 3: combineByYear(x , firsttime, targetpos); system("pause"); system("cls"); MainDecision();
	case 4: combineByPgType(x , firsttime, targetpos); system("pause"); system("cls"); MainDecision();
	case 5: combineNumberOfType(x , firsttime, targetpos); system("pause"); system("cls"); MainDecision();
		SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
	default: cout << "Wrong input." << endl; 
		SetConsoleTextAttribute(hConsole, saved_colors);
		system("pause"); system("cls"); MainDecision();
	}
}

void DataSetlist::combineNumberOfType(int x, bool firsttime, int targetpos) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	int y;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "How many type you want to input? Maximun: 3. " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin >> y;
	SetConsoleTextAttribute(hConsole, saved_colors);

	switch (y) {
	case 1: combineByType1(x, firsttime, targetpos);
	case 2: combineByType2(x, firsttime, targetpos);
	case 3: combineByType3(x, firsttime, targetpos);
	default: combineNumberOfType(x, firsttime, targetpos);
	}
}

void DataSetlist::combineByID(int x, bool firsttime, int targetpos) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	string y;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the ID of the data" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, y);
	SetConsoleTextAttribute(hConsole, saved_colors);

	clock_t start;
	double duration;
	start = clock();
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
		SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;
		cout << "Program Run time: " << duration << "s" << '\n';
		SetConsoleTextAttribute(hConsole, saved_colors); system("pause");
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
		SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;
		cout << "Program Run time: " << duration << "s" << '\n';
		SetConsoleTextAttribute(hConsole, saved_colors); system("pause");
		innerfillist->fildisplay(i); system("pause"); system("cls"); MainDecision();
	}
}

void DataSetlist::combineByName(int x, bool firsttime, int targetpos) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	string y;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the Name of the data" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, y);
	SetConsoleTextAttribute(hConsole, saved_colors);

	clock_t start;
	double duration;
	start = clock();
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
		SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;
		cout << "Program Run time: " << duration << "s" << '\n';
		SetConsoleTextAttribute(hConsole, saved_colors); system("pause");
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
		newfillist->make_Type_List(CurrNode1->listSet->head, y);
		innerfillisthead->filnext = newfillist->filhead;
		SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
		duration = (clock() - start) / (double)CLOCKS_PER_SEC;
		cout << "Program Run time: " << duration << "s" << '\n';
		SetConsoleTextAttribute(hConsole, saved_colors); system("pause");
		innerfillist->fildisplay(i); system("pause"); system("cls"); MainDecision();
	}

}

void DataSetlist::combineByYear(int x, bool firsttime, int targetpos){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	string y;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the Year of the data" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	getline(cin, y);
	SetConsoleTextAttribute(hConsole, saved_colors);

	clock_t start;
	double duration;
	start = clock();
	cout << "*************************************************************" << endl;
	int	counter = 0;
	int i = 0;
	DataSet* CurrNode = DataSethead;
	DataSet* CurrNode1 = DataSethead;
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
		counter = 0;
		for (CurrNode1 = DataSethead; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
			counter++;
			if (counter == x) {
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
		newfillist->make_Type_List(CurrNode1->listSet->head, y);
		innerfillisthead->filnext = newfillist->filhead;
		innerfillist->fildisplay(i); system("pause"); system("cls"); MainDecision();
	}
	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);
}

void DataSetlist::combineByPgType(int x, bool firsttime, int targetpos) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	int y;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Which programme type?" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_YELLOW | FOREGROUND_INTENSITY);
	cout << "1. movie		2. short	3. tvEpisode	4. tvMiniSeries		5. tvMovie	" << endl;
	cout << "6. tvSeries	7. tvShort	8. tvSpecial	9. video			10. videoGame	" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_RED | FOREGROUND_INTENSITY);
	cout << "0. End" << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin >> y;
	SetConsoleTextAttribute(hConsole, saved_colors);

	clock_t start;
	double duration;
	start = clock();
	int	counter = 0;
	int i = 0;
	DataSet* CurrNode = DataSethead;
	DataSet* CurrNode1 = DataSethead;
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
		counter = 0;
		for (CurrNode1 = DataSethead; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
			counter++;
			if (counter == x) {
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
		newfillist->make_Type_List(CurrNode1->listSet->head, CurrNode->typelist[y-1]);
		innerfillisthead->filnext = newfillist->filhead;
		innerfillist->fildisplay(i); system("pause"); system("cls"); MainDecision();
	}
	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);
}

void DataSetlist::combineByType1(int x, bool firsttime, int targetpos) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	string y;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the type of the data: " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, y);
	SetConsoleTextAttribute(hConsole, saved_colors);

	clock_t start;
	double duration;
	start = clock();
	cout << "*************************************************************" << endl;
	int	counter = 0;
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
		newfillist->make_Type_List(CurrNode1->listSet->head, y);
		innerfillisthead->filnext = newfillist->filhead;
		innerfillist->fildisplay(i); system("pause"); system("cls"); MainDecision();
	}
	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);
}

void DataSetlist::combineByType2(int x, bool firsttime, int targetpos) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	string j, k;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the first type of the data: " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, j);
	SetConsoleTextAttribute(hConsole, saved_colors);

	cout << "*************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the second type of the data: " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	getline(cin, k);
	SetConsoleTextAttribute(hConsole, saved_colors);

	clock_t start;
	double duration;
	start = clock();
	cout << "*************************************************************" << endl;
	int	counter = 0;
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
		counter = 0;
		for (CurrNode1 = DataSethead; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
			counter++;
			if (counter == x) {
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
		newfillist->make_gen_List2(CurrNode1->listSet->head, j,k);
		innerfillisthead->filnext = newfillist->filhead;
		innerfillist->fildisplay(i); system("pause"); system("cls"); MainDecision();
	}
	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);
}

void DataSetlist::combineByType3(int x, bool firsttime, int targetpos) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //color
	const int saved_colors = GetConsoleTextAttribute(hConsole); //color
	string j, k, l;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the first type of the data: " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	cin.ignore();
	getline(cin, j);
	SetConsoleTextAttribute(hConsole, saved_colors);

	cout << "*************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the second type of the data: " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	getline(cin, k);
	SetConsoleTextAttribute(hConsole, saved_colors);

	cout << "*************************************************************" << endl;
	SetConsoleTextAttribute(hConsole, FG_GREEN | FOREGROUND_INTENSITY);
	cout << "Enter the third type of the data: " << endl;
	SetConsoleTextAttribute(hConsole, saved_colors);
	SetConsoleTextAttribute(hConsole, FG_MAGENTA | FOREGROUND_INTENSITY);
	getline(cin, l);
	SetConsoleTextAttribute(hConsole, saved_colors);

	clock_t start;
	double duration;
	start = clock();
	cout << "*************************************************************" << endl;
	int	counter = 0;
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
		counter = 0;
		for (CurrNode1 = DataSethead; CurrNode1 != NULL; CurrNode1 = CurrNode1->next) {
			counter++;
			if (counter == x) {
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
		newfillist->make_gen_List3(CurrNode1->listSet->head, j, k, l);
		innerfillisthead->filnext = newfillist->filhead;
		innerfillist->fildisplay(i); system("pause"); system("cls"); MainDecision();
	}
	SetConsoleTextAttribute(hConsole, FG_LIGHTCYAN | FOREGROUND_INTENSITY);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "Program Run time: " << duration << "s" << '\n';
	SetConsoleTextAttribute(hConsole, saved_colors);
}

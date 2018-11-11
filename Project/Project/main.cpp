#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include <cstdio>
#include <ctime>

using namespace std;
//DataSet Name : DataSet1_1000
class Node {
protected:
	// All the data member (Attributes)
	string tconst;
	string titleType;
	string primaryTitle;
	string startYear;
	string runtimeMinutes;
	string genres[3];
	// To make a pointer pointing to the next set of data, linking process
	Node * next;
public:
	//Default constructor
	Node() {
		tconst = " ";
		titleType = " ";
		primaryTitle = " ";
		startYear = " ";
		runtimeMinutes = " ";
		genres[0] = " ";
		genres[1] = " ";
		genres[2] = " ";
		next = NULL;
	};
	//Accessor & Mutator
	Node(string tconst, string titleType, string primaryTitle, string startYear, string runtimeMinutes, string genre) {
		this->tconst = tconst;
		this->titleType = titleType;
		this->primaryTitle = primaryTitle;
		this->startYear = startYear;
		this->runtimeMinutes = runtimeMinutes;
		this->genres[0] = genre;
		this->genres[1] = genre;
		this->genres[2] = genre;
		next = NULL;
	};
	string get_tconst() {
		return tconst;
	};
	string get_titleType() {
		return titleType;
	};
	string get_primaryTitle() {
		return primaryTitle;
	};
	string get_startYear() {
		return startYear;
	};
	string get_runtimeMinutes() {
		return runtimeMinutes;
	};
	string get_genres(int index) {
		return genres[index];
	};

	void set_tconst(string tconst) {

	};
	void set_titleType(string titleType) {

	};
	void set_primaryTitle(string primaryTitle) {

	};
	void set_startYear(string startYear) {

	};
	void set_runtimeMinutes(string runtimeMinutes) {

	};
	/*ifstream for inputting DataSet, a console user interface
	TODO::
	1. Userinput of filename to read file
	2. Separate the dataset into different attributes
	3. A little demonstration of printing out the whole DataSet
	*/
	void fileinput() {
		ifstream dataSet;
		string filename = " ";
		cout << "Which dataSet you want to input?" << endl;
		cout << "Filename: ";
		cin >> filename;
		cout << endl;

		//CHeck whether the file can open correctly
		dataSet.open(filename);
		if (!(dataSet.is_open())) {
			cerr << "Error. The file doesn't open correctly." << endl;
		}
		else {
			getline(dataSet, tconst, '\t');
			getline(dataSet, titleType, '\t');
			getline(dataSet, primaryTitle, '\t');
			getline(dataSet, startYear, '\t');
			getline(dataSet, runtimeMinutes, '\t');
			string originalgenre = " ";
			string symbol = "\"";
			string symbolofnothing = "\N";
			getline(dataSet, originalgenre, '\n');
			cout << originalgenre.substr(0, 2);
			if ((originalgenre.substr(0, 0) != symbol) && (originalgenre.substr(0, 2) != symbolofnothing)) {
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
				for (int i = 0; i < originalgenre.length(); i++){
					
				}
			}
			/*Different case of genres: case 1: genres[3] = "Drama,Short,Western"
			case 2: genres[2] = "Drama,Short"
			case 3: genres[1] = Drama
			case 4: genres[0] = \N
			TODO::
			Check with the number of commas(case 1 & 2)
			Instruction:
			1. using for loop for checking the whole string
			i.e. for(int i = 0; i < originalgenre.length(); i++){};
			2. set an array to remember the position of array remPos[a,b,c,d,e,f,g]
			3. output the string using substr(a+1,b)
			#Reminder: substr from the starting point always be (1, a) to ignore the symbol
			4. make another array for recording the types of genres
			5. find the total number of genres and assign those genres into integer value.
			6. sorting the array, using simple hash table algorithm
			i.e.     int lower = ( temp[0] <= 'Z' ? temp[0]  - 'A' : temp[0]  - 'a');
			hashTable[lower].push_back(temp);
			*/


			cout << tconst << endl << titleType << endl << primaryTitle << endl << startYear << endl << runtimeMinutes << endl << genres[0] << endl << genres[1] << endl << genres[2] << endl;
		}
	};

	void insertion() {

	}
};


int main() {
	std::clock_t start;
	double duration;

	start = std::clock();

	Node n1;
	n1.fileinput();


	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

	std::cout << "Program Run time: " << duration / 1000 << "mins" << '\n';

	system("pause");
	return 0;

}
//0000
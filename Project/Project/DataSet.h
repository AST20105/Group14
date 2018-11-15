#ifndef DataSet_h
#define DataSet_h


#include <iostream>
#include "List.h"
#include "FilList.h"


using namespace std;

class DataSet
{
public:
	string typelist[20];
	List * listSet;
	FilList * filListSet;
	DataSet * next;
public:
	DataSet() {
		typelist[0] = "movie";
		typelist[1] = "short";
		typelist[2] = "tvEpisode";
		typelist[3] = "tvMiniSeries";
		typelist[4] = "tvMovie";
		typelist[5] = "tvSeries";
		typelist[6] = "tvShort";
		typelist[7] = "tvSpecial";
		typelist[8] = "video";
		typelist[9] = "videoGame";
		for (int i = 10; i < 20; i++) {
			typelist[i] = "";
		};
		listSet = new List();
		filListSet = new FilList();
		next = NULL;
	};

};

#endif
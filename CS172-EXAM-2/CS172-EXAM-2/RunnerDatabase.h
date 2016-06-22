#ifndef RUNNERDATABASE_H
#define RUNNERDATABASE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Runners.h"
using namespace std;

class Database
{
private:
	vector<Runner> DATABASE; // Creates a vector with the "Runner" class in place of the type

public:
	Database(string); // A default constructor that will get input from a txt file and save those inputs in the DATABASE vector
	void SortInOrder(); // This function will sort the DATABASE vector in ascending order according to the Pace of an individual
	void SortIntoColors(Runner&);
	
	// This overrides the "<<" operator so that it can outputs all 3 values that are stored in the DATABASE vector
	friend ostream& operator<<(ostream&, Runner);

	// These functions are going to output the data (first/last names and pace) that is stored in their respective txt files
	void ShowWhiteList();
	void ShowYellowList();
	void ShowGreenList();
	void ShowOrangeList();
	void ShowBlueList();
	void ShowLilacList();
	void ShowRedList();
};

#endif
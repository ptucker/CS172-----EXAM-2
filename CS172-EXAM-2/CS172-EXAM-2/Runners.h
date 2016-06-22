#ifndef RUNNERS_H
#define RUNNERS_H


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

// Declares a class for runners at Bloomsday
class Runner
{
private:
	string FirstName; //Declares a string for the first name of a person from the txt file
	string LastName; //Declares a string for the last name of a person from the txt file
	int Pace; // Declares a integer variable for the pace of aperson from the txt file

	// These variables will act as the maximum limit for qualifcation to be in their respective color catagories
	int WhiteMax;
	int YellowMax;
	int GreenMax;
	int OrangeMax;
	int BlueMax;
	int LilacMax;
	int RedMax;

public:

	// Default constructor
	Runner()
	{
		FirstName = "";
		LastName = "";
		Pace = 0;
	}

	// This function will take that values that are obtained from the text file and save their values to that of the private variables
	Runner(string firstname, string lastname, int pace)
	{
		this->FirstName = firstname; // Saves the value of firstname from the txt file to FirstName
		this->LastName = lastname; // Saves the value of lastname from the txt file to LastName
		this->Pace = pace; // Saves the value of pace from the txt file to Pace
	}

	// This function will return the value of FirstName
	string getFirstName()
	{
		return FirstName;
	}

	// This function will return the value of LastName
	string getLastName()
	{
		return LastName;
	}

	// This function will return the value of Pace
	int getPace()
	{
		return Pace;
	}

	// This function will set and return the maximim value for the white section
	int getWhiteMax()
	{
		WhiteMax = 360;
		return WhiteMax;
	}

	// This function will set and return the maximim value for the yellow section
	int getYellowMax()
	{
		YellowMax = 420;
		return YellowMax;
	}

	// This function will set and return the maximim value for the green section
	int getGreenMax()
	{
		GreenMax = 480;
		return GreenMax;
	}

	// This function will set and return the maximim value for the orange section
	int getOrangeMax()
	{
		OrangeMax = 540;
		return OrangeMax;
	}

	// This function will set and return the maximim value for the blue section
	int getBlueMax()
	{
		BlueMax = 600;
		return BlueMax;
	}

	// This function will set and return the maximim value for the lilac section
	int getLilacMax()
	{
		LilacMax = 720;
		return LilacMax;
	}

	// This function will set and return the maximim value for the red section
	int getRedMax()
	{
		RedMax = 1200;
		return RedMax;
	}


	// This function is used in the DATABASE function "SortInOrder" to make the variable that keeps track of which value is the smallest
	// This function ensures that the values of the vector value that is tested to be smaller than the variable "Smallest" is saved to "Smallest"
	void operator=(Runner& Runr)
	{
		FirstName = Runr.FirstName; // Saves the value of FirstName of the vector value
		LastName = Runr.LastName; // Saves the value of LastName of the vector value
		Pace = Runr.Pace; // Saves the value of Pace of the vector value
	}

	// This function will overload the ">" operator so that it will compare the value of pace to the value of "Runr.Pace" (which is the value stored the DATABASE vector)
	// It will whether or not "Pace" is greater than the current pace value of the vector
	// This will be used in the "SortInOrder" function in the Database class
	bool operator>(Runner& Runr)
	{
		return (Pace > Runr.Pace);
	}
};

#endif



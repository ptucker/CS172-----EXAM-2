////////////////////////////////////////
// Aaron Meyers
// 6/21/16
// CS172: Exam 2
/////////////////////////////////////////

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Runners.h"
#include "RunnerDatabase.h"
using namespace std;

/*******************************************************************************************************


  I affirm that all code givin below is written solely by me
  , Aaron Meyers, 
  and that any help I receieved adhered to the rules stated for this exam. 


********************************************************************************************************/

int main()
{

	// Sends the absolute address of the txt file to the DATABASE class for use in its functions
	Database DATABASE("C:\\Users\\ameyers\\Desktop\\EXAM2\\registrants.txt");
	Runner Runner;

	DATABASE.SortInOrder(); // Calls the function that will sort the info from the "registrant.txt" file into ascendng order according to an individual's pace
	DATABASE.SortIntoColors(Runner);
	
	// Intro for the user
	cout << "1000 different Bloomsday marathon runners have been organized into different color groups"
		<< " depending on the pace (second per mile) that they are going to run the marathon." << endl;
	
	// A list showing the user which number relates to which color section and shows the pace range for one to qualify for a certain clor section
	cout << "\nThe color groups are as follows: " << endl;
	cout << "1) White: 0 - 360 seconds per mile" << endl;
	cout << "2) Yellow: 361 - 420 seconds per mile" << endl;
	cout << "3) Green: 421 - 480 second per mile" << endl;
	cout << "4) Orange: 481 - 540 second per mile" << endl;
	cout << "5) Blue: 541 - 600 seconds per mile" << endl;
	cout << "6) Lilac: 601 - 720 seconds per mile" << endl;
	cout << "7) Blue: 721 - 1200 seconds per mile" << endl;
	
	int choice = 0; // Declares a variable for user input

	// This loop will run 7 times (one for every color section)
	// The user will input a num,ber and they will be provided with the anems ands paces of eveyone who is in the color section that corresponds to the number that the user inputs
	for (int i = 0; i < 7; i++)
	{
		cout << "\n\nWhich list do you want to look through?" << endl;
		cin >> choice; // Get input from the user
		
		cout << endl; // Outputs an empty line

		if (choice == 1) // Executes if the user inputs a 1
		{
			DATABASE.ShowWhiteList(); // Calls the function that will display the names of paces of people in the white color group
			cout << endl; // Outputs an empty line
		}

		else if (choice == 2) // Executes if the user inputs a 2
		{
			DATABASE.ShowYellowList(); // Calls the function that will display the names of paces of people in the yellow color group
			cout << endl; // Outputs an empty line
		}

		else if (choice == 3) // Executes if the user inputs a 3
		{
			DATABASE.ShowGreenList(); // Calls the function that will display the names of paces of people in the green color group
			cout << endl; // Outputs an empty line
		}

		else if (choice == 4) // Executes if the user inputs a 4
		{
			DATABASE.ShowOrangeList(); // Calls the function that will display the names of paces of people in the orange color group
			cout << endl; // Outputs an empty line
		}

		else if (choice == 5) // Executes if the user inputs a 5
		{
			DATABASE.ShowBlueList(); // Calls the function that will display the names of paces of people in the blue color group
			cout << endl; // Outputs an empty line
		}

		else if (choice == 6) // Executes if the user inputs a 6
		{
			DATABASE.ShowLilacList(); // Calls the function that will display the names of paces of people in the lilac color group
			cout << endl; // Outputs an empty line
		}

		else if (choice == 7) // Executes if the user inputs a 7
		{
			DATABASE.ShowRedList(); // Calls the function that will display the names of paces of people in the red color group
			cout << endl; // Outputs an empty line
		}
	}

	cout << "\nYou have gone through the entire list." << endl;

	return 0;
}





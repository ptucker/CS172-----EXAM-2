/*******************************************************************************************************


I affirm that all code givin below is written solely by me
, Aaron Meyers,
and that any help I receieved adhered to the rules stated for this exam.


********************************************************************************************************/


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "RunnerDatabase.h"
using namespace std;

//This function will take the info that is stored in the txt file ("filename" is the name of the txt file) and store it into a vector
Database::Database(string filename)
{
	ifstream INPUT(filename); // Sets up a ifstream for taking information from the txt file

	if (INPUT.fail()) // This will test whether or not the file exists
	{
		cout << "File does not exist" << endl;
		cout << "Exit program" << endl;
		return ; // Ends the program if the txt file is not found
	}

	// This loop will take the information from the loop (first name and last name of an individual, and their pace) and store it into an vector
	// This loop will execute until the end of the txt file is reached
	while (!INPUT.eof())
	{
		string FName, LName; // Declares string variables
		int PACE; // Declares integer variable

		INPUT >> FName; // Gets the first name from the txt file and saves it into the FName variable
		INPUT >> LName; // Gets the last name from the txt file and saves it into the LName variable
		INPUT >> PACE; // Gets the pace from the txt file and saves it into the PACE variable

		Runner OneLine(FName, LName, PACE); // Creates an object of the Runner class with the above variable
		DATABASE.push_back(OneLine); // Saves the Runner object into the DATABASE vector
	}

	INPUT.close(); // Closes input from the txt file
}

// This function will sort the DATABASE vector and sort it in ascending order according to an individuals pace
void Database::SortInOrder()
{
	// This loop will go through the entire DATABASE vector to sort it in ascending order according to an individuals pace
	for (int i = 0; i < DATABASE.size(); i++)
	{
		// Creates a variable that will contain the values of FirstName, LastName, and Pace from the array 
		// The value of this variable will change depending on whether the value of Pace and whether or not it is the smallest value in the DATABASE vector
		Runner Smallest = DATABASE.at(i);
		int Savepoint = i; // declares a variable that will keep track of which spot in a vector contains the smallest value (its default value is set to "i")

		// This loop will run through the DATABASE vector and test for the smallest value in the vector
		// The loop will end once it goes through the entire vector
		for (int j = i + 1; j < DATABASE.size(); j++)
		{
			if (Smallest > DATABASE.at(j)) // This executes if the value of "Smallest" is greater than the current value in the vector
			{
				Smallest = DATABASE.at(j); // Sets the value of "Smallest" to the current value of the DATABASE vector
				Savepoint = j; // Saves the value of "j" (which is the spot of the vector that the value of "Smallest" is equal to
			}
		}
		DATABASE.at(Savepoint) = DATABASE.at(i); // Swaps the values that are stored at "Savepoint" and "i" to ensure that the value stored at "i" is not overridden and lost when the next line executes
		DATABASE.at(i) = Smallest; // Makes the current spot in the DATABASE vector equal to the value of "Smallest"
	}

}


// This function will reoragnize all of the values that are stored in the DATABASE vector into a list that goes in ascending order based on the pace of the runners
void Database::SortIntoColors(Runner& Run)
{
	// These create new txt files if it is the first time, if not, then it wil open the selected txt file and delete their contents
	ofstream WhiteRunners("White Runners.txt", ios::out);
	ofstream YellowRunners("Yellow Runners.txt", ios::out);
	ofstream GreenRunners("Green Runners.txt", ios::out);
	ofstream OrangeRunners("Orange Runners.txt", ios::out);
	ofstream BlueRunners("Blue Runners.txt", ios::out);
	ofstream LilacRunners("Lilac Runners.txt", ios::out);
	ofstream RedRunners("Red Runners.txt", ios::out);


	// This loop will go through the entire DATABASE vector (now organized in ascending order by individual pace)
	// As the loop executes, it will determine if the current vector value of Pace is less than or equal to the Max pace limit for a certain color 
	for (int i = 0; i < DATABASE.size(); i++)
	{
		Runner Color = DATABASE.at(i); // Sets the value of "Color" to the current value of the DATABASE vector

		// This will execute if the value of "Color" is less than or eqaul to the max pace limit of the White color section
		if (Run.getWhiteMax() >= Color.getPace())
		{
			WhiteRunners << DATABASE.at(i); // Saves the current vector value into the txt file for storing White runners
		}

		// This will execute if the value of "Color" is less than or eqaul to the max pace limit of the Yellow color section
		else if (Run.getYellowMax() >= Color.getPace())
		{
			YellowRunners << DATABASE.at(i); // Saves the current vector value into the txt file for storing Yellow runners
		}

		// This will execute if the value of "Color" is less than or eqaul to the max pace limit of the Green color section
		else if (Run.getGreenMax() >= Color.getPace())
		{
			GreenRunners << DATABASE.at(i); // Saves the current vector value into the txt file for storing Green runners
		}

		// This will execute if the value of "Color" is less than or eqaul to the max pace limit of the Orange color section
		else if (Run.getOrangeMax() >= Color.getPace())
		{
			OrangeRunners << DATABASE.at(i); // Saves the current vector value into the txt file for storing Orange runners
		}

		// This will execute if the value of "Color" is less than or eqaul to the max pace limit of the Blue color section
		else if (Run.getBlueMax() >= Color.getPace())
		{
			BlueRunners << DATABASE.at(i); // Saves the current vector value into the txt file for storing Blue runners
		}

		// This will execute if the value of "Color" is less than or eqaul to the max pace limit of the Lilac color section
		else if (Run.getLilacMax() >= Color.getPace())
		{
			LilacRunners << DATABASE.at(i); // Saves the current vector value into the txt file for storing Lilac runners
		}

		// This will execute if the value of "Color" is less than or eqaul to the max pace limit of the Red color section
		else if (Run.getRedMax() >= Color.getPace())
		{
			RedRunners << DATABASE.at(i); // Saves the current vector value into the txt file for storing Red runners
		}
	}

	// These will close the open txt files to make sure that no more input is added
	WhiteRunners.close();
	YellowRunners.close();
	GreenRunners.close();
	OrangeRunners.close();
	BlueRunners.close();
	LilacRunners.close();
	RedRunners.close();
}

//This function will output the data that is stored in the txt file that holds the runners in the White catagory
void Database::ShowWhiteList()
{
	// This will create an input stream with a txt file stored with runners names and paces
	ifstream InputWhiteList("White Runners.txt", ios::in);

	// This will execute if the above txt file does not exist
	if (InputWhiteList.fail())
	{
		cout << "File does not exist" << endl;
		return ;
	}

	string fName, lName; // Declares string variables for file input
	int pace; // Declares an integer variable for file input

	// This loop will execute until the end of the txt file is reached
	// The loop is for outputting all of the data that is stored in the txt file
	while (!InputWhiteList.eof())
	{
		InputWhiteList >> fName >> lName >> pace; // Saves the data from the txt file to the variuable declared before the current loop started 
		if (InputWhiteList.eof()) break; // This will execute if the end of the txt file is reached to avoid the last variables from being outted twice

		cout << fName << " " << lName << pace << endl; // Outputs the data stored in the fname, lName, and pace variables
	}

	InputWhiteList.close(); // This closes the input stream with the txt file
}

//This function will output the data that is stored in the txt file that holds the runners in the Yellow catagory
void Database::ShowYellowList()
{
	// This will create an input stream with a txt file stored with runners names and paces
	ifstream InputYellowList("Yellow Runners.txt", ios::in);

	// This will execute if the above txt file does not exist
	if (InputYellowList.fail())
	{
		cout << "File does not exist" << endl;
		return;
	}

	string fName, lName; // Declares string variables for file input
	int pace; // Declares an integer variable for file input

	// This loop will execute until the end of the txt file is reached
	// The loop is for outputting all of the data that is stored in the txt file
	while (!InputYellowList.eof())
	{
		InputYellowList >> fName >> lName >> pace; // Saves the data from the txt file to the variuable declared before the current loop started 
		if (InputYellowList.eof()) break; // This will execute if the end of the txt file is reached to avoid the last variables from being outted twice

		cout << fName << " " << lName << pace << endl; // Outputs the data stored in the fname, lName, and pace variables
	}

	InputYellowList.close(); // This closes the input stream with the txt file
}

//This function will output the data that is stored in the txt file that holds the runners in the Green catagory
void Database::ShowGreenList()
{
	// This will create an input stream with a txt file stored with runners names and paces
	ifstream InputGreenList("Green Runners.txt", ios::in);

	// This will execute if the above txt file does not exist
	if (InputGreenList.fail())
	{
		cout << "File does not exist" << endl;
		return;
	}

	string fName, lName; // Declares string variables for file input
	int pace; // Declares an integer variable for file input

	// This loop will execute until the end of the txt file is reached
	// The loop is for outputting all of the data that is stored in the txt file
	while (!InputGreenList.eof())
	{
		InputGreenList >> fName >> lName >> pace; // Saves the data from the txt file to the variuable declared before the current loop started 
		if (InputGreenList.eof()) break; // This will execute if the end of the txt file is reached to avoid the last variables from being outted twice

		cout << fName << " " << lName << pace << endl; // Outputs the data stored in the fname, lName, and pace variables
	}

	InputGreenList.close(); // This closes the input stream with the txt file
}

//This function will output the data that is stored in the txt file that holds the runners in the Orange catagory
void Database::ShowOrangeList()
{
	// This will create an input stream with a txt file stored with runners names and paces
	ifstream InputOrangeList("Orange Runners.txt", ios::in);

	// This will execute if the above txt file does not exist
	if (InputOrangeList.fail())
	{
		cout << "File does not exist" << endl;
		return;
	}

	string fName, lName; // Declares string variables for file input
	int pace; // Declares an integer variable for file input

	// This loop will execute until the end of the txt file is reached
	// The loop is for outputting all of the data that is stored in the txt file
	while (!InputOrangeList.eof())
	{
		InputOrangeList >> fName >> lName >> pace; // Saves the data from the txt file to the variuable declared before the current loop started 
		if (InputOrangeList.eof()) break; // This will execute if the end of the txt file is reached to avoid the last variables from being outted twice

		cout << fName << " " << lName << pace << endl; // Outputs the data stored in the fname, lName, and pace variables
	}

	InputOrangeList.close(); // This closes the input stream with the txt file
}

//This function will output the data that is stored in the txt file that holds the runners in the Blue catagory
void Database::ShowBlueList()
{
	// This will create an input stream with a txt file stored with runners names and paces
	ifstream InputBlueList("Blue Runners.txt", ios::in);

	// This will execute if the above txt file does not exist
	if (InputBlueList.fail())
	{
		cout << "File does not exist" << endl;
		return;
	}

	string fName, lName; // Declares string variables for file input
	int pace; // Declares an integer variable for file input

	// This loop will execute until the end of the txt file is reached
	// The loop is for outputting all of the data that is stored in the txt file
	while (!InputBlueList.eof())
	{
		InputBlueList >> fName >> lName >> pace; // Saves the data from the txt file to the variuable declared before the current loop started 
		if (InputBlueList.eof()) break; // This will execute if the end of the txt file is reached to avoid the last variables from being outted twice

		cout << fName << " " << lName << pace << endl; // Outputs the data stored in the fname, lName, and pace variables
	}

	InputBlueList.close(); // This closes the input stream with the txt file
}

//This function will output the data that is stored in the txt file that holds the runners in the Lilac catagory
void Database::ShowLilacList()
{
	// This will create an input stream with a txt file stored with runners names and paces
	ifstream InputLilacList("Lilac Runners.txt", ios::in);

	// This will execute if the above txt file does not exist
	if (InputLilacList.fail())
	{
		cout << "File does not exist" << endl;
		return;
	}

	string fName, lName; // Declares string variables for file input
	int pace; // Declares an integer variable for file input

	// This loop will execute until the end of the txt file is reached
	// The loop is for outputting all of the data that is stored in the txt file
	while (!InputLilacList.eof())
	{
		InputLilacList >> fName >> lName >> pace; // Saves the data from the txt file to the variuable declared before the current loop started 
		if (InputLilacList.eof()) break; // This will execute if the end of the txt file is reached to avoid the last variables from being outted twice

		cout << fName << " " << lName << pace << endl; // Outputs the data stored in the fname, lName, and pace variables
	}

	InputLilacList.close(); // This closes the input stream with the txt file
}

//This function will output the data that is stored in the txt file that holds the runners in the Red catagory
void Database::ShowRedList()
{
	// This will create an input stream with a txt file stored with runners names and paces
	ifstream InputRedList("Red Runners.txt", ios::in);

	// This will execute if the above txt file does not exist
	if (InputRedList.fail())
	{
		cout << "File does not exist" << endl;
		return;
	}

	string fName, lName; // Declares string variables for file input
	int pace; // Declares an integer variable for file input

	// This loop will execute until the end of the txt file is reached
	// The loop is for outputting all of the data that is stored in the txt file
	while (!InputRedList.eof())
	{
		InputRedList >> fName >> lName >> pace; // Saves the data from the txt file to the variuable declared before the current loop started 
		if (InputRedList.eof()) break; // This will execute if the end of the txt file is reached to avoid the last variables from being outted twice

		cout << fName << " " << lName << pace << endl; // Outputs the data stored in the fname, lName, and pace variables
	}

	InputRedList.close(); // This closes the input stream with the txt file
}

// This overrides the "<<" operator so that when DATABASE.at(i) is used, it will output the 3 values that are stored in that one spot of the vector
ostream& operator<<(ostream& RUN, Runner Run)
{
	RUN << Run.getFirstName() << " " << Run.getLastName() << " " << Run.getPace(); // Saves the values of FirstName, LastName, and Pace to "RUN" so it can be outputted
	return RUN; // Returns "RUN" for output
}
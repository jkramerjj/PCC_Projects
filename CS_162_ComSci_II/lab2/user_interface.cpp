// This is the Lab 2 / Personal Organizer (user_interface.cpp)
// Written by: Joseph Kramer
// Class: CS162
// Date: 07/11/17
// Sources: Text Book, course videos, in class examples


#include "user_interface.h"
#include "myutil.h"
#include <iomanip>


/*
Purpose: To read in a command
Out: cInCommand --> used to proceed throug the program
*/
char readCommand() {
	char	cInCommand;

	cout << "Please enter in (A, L, S, R, or Q): " << endl;
	cin.get(cInCommand);
	cInCommand = tolower(cInCommand);
	
	while ((cInCommand !='a')&&(cInCommand !='l')&&(cInCommand !='s')&&(cInCommand !='q')&&(cInCommand !='r')) {
		cin.clear();
		cin.ignore(iMAX_CHAR, '\n');
		cout << "Please enter either (A, L, S, R, or Q): ";
		cin.get(cInCommand);
	}
		
	cin.ignore(100, '\n');
	cInCommand = verifyQuit(cInCommand);
	return cInCommand;
}


/*
Purpose: To run the intial prompts
Out: Formal menu layout
*/
void runPrompt() {
	cout << "Welcome to Joe's Persoanl Organizer!" << endl;
	cout << "What would you like to do today?" << endl;
	cout << "(A)	To add an Entry: " << endl;
	cout << "(L)	To list all current Entries: " << endl;	
	cout << "(S)	To search entry list: " << endl;
	cout << "(R)	To remove an entry: " << endl;
	cout << "(Q)	To quit the program: " << endl;	
}


/*
Purpose: Used to list entries in the taskList array
Out: Display of what's in taskList[]
*/
void listEntries (const task list[], int iListSize) {
	cout << left << setw(iCOL_WIDTH_NAME) << "Name" << setw(iCOL_WIDTH_DESCRIPTION) << "Desciption" << setw(iCOL_WIDTH_DUE_DATE) << "Due Date" <<endl;
	for(int i = 0; i < iListSize; i++) {
		cout << left << setw(iCOL_WIDTH_NAME) << list[i].a_cCouresName << setw(iCOL_WIDTH_DESCRIPTION) << list[i].a_cAssignmentDescription 
			<< setw(iCOL_WIDTH_DUE_DATE) << list[i].a_cDueDate << endl;
	}	
}


/*
Purpose: Used to list entries in the foundIt[] array
Out: Display of what's in foundIt[]
*/
void listSearchedEntries (const char a_cCourseName[], task list[], int iListSize, int& foundCoutner) {
	cout << endl;
	cout << " Following information for: " << a_cCourseName << endl;
	for (int i = 0; i < foundCoutner; i++) {
		cout << right << setw(iCOL_SEARCH_WIDTH) << " Description: " << list[i].a_cAssignmentDescription << endl;
		cout << right << setw(iCOL_SEARCH_WIDTH) << " Due Date: " << list[i].a_cDueDate << endl;
		cout << endl;
	}
}


/* This function reads in a_cCourseName.
   out: a_cCourseName
*/
void readInCourseName (char a_cCourseName[]) {
	readInString("Please enter the name you want to search: ", a_cCourseName, iMAX_CHAR);
}


/*
Purpose: Read in a_cCourseName, a_cAssignmentDescription, and a_cDueDate
Out: Text to user and string copy
*/
void readInEntry (task& anEntry) {
	char	a_cCourseName[iMAX_CHAR];
	char	a_cAssignmentDescription[iMAX_CHAR];
	char	a_cDueDate[iMAX_CHAR];

	readInString("Please enter the Name: ", a_cCourseName, iMAX_CHAR);
	readInString("Please enter the Assignment Description: ", a_cAssignmentDescription, iMAX_CHAR);
	readInString("Please enter the the Due Date: ", a_cDueDate, iMAX_CHAR);

	strcpy(anEntry.a_cCouresName, a_cCourseName);
	strcpy(anEntry.a_cAssignmentDescription, a_cAssignmentDescription);
	strcpy(anEntry.a_cDueDate, a_cDueDate);
}


/*
Purpose: Echo the entered in task
Out: Display what is newly entered
*/
void listNewEntry (const task taskList[], int searchIndex) {

	cout << "\n\nYOU ADDED:" << endl;
	cout <<  "******************************************************" << endl;
	cout << left << setw(iCOL_WIDTH_NAME) << "Name" << setw(iCOL_WIDTH_DESCRIPTION) 
		<< "Desciption" << setw(iCOL_WIDTH_DUE_DATE) << "Due Date" <<endl;
	cout << left << setw(iCOL_WIDTH_NAME) << taskList[searchIndex].a_cCouresName << setw(iCOL_WIDTH_DESCRIPTION) << taskList[searchIndex].a_cAssignmentDescription 
		<< setw(iCOL_WIDTH_DUE_DATE) << taskList[searchIndex].a_cDueDate << endl;
	cout <<  "******************************************************\n\n" << endl;
}


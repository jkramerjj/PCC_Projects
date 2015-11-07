// This is the Lab 3 / Personal Organizer (user_interface.cpp)
// Written by: Joseph Kramer
// Class: CS162
// Date: 07/13/17
// Sources: Text Book, course videos, in class examples


#include "user_interface.h"
#include <iostream>                 
using namespace std;


/* 
	This function reads in an address entry.
	out: anEntry
*/
void readInEntry(TaskList& anEntry) {
	char	a_cName[iMAX_CHAR];
	char	a_cAssignmentDescription[iMAX_CHAR];
	char	a_cDueDate[iMAX_CHAR];

	//read in a_cName and email
	readString("Please enter the Course Name: ", a_cName, iMAX_CHAR);
	readString("Please enter an Assignment Description: ", a_cAssignmentDescription, iMAX_CHAR);
	readString("Please enter the Due Date: ", a_cDueDate, iMAX_CHAR);

	//populate the passed in object
	anEntry.setCourseName(a_cName);
	anEntry.setAssignmentDescription(a_cAssignmentDescription);
	anEntry.setDueDate(a_cDueDate);
}


/* 
	This function reads in a_cName.
	out: a_cName
*/
void readInName(char a_cName[]) {
	readString("Please enter the Course Name you want to search: ", a_cName, iMAX_CHAR);
}


/*
	This function reads in user's command.
	return: the command in lower case
*/
char readInCommand()
{
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
	Used to display the main menu 
*/
void displayMenu() {
	cout << "Welcome to Joe's Personal Organizer!" << endl;
	cout << "What would you like to do today?" << endl;
	cout << "(A)	To add an Entry: " << endl;
	cout << "(L)	To list all current Entries: " << endl;	
	cout << "(S)	To search entry list: " << endl;
	cout << "(R)	To remove an entry: " << endl;
	cout << "(Q)	To quit the program: " << endl;	
}

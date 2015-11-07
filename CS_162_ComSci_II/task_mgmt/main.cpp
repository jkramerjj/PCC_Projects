// This is the Lab 3 / Personal Organizer (main.cpp)
// Written by: Joseph Kramer
// Class: CS162
// Date: 07/12/17
// Sources: Text Book, course videos, in class examples


#include <iostream>                 
//#include <cctype>
#include <iomanip>

#include "task_list.h"
#include "entry_list.h"
#include "my_utilities.h"
#include "user_interface.h"

using namespace std;     

// Process Prototype
void processCommand(char command, EntryList& list);



int main () {
	char			command;
	char			a_cFileName[] = "tasks.txt";
	EntryList		list(a_cFileName);

	displayMenu();
	command = readInCommand();
	while (command != 'q') {

		processCommand(command, list);
		displayMenu();
		command = readInCommand();
	}

	pause();
	list.saveTaskList(a_cFileName);	
    
    return 0;
}

/* 
	This function processes the command passed in.
	in: command
	in/out: list and listSize
*/
void processCommand(char command, EntryList& list)
{
	TaskList	entry;
	char		courseName[iMAX_CHAR];
	char		a_cAssignmentDescription[iMAX_CHAR];
	char		a_cDueDate[iMAX_CHAR];
	
	switch (command) {
	case 'a': 
		readInEntry(entry);
		list.addEntry(entry);		// this has access to TaskList functions
		break;

	case 'l': 
		cout << endl;
		list.printAll();
		cout << endl << endl;
		break;

	case 's': 
		readInName(courseName);
		list.searchEntry(courseName, entry);
		break;

	case 'r':
		readInName(courseName);
		list.searchDeleteEntry(courseName, entry);

		break;

	default: 
		cout << endl << "Illegal Command!" << endl;
		break;
	}
}

// This is the Lab 4 / Personal Organizer (main.cpp)
// Written by: Joseph Kramer
// Class: CS162
// Date: 07/19/14
// Sources: Text Book, course videos, in class examples

//memory leak detection tool headers
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>                 
#include <cctype>
#include <fstream>
#include <iomanip>

#include "entry_list.h"
#include "task_list.h"
#include "my_utilities.h"
#include "user_interface.h"

using namespace std;     

//user-interface related functions
void processCommand(char command, EntryList& pntr_list);


int main () {
	//enable memory leak detection tools
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	char			command;
	char			a_cFileName[] = "tasks.txt";
	EntryList		pntr_list(1, a_cFileName);

	displayMenu();
	command = readInCommand();
	while (command != 'q') {
		processCommand(command, pntr_list);
		displayMenu();
		command = readInCommand();
	}
	pause();
	pntr_list.saveTaskList(a_cFileName);	
    
    return 0;
}

/* 
	This function processes the command passed in.
    in: command
    in/out: pntr_list and listSize
*/
void processCommand(char command, EntryList& pntr_list) {
	TaskList		entry;
	TaskList		searchEntryList[iMAX_CHAR];
	char			a_cName[iMAX_CHAR];
	char			assignmentDesc[iMAX_CHAR];
	char			a_cDueDate[iMAX_CHAR];
	bool			bTotallyComplete = false;
	int				iFoundCounter = 0;

	switch (command) {
	case 'a': 
		readInEntry(entry);
		pntr_list.addEntry(entry);
		break;

	case 'l': 
		pntr_list.printAll();
		break;

	case 's': 
		readInName(a_cName);
		while (bTotallyComplete == false) {
			  if(pntr_list.searchEntry(a_cName, searchEntryList, bTotallyComplete, iFoundCounter)) {
				 
				  for(int i = 0; i < iFoundCounter; i++) {
					  searchEntryList[i].getAsignmentDesc(assignmentDesc);
					  searchEntryList[i].getDueDate(a_cDueDate);
					  cout << right << setw(iCOL_SEARCH_WIDTH) << " Description: " << assignmentDesc << endl;
					  cout << right << setw(iCOL_SEARCH_WIDTH) << " Due Date: " << a_cDueDate << endl;
					  cout << endl;
				  }
				  break;
			  }
			  else
				  cout << "\t** NOTHING WAS FOUND ** " << endl << endl;
		}
		break;
					  
	case 'r':
		readInName(a_cName);
		if(pntr_list.searchDeleteEntry(a_cName, searchEntryList)) {
			cout << "\nAll entries of ** " << a_cName << " ** have been removed!\n\n" << endl;
		}
		else
			cout << "\nThe task ** " << a_cName << " ** could not be found." << endl << endl;
		break;

	case 'n':	// case 'n' exisits incase the user decides not to quit and enters a 'n'
		break;

	default: 
		cout << endl << "Illegal Command!" << endl;
		break;
	}
}


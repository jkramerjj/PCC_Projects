// This is the Lab 2 / Personal Organizer (lab2.cpp)
// Written by: Joseph Kramer
// Class: CS162
// Date: 07/11/17
// Sources: Text Book, course videos, in class examples


#include "myutil.h"
#include "user_interface.h"
#include "io.h"
#include "db.h"


// Prototype -- Process Commands
void processCommand (char cCommand, task taskList[], int& iListSize);


int main () {

	// Variables
	char			cCommand;
	task			taskList[iLIST_SIZE];
	int				iListSize = 0;
	char			cYesOrNo = 'y';
	char			a_cFileName[] = "tasks.txt";

	openTaskFile(a_cFileName, taskList, iListSize);

	runPrompt();
	cCommand = readCommand();

	while (cCommand != 'q') {
		
		processCommand(cCommand, taskList, iListSize);
		runPrompt();
		cCommand = readCommand();
	}
	
	saveTaskFile(a_cFileName, taskList, iListSize);

	pause();
	return 0;
}


/*
Purpose: To process cCommand and excute functions
Out: Search results
*/
void processCommand (char cCommand, task taskList[], int& iListSize) {
	task		anEntry;
	task		foundIt[iLIST_SIZE];
	char		a_cCourseName[iMAX_CHAR];
	bool		firstTime = false;
	int			iDeleteLocationIndex = 0;
	int			foundCounter;
	
	switch (cCommand)
	{
	case 'a': 
		readInEntry(anEntry);
		addEntry(anEntry, taskList, iListSize, firstTime);
		break;

	case 'l':
		cout << endl;
		listEntries(taskList, iListSize);
		cout << endl << endl;
		break;

	case 's':
		readInCourseName(a_cCourseName);
		if (searchForEntry(a_cCourseName, foundIt, taskList, iListSize, foundCounter)) {  
			listSearchedEntries(a_cCourseName, foundIt, iListSize, foundCounter);			
		}
		else {
			cout << endl;
			cout << " Search Results --> NOTHING FOUND USING: " << a_cCourseName << endl;
			cout << endl;
		}
		break;

	case 'r':
		readInCourseName(a_cCourseName);
		searchForDeleteEntry(a_cCourseName, taskList, iListSize, iDeleteLocationIndex);
		break;

	default: 
		cout << "Illegal Command Entered!" << endl;
		break;
	
	}

}



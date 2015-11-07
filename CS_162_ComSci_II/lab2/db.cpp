// This is the Lab 2 / Personal Organizer (db.cpp)
// Written by: Joseph Kramer
// Class: CS162
// Date: 07/12/17
// Sources: Text Book, course videos, in class examples


#include "db.h"
#include <iostream>
using namespace std;


/*
Purpose:	To add entries into the struct task taskList[]
			and to update iListSize			
			
*/
void addEntry (const task entry, task taskList[], int& iListSize, bool& firstTime) {

		strcpy (taskList[iListSize].a_cCouresName, entry.a_cCouresName);
		strcpy (taskList[iListSize].a_cAssignmentDescription, entry.a_cAssignmentDescription);
		strcpy (taskList[iListSize].a_cDueDate, entry.a_cDueDate);
		iListSize++;
}


/* This function searches an entry by courseName.
   in: a_cCourseName, foundIt, taskList, listSize
   out: foundIt
   return: true if a foundIt is found and FoundIt contains the courseName
           false if a foundIt is not found and foundIt does not contain the courseName
*/
bool searchForEntry (const char a_cCourseName[], task foundIt[], const task taskList[], int iListSize, int& foundCounter) {
	int i;
	bool found = false;
	foundCounter = 0;
	for(i = 0; i < iListSize; i++) {
		if(strcmp(a_cCourseName, taskList[i].a_cCouresName) == 0) {
			strcpy(foundIt[foundCounter].a_cCouresName, taskList[i].a_cCouresName);
			strcpy(foundIt[foundCounter].a_cAssignmentDescription, taskList[i].a_cAssignmentDescription);
			strcpy(foundIt[foundCounter].a_cDueDate, taskList[i].a_cDueDate);
			found = true;
			foundCounter++;
		}
	}
	if (!found) 
		return false;
	else
		return true;
}


/* Purpose:		This function searches an entry by courseName 
				and sets bool bNotFound to false. Will loop shifting
				everything up one, and then will restart until every instance
				of coureName has been removed
*/
void searchForDeleteEntry(const char a_cCourseName[], task taskList[], int& iListSize, int& iDeleteLocationIndex) {
	int		index = 0;
	bool	foundIt = false;
	int		sizeCounter = 0;
	for(index; index < iListSize; index++) {
	
		if(strcmp(a_cCourseName, taskList[index].a_cCouresName) == 0) {
			int searchIndex = index;
			index = -1; // start the search over everytime
			for(searchIndex; searchIndex < iListSize; searchIndex++) {
				strcpy(taskList[searchIndex].a_cCouresName, taskList[searchIndex + 1].a_cCouresName);
				strcpy(taskList[searchIndex].a_cAssignmentDescription, taskList[searchIndex + 1].a_cAssignmentDescription);
				strcpy(taskList[searchIndex].a_cDueDate, taskList[searchIndex + 1].a_cDueDate);
			}
			iListSize--;
			foundIt = true;
		}
	}
	
	if(!foundIt) {
		cout << "\nThe task ** " << a_cCourseName << " ** could not be found." << endl << endl;
	}
	else {
		cout << "\nAll entries of ** " << a_cCourseName << " ** have been removed!\n\n" << endl;
	}
}

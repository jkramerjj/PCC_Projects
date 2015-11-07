#define _CRT_SECURE_NO_WARNINGS

/* The implementation file for class entry_list.

   Written by: Joe Kramer
   Date: 07/11/2014

   Sources: None
*/

#include "entry_list.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/* 
	Default constructor. It initializes the list to be empty.
*/
EntryList::EntryList() {
	iSize = 0;
}

/* 
	A constructor that initializes the list with data on the passed in file.
	in: a_cFileName
*/
EntryList::EntryList(const char a_cFileName[]) {
	iSize = 0;
	loadTaskList(a_cFileName);
}


/* 
	This function reads the entries from the file and adds them to the TaskList.
    in: a_cFileName
*/
void EntryList::loadTaskList(const char a_cFileName[]) {

	ifstream		inFile;
	char			a_cCourseName[iMAX_CHAR];
	char			a_cAssignmentDescription[iMAX_CHAR];
	char			a_cDueDate[iMAX_CHAR];
	TaskList		anEntry;

	inFile.open (a_cFileName);
	if(!inFile) {
		inFile.clear();
		cerr << endl << "Failed to open " << a_cFileName << " for required input!" << endl << endl;
		//pause();
		exit(1);
	}

	inFile.get(a_cCourseName, iMAX_CHAR, ';');
	while (!inFile.eof()) {
		inFile.get();										
		inFile.get(a_cAssignmentDescription, iMAX_CHAR, ';');
		//inFile.ignore(100, '\n');				
		inFile.get();
		inFile.get(a_cDueDate, iMAX_CHAR, '\n');
		inFile.ignore(iMAX_CHAR, '\n');

		anEntry.setCourseName(a_cCourseName);
		anEntry.setAssignmentDescription(a_cAssignmentDescription);
		anEntry.setDueDate(a_cDueDate);

		addEntry(anEntry);

		inFile.get(a_cCourseName, iMAX_CHAR, ';');		
	}
	inFile.close();
}


/* 
	This function returns the iSize of the Task List.
    return: iSize
*/
int EntryList::getSize() const {
	return iSize;
}


/* 
	This function prints all the entries to the standard output.
*/
void EntryList::printAll() const {
	//int		index;
	char	a_cName[iMAX_CHAR];
	char	a_cAssignmentDescription[iMAX_CHAR];
	char	a_cDueDate[iMAX_CHAR];

	cout << left << setw(iCOL_WIDTH_NAME) << "Name" << setw(iCOL_WIDTH_DESCRIPTION) << "Desciption" << setw(iCOL_WIDTH_DUE_DATE) << "Due Date" <<endl;
	for(int i=0; i < iSize; i++) {
		list[i].getCourseName (a_cName);
		list[i].getAssignmentDescription (a_cAssignmentDescription);
		list[i].getDueDate (a_cDueDate);

		cout << left << setw(iCOL_WIDTH_NAME) << a_cName << setw(iCOL_WIDTH_DESCRIPTION) << a_cAssignmentDescription 
			<< setw(iCOL_WIDTH_DUE_DATE) << a_cDueDate << endl;
	}
}


/*
	This function returns the TaskList object at the specified position through parameter
    in: index
    out: anEntry
    return: true if avalaible entry  and false if entry does not exists
*/
bool EntryList::get(int index, TaskList &anEntry) const {
	char	a_cName[iMAX_CHAR];
	char	a_cAssignmentDescription[iMAX_CHAR];
	char	a_cDueDate[iMAX_CHAR];

	if (index < 0 || index >= iSize)
		return false;

	list[index].getCourseName (a_cName);
	list[index].getAssignmentDescription (a_cAssignmentDescription);
	list[index].getDueDate (a_cDueDate);
	anEntry.setCourseName (a_cName);
	anEntry.setAssignmentDescription(a_cAssignmentDescription);	
	anEntry.setDueDate(a_cDueDate);	
	return true;
}


/* This function searches the list for an entry with passed in a_cName. 
   in: a_cName
   out: match
*/
void EntryList::searchEntry(const char a_cName[], TaskList& match) const {
	int		index;
	char	a_cCurrentName[iMAX_CHAR];
	char	a_cCurrentAssignmentDescription[iMAX_CHAR];
	char	a_cCurrentDueDate[iMAX_CHAR];
	bool	foundIt = false;

	cout << "\nFollowing information for: " << a_cName << endl;
	
	for(index = 0; index < iSize; index++) {

		list[index].getCourseName (a_cCurrentName);
		list[index].getAssignmentDescription (a_cCurrentAssignmentDescription);
		list[index].getDueDate (a_cCurrentDueDate);
		
		if(strcmp(a_cName, a_cCurrentName) == 0) {	

			cout << right << setw(iCOL_SEARCH_WIDTH) << " Description: " << a_cCurrentAssignmentDescription << endl;
			cout << right << setw(iCOL_SEARCH_WIDTH) << " Due Date: " << a_cCurrentDueDate << endl;
			cout << endl;
			
			foundIt = true;
		}
	}
	if (!foundIt)
		cout << "\t** NOTHING WAS FOUND ** " << endl << endl;
	
}


/* This function searches the list for an entry with passed in a_cName. 
   in: a_cName
   out: deleted or not deleted
*/
void EntryList::searchDeleteEntry(const char a_cName[], TaskList& match) {
	int		index = 0;
	char	a_cCurrentName[iMAX_CHAR];
	char	a_cCurrentAssignmentDescription[iMAX_CHAR];
	char	a_cCurrentDueDate[iMAX_CHAR];
	bool	bFoundIt = false;
	//int		sizeCounter = 0;
	for(index; index < iSize; index++) {
		list[index].getCourseName (a_cCurrentName);
		list[index].getAssignmentDescription (a_cCurrentAssignmentDescription);
		list[index].getDueDate (a_cCurrentDueDate);
		
		if(strcmp(a_cName, a_cCurrentName) == 0) {
			int iSearchIndex = index;
			index = -1; // start the search over everytime
			for(iSearchIndex; iSearchIndex < iSize; iSearchIndex++) {
				
			//	list[iSearchIndex] = list[iSearchIndex + 1];	// this was so much easier.....

				list[iSearchIndex + 1].getCourseName (a_cCurrentName);
				list[iSearchIndex].setCourseName (a_cCurrentName);

				list[iSearchIndex + 1].getAssignmentDescription (a_cCurrentAssignmentDescription);
				list[iSearchIndex].setAssignmentDescription (a_cCurrentAssignmentDescription);

				list[iSearchIndex + 1].getDueDate (a_cCurrentDueDate);
				list[iSearchIndex].setDueDate (a_cCurrentDueDate);					
			}

		bFoundIt = true;
		iSize--;
		}
	}

	if(!bFoundIt) {
		cout << "\nThe task ** " << a_cName << " ** could not be found." << endl << endl;
	}
	else {
		cout << "\nAll entries of ** " << a_cName << " ** have been removed!\n\n" << endl;
	}
}


/* This function saves the list to the external file.
   in: a_cFileName
*/
void EntryList::saveTaskList(const char a_cFileName[]) const {
	ofstream		outFile;
	int				index;
	char			a_cName[iMAX_CHAR];
	char			a_cAssignmentDescription[iMAX_CHAR];
	char			a_cDueDate[iMAX_CHAR];

	outFile.open (a_cFileName);
	if(!outFile) {
		outFile.clear();
		cerr << endl << "Fail to open " << a_cFileName << " for output!" << endl << endl;
		exit(1);
	}

	for(index=0; index<iSize; index++) {
		list[index].getCourseName(a_cName);
		list[index].getAssignmentDescription(a_cAssignmentDescription);
		list[index].getDueDate(a_cDueDate);
		outFile << a_cName << ';' << a_cAssignmentDescription << ";" <<  a_cDueDate << endl;
	}

	outFile.close();
}

/* This function adds a passed in entry to the end of the list.
   in: anEntry
*/
void EntryList::addEntry(const TaskList &anEntry) {
	char			a_cName[iMAX_CHAR];
	char			a_cAssignmentDescription[iMAX_CHAR];
	char			a_cDueDate[iMAX_CHAR];

	anEntry.getCourseName(a_cName);
	anEntry.getAssignmentDescription(a_cAssignmentDescription);
	anEntry.getDueDate(a_cDueDate);
	list[iSize].setCourseName(a_cName);
	list[iSize].setAssignmentDescription(a_cAssignmentDescription);
	list[iSize].setDueDate(a_cDueDate);
	list[iSize] = anEntry;
	iSize++;
}
	


























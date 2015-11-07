/* 
	The implementation file for class entry_list.

    Written by: Joe Kramer
    Date: 07/19/17

    Sources: Text Book, course videos, in class examples
*/


#include "entry_list.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/* 
	Default constructor. It initializes the pntr_list to be empty.
*/
EntryList::EntryList() {
	iCapacity = ADDRESS_BOOK_CAPACITY;
	pntr_list = new TaskList[iCapacity];
	iSize = 0;
}

/* 
	A constructor that initializes the pntr_list with data on the passed in file.
	in: a_cFileName
*/
EntryList::EntryList(int iInitCapacity, const char a_cFileName[]) {
	iCapacity = iInitCapacity;
	pntr_list = new TaskList[iCapacity];
	iSize = 0;
	loadTaskList(a_cFileName);
}

/*
	Destructor. It releases the memory allocated for the array.
*/
EntryList::~EntryList() {
	if(pntr_list != NULL)
		delete [] pntr_list;
}

/* 
	This function reads the entries from the file and adds them to the TaskList.
    in: a_cFileName
*/
void EntryList::loadTaskList(const char a_cFileName[]) {
	ifstream		inFile;
	char			a_cName[iMAX_CHAR];
	char			a_cAsignmentDesc[iMAX_CHAR];
	char			a_cDueDate[iMAX_CHAR];
	TaskList		anEntry;

	inFile.open (a_cFileName);
	if(!inFile) {
		inFile.clear();
		cerr << endl << "Fail to open " << a_cFileName << " for input!" << endl << endl;
		exit(1);
	}

	inFile.get(a_cName, iMAX_CHAR, ';');
	while (!inFile.eof()) {
		inFile.get();										
		inFile.get(a_cAsignmentDesc, iMAX_CHAR, ';');
		//in.ignore(100, '\n');				
		inFile.get();
		inFile.get(a_cDueDate, iMAX_CHAR, '\n');
		inFile.ignore(100, '\n');

		anEntry.setCourseName(a_cName);
		anEntry.setAssignmentDesc(a_cAsignmentDesc);
		anEntry.setDueDate(a_cDueDate);

		addEntry(anEntry);

		inFile.get(a_cName, iMAX_CHAR, ';');	
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
	This function returns the TaskList object at the specified position through parameter
    in: index
    out: anEntry
    return: true if avalaible entry  and false if entry does not exists
*/
bool EntryList::get(int index, TaskList &anEntry) const {
	char	a_cName[iMAX_CHAR];
	char	a_cAsignmentDesc[iMAX_CHAR];
	char	a_cDueDate[iMAX_CHAR];

	if(index<0 || index>=iSize)
		return false;

	pntr_list[index].getAsignmentDesc (a_cAsignmentDesc);
	pntr_list[index].getCourseName (a_cName);
	pntr_list[index].getDueDate (a_cDueDate);
	anEntry.setAssignmentDesc (a_cAsignmentDesc);
	anEntry.setCourseName(a_cName);	
	anEntry.setDueDate (a_cDueDate);
	return true;
}

/* 
	This function searches the pntr_list for an entry with passed in a_cName. 
    in: a_cName
    out: match
    return: true if a match is found and match will be returned through parameter.
            false if a match can not be found 
*/
bool EntryList::searchEntry(const char a_cName[], TaskList searchEntryList[], bool &bTotallyComplete, int& iFoundCounter) const {
	//int		index;
	char	currentName[iMAX_CHAR];
	char	currentEmail[iMAX_CHAR];
	char	currentDueDate[iMAX_CHAR];
	int		counter = 0;

	while(counter < iSize) {
		pntr_list[counter].getCourseName (currentName);
		pntr_list[counter].getAsignmentDesc(currentEmail);
		pntr_list[counter].getDueDate (currentDueDate);
		counter ++;
		if(strcmp(a_cName, currentName) == 0) {
			searchEntryList[iFoundCounter].setCourseName(currentName);
			searchEntryList[iFoundCounter].setAssignmentDesc(currentEmail);
			searchEntryList[iFoundCounter].setDueDate(currentDueDate);
			iFoundCounter++;
			//break;
		}
	}
	if (iFoundCounter > 0) {
		bTotallyComplete = true;
		return true;
		
	}
	else {
		bTotallyComplete = true;
		return false;
		
	}
}


/* 
	This function searches the pntr_list for an entry with passed in a_cName. 
    in: a_cName
    out: deleted or not deleted
	return: true if a match is found and match will be returned through parameter.
            false if a match can not be found
*/
bool EntryList::searchDeleteEntry(const char a_cName[], TaskList searchEntryList[]) {
	int		index = 0;
	char	a_cCurrentName[iMAX_CHAR];
	char	a_cCurrentAssignmentDescription[iMAX_CHAR];
	char	a_cCurrentDueDate[iMAX_CHAR];
	bool	bFoundIt = false;
	//int		sizeCounter = 0;
	for(index; index < iSize; index++) {
		pntr_list[index].getCourseName (a_cCurrentName);
		pntr_list[index].getAsignmentDesc(a_cCurrentAssignmentDescription);
		pntr_list[index].getDueDate (a_cCurrentDueDate);
		
		if(strcmp(a_cName, a_cCurrentName) == 0) {
			int iSearchIndex = index;
			index = -1; // start the search over everytime
			for(iSearchIndex; iSearchIndex < iSize; iSearchIndex++) {
				
				pntr_list[iSearchIndex + 1].getCourseName (a_cCurrentName);
				pntr_list[iSearchIndex].setCourseName (a_cCurrentName);
	
				pntr_list[iSearchIndex + 1].getAsignmentDesc (a_cCurrentAssignmentDescription);
				pntr_list[iSearchIndex].setAssignmentDesc (a_cCurrentAssignmentDescription);

				pntr_list[iSearchIndex + 1].getDueDate (a_cCurrentDueDate);
				pntr_list[iSearchIndex].setDueDate (a_cCurrentDueDate);					
			}

		bFoundIt = true;
		iSize--;
		}
	}
	if(bFoundIt)
		return true;
	else
		return false;
}


/* 
	This function prints all the entries to the standard output.
*/
void EntryList::printAll() const {
	char	a_cName[iMAX_CHAR];
	char	a_cAsignmentDesc[iMAX_CHAR];
	char	a_cDueDate[iMAX_CHAR];

	cout << left << setw(iCOL_WIDTH_NAME) << "Name" << setw(iCOL_WIDTH_DESCRIPTION) << "Desciption" << setw(iCOL_WIDTH_DUE_DATE) << "Due Date" <<endl;
	for(int i=0; i < iSize; i++) {
		pntr_list[i].getCourseName (a_cName);
		pntr_list[i].getAsignmentDesc (a_cAsignmentDesc);
		pntr_list[i].getDueDate (a_cDueDate);

		cout << left << setw(iCOL_WIDTH_NAME) << a_cName << setw(iCOL_WIDTH_DESCRIPTION) << a_cAsignmentDesc 
			<< setw(iCOL_WIDTH_DUE_DATE) << a_cDueDate << endl;
	}
	cout << endl;
}

/* This function saves the pntr_list to the external file.
   in: a_cFileName
*/
void EntryList::saveTaskList(const char a_cFileName[]) const {
	ofstream		outFile;
	//int				index;
	char			a_cName[iMAX_CHAR];
	char			a_cAsignmentDesc[iMAX_CHAR];
	char			a_cDueDate[iMAX_CHAR];

	outFile.open (a_cFileName);
	if(!outFile) {
		outFile.clear();
		cerr << endl << "Fail to open " << a_cFileName << " for output!" << endl << endl;
		exit(1);
	}

	for(int i = 0; i < iSize; i++) {
		pntr_list[i].getCourseName(a_cName);
		pntr_list[i].getAsignmentDesc(a_cAsignmentDesc);
		pntr_list[i].getDueDate (a_cDueDate);
		outFile << a_cName << ';' << a_cAsignmentDesc << ";" << a_cDueDate << endl;
	}

	outFile.close();
}

/* This function adds a passed in entry to the end of the pntr_list.
   in: anEntry
*/
void EntryList::addEntry(const TaskList &anEntry) {
	char	a_cName[iMAX_CHAR];
	char	a_cAsignmentDesc[iMAX_CHAR];
	char	a_cDueDate[iMAX_CHAR];

	if(iSize == iCapacity) {
		expandList();
	}
	anEntry.getCourseName(a_cName);
	anEntry.getAsignmentDesc(a_cAsignmentDesc);
	anEntry.getDueDate(a_cDueDate);
	pntr_list[iSize].setCourseName(a_cName);
	pntr_list[iSize].setAssignmentDesc(a_cAsignmentDesc);
	pntr_list[iSize].setDueDate(a_cDueDate);

	iSize++;
}

/* This function creats a new array that is twice as big as the current one. It copies the 
   TaskList objects over to this new array.
*/
void EntryList::expandList() {
	TaskList *		tempList;
	char			a_cName[iMAX_CHAR];
	char			a_cAsignmentDesc[iMAX_CHAR];
	char			a_cDueDate[iMAX_CHAR];
	//int				i;

	//creates a new array
	iCapacity *= 2;
	tempList = new TaskList[iCapacity];

	//coppies over the content
	for(int i = 0; i < iSize; i++) {
		pntr_list[i].getCourseName(a_cName);
		pntr_list[i].getAsignmentDesc(a_cAsignmentDesc);
		pntr_list[i].getDueDate (a_cDueDate);
		tempList[i].setCourseName(a_cName);
		tempList[i].setAssignmentDesc(a_cAsignmentDesc);
		tempList[i].setDueDate (a_cDueDate);
	}

	delete [] pntr_list;

	pntr_list = tempList;
	tempList = NULL;
}


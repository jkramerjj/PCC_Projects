/* 
	The implementation file for class entry_list.

    Written by: Joe Kramer
    Date: 08/06/14

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
	head = NULL;
	iSize = 0;
}

/* 
	A constructor that initializes the pntr_list with data on the passed in file.
	in: a_cFileName
*/
EntryList::EntryList(const char a_cFileName[]) {
	head = NULL;
	iSize = 0;
	loadTaskList(a_cFileName);
}

/*
	Destructor. It releases the memory allocated for the array.
*/
EntryList::~EntryList() {
	Node* curr = head;

	while(head != NULL) {
		curr = head->link;
		delete head;
		head = curr;	
	}
}

/* 
	This function reads the entries from the file and adds them to the TaskList.
    in: a_cFileName
*/
void EntryList::loadTaskList(const char a_cFileName[]) {
	ifstream		inFile;
	char			a_cName[iMAX_CHAR];
	char			a_cAssignmentDesc[iMAX_CHAR];
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
		inFile.get(a_cAssignmentDesc, iMAX_CHAR, ';');
		inFile.get();
		inFile.get(a_cDueDate, iMAX_CHAR, '\n');
		inFile.ignore(100, '\n');

		anEntry.setCourseName(a_cName);
		anEntry.setAssignmentDesc(a_cAssignmentDesc);
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
	char	a_cAssignmentDesc[iMAX_CHAR];
	char	a_cDueDate[iMAX_CHAR];

	if(index<0 || index>=iSize)
		return false;

	
	Node *	curr = head;
	for(int i = 0; i < index; i++)
	{	
		curr = curr->link;
	}

	curr->data.getCourseName(a_cName);
	curr->data.getAsignmentDesc(a_cAssignmentDesc);
	curr->data.getDueDate(a_cDueDate);

	anEntry.setAssignmentDesc(a_cAssignmentDesc);
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
bool EntryList::searchEntry(const char a_cName[], TaskList& searchEntryList, int& iFoundCounter) const {

	Node *  curr;
	char	currentName[iMAX_CHAR];
	char	currentAsignmentDesc[iMAX_CHAR];
	char	currentDueDate[iMAX_CHAR];
	
	for(curr = head; curr != NULL; curr = curr -> link) {
		curr->data.getCourseName(currentName);
		curr->data.getAsignmentDesc(currentAsignmentDesc);
		curr->data.getDueDate(currentDueDate);

		if(strcmp(a_cName, currentName) == 0) {
			searchEntryList.setCourseName(currentName);
			searchEntryList.setAssignmentDesc(currentAsignmentDesc);
			searchEntryList.setDueDate(currentDueDate);
			printSearchPointer(curr);
			iFoundCounter++;
		}
	}
	
	if (iFoundCounter > 0) {
		return true;		
	}
	else {
		return false;		
	}
}

/* 
	This function prints the searched results. 
    in: searchEntryList
    out: CurrentAssignmentDesc and CurrentDueDate
*/
void EntryList::printSearch(TaskList& searchEntryList) const {
	char	currentAsignmentDesc[iMAX_CHAR];
	char	currentDueDate[iMAX_CHAR];
	searchEntryList.getAsignmentDesc(currentAsignmentDesc);
	searchEntryList.getDueDate(currentDueDate);
	cout << right << setw(iCOL_SEARCH_WIDTH) << " Description: " << currentAsignmentDesc << endl;
	cout << right << setw(iCOL_SEARCH_WIDTH) << " Due Date: " << currentDueDate << endl;
	cout << endl;
}

/* 
	This function prints the searched results. 
    in: searchEntryList
    out: CurrentAssignmentDesc and CurrentDueDate
*/
void EntryList::printSearchPointer(Node* currSearch) const {
	char	currentAsignmentDesc[iMAX_CHAR];
	char	currentDueDate[iMAX_CHAR];

	currSearch->data.getAsignmentDesc (currentAsignmentDesc);
	currSearch->data.getDueDate (currentDueDate);

	cout << right << setw(iCOL_SEARCH_WIDTH) << " Description: " << currentAsignmentDesc << endl;
	cout << right << setw(iCOL_SEARCH_WIDTH) << " Due Date: " << currentDueDate << endl;
	cout << endl;
}

/* 
	This function prints all the entries to the standard output.
*/
void EntryList::printAll() const {
	Node*	curr;
	char	a_cName[iMAX_CHAR];
	char	a_cAssignmentDesc[iMAX_CHAR];
	char	a_cDueDate[iMAX_CHAR];

	cout << left << setw(iCOL_WIDTH_NAME) << "Name" << setw(iCOL_WIDTH_DESCRIPTION) << "Desciption" << setw(iCOL_WIDTH_DUE_DATE) << "Due Date" <<endl;
	for (curr = head; curr!=nullptr; curr=curr->link) {
		curr->data.getCourseName (a_cName);
		curr->data.getAsignmentDesc (a_cAssignmentDesc);
		curr->data.getDueDate (a_cDueDate);

		cout << left << setw(iCOL_WIDTH_NAME) << a_cName << setw(iCOL_WIDTH_DESCRIPTION) << a_cAssignmentDesc 
			<< setw(iCOL_WIDTH_DUE_DATE) << a_cDueDate << endl;
	}
	cout << endl;
}

/* 
	This function validates in the node list is empty before deleting
	return: true if there is a a match
			false if there isn't a match
*/
bool EntryList::searchEmptyList(TaskList& searchEntryList) {//const int iHold, TaskList& searchEntryList) {
	if(head == NULL)
		return true;

	return false;
}

/* 
	This function searches the pntr_list for an entry with passed in a_cName. 
    in: a_cName
    out: deleted or not deleted
	return: true if a match is found and match will be returned through parameter.
            false if a match can not be found
*/
bool EntryList::searchDeleteEntry(const char a_cName[], TaskList& searchEntryList) {
	int		searchCounter = 0;
	Node *	curr = head;
	Node *	temp;
	Node *	prevTemp = curr;
	char	a_cCurrentName[iMAX_CHAR];
	
	curr->data.getCourseName(a_cCurrentName);
	if(strcmp(a_cName, a_cCurrentName) == 0) {
		if(curr == head) {
			head = head->link;
			delete curr;
			TrackTail();
			iSize--;	
			return true;
			}
		}
		else {
			while(!strcmp(a_cName, a_cCurrentName) == 0) {
				searchCounter++;
				prevTemp = curr;
				curr = curr->link;
					if(searchCounter < iSize)
						curr->data.getCourseName(a_cCurrentName);
					else if (searchCounter == iSize)
						return false;
			}

			temp = curr->link;
			prevTemp->link = temp;
			delete curr;
			TrackTail();
			iSize--;
			return true;
	}
}

/* This function saves the pntr_list to the external file.
   in: a_cFileName
*/
void EntryList::saveTaskList(const char a_cFileName[]) const {
	ofstream		outFile;
	
	outFile.open (a_cFileName);
	if(!outFile) {
		outFile.clear();
		cerr << endl << "Fail to open " << a_cFileName << " for output!" << endl << endl;
		exit(1);
	}

	Node *			curr;
	char			a_cName[iMAX_CHAR];
	char			a_cAssignmentDesc[iMAX_CHAR];
	char			a_cDueDate[iMAX_CHAR];

	for (curr = head; curr!=nullptr; curr=curr->link) {
		curr->data.getCourseName(a_cName);
		curr->data.getAsignmentDesc(a_cAssignmentDesc);
		curr->data.getDueDate (a_cDueDate);
		outFile << a_cName << ';' << a_cAssignmentDesc << ";" << a_cDueDate << endl;
	}

	outFile.close();
}

/* This function adds a passed in entry to the end of the pntr_list.
   in: anEntry
*/
void EntryList::addEntry(const TaskList &anEntry) {
	addSorted(anEntry);
}

/* This function sorts the list by a_cName.
   in: anEntry
*/
void EntryList::addSorted(const TaskList& anEntry) {
	char		a_cName[iMAX_CHAR];
	char		a_cCurrentName[iMAX_CHAR];

	anEntry.getCourseName(a_cName);

	Node* newNode = new Node(anEntry);
	Node* prev = NULL;
	Node* curr = head;

	while(curr) {
		curr->data.getCourseName(a_cCurrentName);
		if(strcmp(a_cName, a_cCurrentName) < 0) 
			break;

		prev = curr;
		curr = curr->link;
	}

	newNode->link = curr;
	
	if(!prev)
		head = newNode;
	else
		prev->link = newNode;

	TrackTail();
	iSize++;
}

/* 
	This function keeps track of the tail pointer via a for loop.
*/
void EntryList::TrackTail()  {
	
	Node *	curr;
	for(curr = head; curr != NULL; curr = curr->link) {
		if(curr->link == NULL) {
			tail = curr;
		}
	}
	if(head == NULL)
		tail = NULL;
}

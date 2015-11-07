// This is the Lab 2 / Personal Organizer (io.cpp)
// Written by: Joseph Kramer
// Class: CS162
// Date: 07/11/17
// Sources: Text Book, course videos, in class examples


#include "io.h"
#include "db.h"
#include "myutil.h"
#include <fstream>


/*
Purpose:	To open tasks.txt file and verify it opened.
			To read through the file and copy over existing data.
Out:		Error if the file did not open
*/
void openTaskFile(const char a_cFileName[], task taskList[], int& iListSize ) {
	ifstream	inFile;
	bool		firstTime;

	char a_cCourseName[iMAX_CHAR];
	char a_cAssignmentDescription[iMAX_CHAR];
	char a_cDueDate[iMAX_CHAR];
	task entry;

	inFile.open(a_cFileName);
	if(!inFile) {
		inFile.clear();
		cerr << endl << "Failed to open " << a_cFileName << " for required input!" << endl << endl;
		pause();
		exit(1);
	}

	inFile.get(a_cCourseName, iMAX_CHAR, ';');
	while (!inFile.eof()) {
		firstTime = true;
		inFile.get();
		inFile.get(a_cAssignmentDescription, iMAX_CHAR, ';');
		inFile.get();
		inFile.get(a_cDueDate, iMAX_CHAR, '\n');
		inFile.ignore(iMAX_CHAR, '\n');
		
		strcpy(entry.a_cCouresName, a_cCourseName);
		strcpy(entry.a_cAssignmentDescription, a_cAssignmentDescription);
		strcpy(entry.a_cDueDate, a_cDueDate);

		addEntry(entry, taskList, iListSize, firstTime);

		inFile.get(a_cCourseName, iMAX_CHAR, ';');
	}

	firstTime = false;
	inFile.close();
}


/* This function saves the array to the external file.
   in: a_cFileName, taskList, iListSize
   out: Data to file
*/
void saveTaskFile (const char a_cFileName[], const task taskList[], int iListSize) {
	ofstream		outFile;

	outFile.open (a_cFileName);
	if(!outFile) {
		outFile.clear();
		cerr << endl << "Failed to open " << a_cFileName << " for output!" << endl << endl;
		pause();
		exit(1);
	}

	for(int i = 0; i < iListSize; i++) {
		outFile << taskList[i].a_cCouresName << ';' << taskList[i].a_cAssignmentDescription << ";" 
			<<  taskList[i].a_cDueDate << endl;
	}

	outFile.close();
}



/* A header file for db.cpp

   Written by: Joseph Kramer
   Date: 07/12/14

   Sources: couse videos
*/


#ifndef DB_H
#define DB_H
//#include "myutil.h"

//Struct
struct task {
	char a_cCouresName[iMAX_CHAR];
	char a_cAssignmentDescription[iMAX_CHAR];
	char a_cDueDate[iDATE_CHAR_MAX];
};

// Prototypes -- Database related functions
void addEntry (const task entry, task tasklist[], int& iListSize, bool& firstTime);
void searchForDeleteEntry (const char a_cCourseName[], task taskList[], int& iListSize, int& iDeleteLocationIndex);
bool searchForEntry(const char a_cCourseName[], task foundIt[], const task taskList[], int iListSize, int& foundCounter);


#endif
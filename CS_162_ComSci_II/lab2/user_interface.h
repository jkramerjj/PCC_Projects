/* A header file for user_interface.cpp

   Written by: Joseph Kramer
   Date: 07/11/14

   Sources: couse videos
*/



#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

//#include "myutil.h"
//#include "db.h"
#include <iomanip>

// Constants
const int	iCOL_SEARCH_WIDTH = 20;
const int	iCOL_WIDTH_NAME = 15;
const int	iCOL_WIDTH_DESCRIPTION = 30;
const int	iCOL_WIDTH_DUE_DATE = 15;

// Prototypes -- User interface fuctions
char readCommand();
void runPrompt();
void listEntries (const task list[], int searchIndex);
void listSearchedEntries(const char a_cCourseName[], task list[], int iListSize, int& foundCounter);
void readInCourseName (char a_cCourseName[]);
void readInEntry (task& anEntry);
void listNewEntry (const task taskList[], int iListSize);


#endif
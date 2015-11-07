/* The header file for class task_list.h

   Written by: Joseph Kramer
   Date: 07/11/14

   Sources: couse videos
*/

#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H
#include "task_list.h"


//user-interface related functions
void displayMenu();
char readInCommand();
void readInEntry(TaskList& anEntry);
void readInName(char a_cName[]);


#endif
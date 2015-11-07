/* The header file for class task_list.h

   Written by: Joseph Kramer
   Date: 07/11/14

   Sources: couse videos
*/

#ifndef TASK_LIST_H
#define TASK_LIST_H
#include "my_utilities.h"


class TaskList {

public:
	// Constructors
	TaskList();
	TaskList(const char a_cCourseName[], const char a_cAssignmentDescription[], const char a_cDueDate[]);
	
	// Accessort Functions
	void getCourseName(char a_cCourseName[]) const; 
	void getAssignmentDescription(char a_cAssignmentDescription[]) const;
	void getDueDate(char a_cDueDate[]) const;
	void printList() const;

	// Mutators
	void setCourseName(const char a_cCourseName[]);
	void setAssignmentDescription(const char a_cAssignmentDescription[]);
	void setDueDate(const char a_cDueDate[]);
	
private:
	char a_cCourseName[iMAX_CHAR];
	char a_cAssignmentDescription[iMAX_CHAR];
	char a_cDueDate[iDATE_CHAR_MAX];
};

#endif
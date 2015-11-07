/* The header file for class task_list.h

   Written by: Joseph Kramer
   Date: 07/19/17

   Sources: couse videos
*/

#ifndef TASK_LIST
#define TASK_LIST
#include "my_utilities.h"

class TaskList
{
public: 
	//constructors
	TaskList();
	TaskList(const char a_cName[], const char a_cAsignmentDesc[], const char a_cDueDate[]);

	//destructor
	~TaskList();

	//accessor functions
	void getCourseName(char a_cName[]) const;
	void getAsignmentDesc(char a_cAsignmentDesc[]) const;
	void getDueDate(char a_cDueDate[]) const;
	void print() const;

	//mutator functions
	void setCourseName(const char a_cName[]);
	void setAssignmentDesc(const char a_cAsignmentDesc[]);
	void setDueDate(const char a_cDueDate[]);

private:
	char*	a_cName;
	char*	a_cAsignmentDesc;
	char*	a_cDueDate;
}; 

#endif
/* The implementation file for class task_list.

   Written by: Joe Kramer
   Date: 07/12/2014

   Sources: None
*/

#define _CRT_SECURE_NO_WARNINGS
#include "task_list.h"
#include <iostream>
using namespace std;


/* 
	Default constructor. It initializes a_cCourseName. a_cAssitmentDescrption, and
	a_cDueDate to a default value.
*/
TaskList::TaskList () {
	strcpy(a_cCourseName, "no a_cName");
	strcpy(a_cAssignmentDescription, "no description");
	strcpy(a_cDueDate, "no due date");
}


/* 
	Constructor. It initializes a_cCourseName. a_cAssitmentDescrption, and
	a_cDueDate to a passed in value.
    in: a_cCourseName and a_cAssignmentDescription and a_cDueDate
*/
TaskList::TaskList (const char a_cCourseName[], const char a_cAssignmentDescription[], const char a_cDueDate[]) {
	strcpy(this->a_cCourseName, a_cCourseName);
	strcpy(this->a_cAssignmentDescription, a_cAssignmentDescription);
	strcpy(this->a_cDueDate, a_cDueDate);
}


/*	
	This function returns the Course Name of the entry through the parameter.
	out: a_cCourseName
*/
void TaskList::getCourseName (char a_cCourseName[]) const {
	strcpy(a_cCourseName, this->a_cCourseName);
}


/* 
	This functions returns the Assignment Description of the entry through the parameter.
	out: a_cAssignmentDescription
*/
void TaskList::getAssignmentDescription (char a_cAssignmentDescription[]) const {
	strcpy(a_cAssignmentDescription, this->a_cAssignmentDescription);
}


/* 
	This functions returns the DueDate of the entry through the parameter.
	out: a_cDueDate
*/
void TaskList::getDueDate (char a_cDueDate[]) const {
	strcpy(a_cDueDate, this->a_cDueDate);
}


/* 
	This function sets the Course Name to the passed in value.
	in: a_cCourseName
*/
void TaskList::setCourseName (const char a_cCourseName[]) {
	strcpy(this->a_cCourseName, a_cCourseName);
}


/* 
	This function sets the Assignment Descirption to the passed in value.
	in: a_cAssignmentDescription
*/
void TaskList::setAssignmentDescription (const char a_cAssignmentDescription[]) {
	strcpy(this->a_cAssignmentDescription, a_cAssignmentDescription);
}


/* 
	This function sets the Due Date to the passed in value.
	in: a_cDueDate
*/
void TaskList::setDueDate (const char a_cDueDate[]) {
	strcpy(this->a_cDueDate, a_cDueDate);
}


/* 
	This function prints the state of the object to stdout.
*/
void TaskList::printList() const {
	cout << a_cCourseName << " -> " << a_cAssignmentDescription << "- > " << a_cDueDate << endl;
}







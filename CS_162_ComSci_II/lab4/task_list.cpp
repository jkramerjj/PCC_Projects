#define _CRT_SECURE_NO_WARNINGS
/*
	The implementation file for class task_list.

    Written by: Joe Kramer
    Date: 07/19/17

    Sources: Text Book, course videos, in class examples
*/


#include "task_list.h"
#include <iostream>
using namespace std;

/* 
	Default constructor. It initializes a_cCourseName. a_cAssitmentDescrption, and
	a_cDueDate to a default value.
*/
TaskList::TaskList() {
	a_cName = new char[strlen("no a_cName")+1];
	strcpy(a_cName, "no a_cName");
	a_cAsignmentDesc = new char[strlen("no a_cAsignmentDesc")+1];
	strcpy(a_cAsignmentDesc, "no a_cAsignmentDesc");
	a_cDueDate = new char[strlen("no due date")+1];
	strcpy(a_cDueDate, "no due date");

}

/* 
	Constructor. It initializes a_cCourseName. a_cAssitmentDescrption, and
	a_cDueDate to a passed in value.
    in: a_cCourseName and a_cAssignmentDescription and a_cDueDate
*/
TaskList::TaskList(const char a_cName[], const char a_cAsignmentDesc[], const char a_cDueDate[]) {
	this->a_cName = new char[strlen(a_cName)+1];
	strcpy(this->a_cName, a_cName);	//this->a_cName refers to the instance variable "a_cName"
	
	this->a_cAsignmentDesc = new char[strlen(a_cAsignmentDesc)+1];
	strcpy(this->a_cAsignmentDesc, a_cAsignmentDesc); //this->a_cAsignmentDesc refers to the instance variable "a_cAsignmentDesc"

	this->a_cDueDate = new char[strlen(a_cDueDate)+1];
	strcpy(this->a_cDueDate, a_cDueDate); //this->a_cAsignmentDesc refers to the instance variable "a_cAsignmentDesc"
}

/* 
	Destructor. It releases the dynamic char array allocated for a_cName and a_cAsignmentDesc.
*/
TaskList::~TaskList() {
	if(a_cName != NULL)
		delete [] a_cName;
	if(a_cAsignmentDesc != NULL)
		delete [] a_cAsignmentDesc;
	if(a_cDueDate != NULL)
		delete [] a_cDueDate;
}

/*	
	This function returns the Course Name of the entry through the parameter.
	out: a_cCourseName
*/
void TaskList::getCourseName(char a_cName[]) const
{
	strcpy(a_cName, this->a_cName);
}

/* 
	This functions returns the Assignment Description of the entry through the parameter.
	out: a_cAssignmentDescription
*/
void TaskList::getAsignmentDesc(char a_cAsignmentDesc[]) const {
	strcpy(a_cAsignmentDesc, this->a_cAsignmentDesc);
}

/* 
	This functions returns the DueDate of the entry through the parameter.
	out: a_cDueDate
*/
void TaskList::getDueDate(char a_cDueDate[]) const {
	strcpy(a_cDueDate, this->a_cDueDate);
}

/* 
	This function prints the state of the object to stdout.
*/
void TaskList::print() const {
	cout << a_cName << " -> " << a_cAsignmentDesc << endl;
}

/* 
	This function sets the Course Name to the passed in value.
	in: a_cCourseName
*/
void TaskList::setCourseName(const char a_cName[]) {
	if(this->a_cName != NULL)
		delete [] this->a_cName;
	this->a_cName = new char[strlen(a_cName)+1];
	strcpy(this->a_cName, a_cName);
}

/* 
	This function sets the a_cAsignmentDesc to the passed in value.
	in: a_cAsignmentDesc
*/
void TaskList::setAssignmentDesc(const char a_cAsignmentDesc[]) {
	if(this->a_cAsignmentDesc != NULL)
		delete [] this->a_cAsignmentDesc;
	this->a_cAsignmentDesc = new char[strlen(a_cAsignmentDesc)+1];
	strcpy(this->a_cAsignmentDesc, a_cAsignmentDesc);
}

/* 
	This function sets the a_cAsignmentDesc to the passed in value.
    in: a_cDueDate
*/
void TaskList::setDueDate(const char a_cDueDate[]) {
	if(this->a_cDueDate != NULL)
		delete [] this->a_cDueDate;
	this->a_cDueDate = new char[strlen(a_cDueDate)+1];
	strcpy(this->a_cDueDate, a_cDueDate);
}

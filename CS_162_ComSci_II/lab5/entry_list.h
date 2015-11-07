/* The header file for class entry_list.

   Written by: Joe Kramer
   Date: 08/06/14

   Sources: None
*/


#ifndef ENTRY_LIST
#define ENTRY_LIST

#include "task_list.h"
#include "my_utilities.h"
#include <iostream>

const int ADDRESS_BOOK_CAPACITY = 100;
const int NAME_COL_WIDTH = 30;
const int EMAIL_COL_WIDTH = 40;



class EntryList {
public: 
	//constructors
	EntryList();
	EntryList(const char a_cFileName[]);

	//destructor
	~EntryList();

	//accessor functions
	bool get(int index, TaskList& anEntry) const;
	bool searchEntry(const char a_cName[], TaskList& searchEntryList, int &iFoundCounter) const;
	bool searchDeleteEntry(const char a_cName[], TaskList& searchEntryList);
	bool searchEmptyList(TaskList& searchEntryList); //const int iHold, TaskList& searchEntryList);
	int getSize() const;
	void printAll() const;
	void TrackTail();
	void printSearch(TaskList& searchEntryList) const;
			
	//mutator functions
	void addEntry(const TaskList& anEntry);
	void addSorted(const TaskList& anEntry);
	void loadTaskList(const char a_cFileName[]);
	void saveTaskList(const char a_cFileName[]) const;
	
private:
	struct Node {

		TaskList data;
		Node*	 link;

		Node (const TaskList& aData) {

			char	a_cName[iMAX_CHAR];
			char	a_cAssignmentDesc[iMAX_CHAR];
			char	a_cDueDate[iMAX_CHAR];

			aData.getCourseName(a_cName);
			aData.getAsignmentDesc(a_cAssignmentDesc);
			aData.getDueDate(a_cDueDate);

			data.setCourseName(a_cName);
			data.setAssignmentDesc(a_cAssignmentDesc);
			data.setDueDate(a_cDueDate);

			link = NULL;
		}
	};
	
	Node*	head;
	Node*	tail;
	int		iSize;
	void printSearchPointer(Node* currSearch) const;
};

#endif
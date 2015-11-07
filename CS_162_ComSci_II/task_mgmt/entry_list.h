/* The header file for class entry_list.

   Written by: Joe Kramer
   Date: 07/11/2014

   Sources: None
*/
#ifndef ENTRY_LIST
#define ENTRY_LIST

#include "task_list.h"


class EntryList {

public:
	EntryList();
	EntryList(const char a_cFileName[]);

	// Accessor Functions
	bool get(int index, TaskList& anEntry) const;
	void searchEntry(const char a_cName[], TaskList& match) const;
	void searchDeleteEntry(const char a_cName[], TaskList& match);
	int getSize() const;
	void printAll() const;
	void saveTaskList(const char a_cFileName[]) const;

	//mutator functions
	void addEntry(const TaskList& anEntry);
	void loadTaskList(const char a_cFileName[]);
	
private:
	TaskList	list[iMAX_CHAR];
	int			iSize;

};


#endif
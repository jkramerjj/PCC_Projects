/* The header file for class entry_list.

   Written by: Joe Kramer
   Date: 07/19/17

   Sources: None
*/


#ifndef ENTRY_LIST
#define ENTRY_LIST

#include "task_list.h"
#include "my_utilities.h"

const int ADDRESS_BOOK_CAPACITY = 100;
const int NAME_COL_WIDTH = 30;
const int EMAIL_COL_WIDTH = 40;



class EntryList {
public: 
	//constructors
	EntryList();
	EntryList(int iInitCapacity, const char a_cFileName[]);

	//destructor
	~EntryList();

	//accessor functions
	bool get(int index, TaskList& anEntry) const;
	bool searchEntry(const char a_cName[], TaskList searchEntryList[], bool &bTotallyComplete, int &iFoundCounter) const;
	bool searchDeleteEntry(const char a_cName[], TaskList searchEntryList[]);
	int getSize() const;
	void printAll() const;
	void saveTaskList(const char a_cFileName[]) const;
	
	//mutator functions
	void addEntry(const TaskList& anEntry);
	void loadTaskList(const char a_cFileName[]);
	
	
private:
	TaskList *		pntr_list;
	int				iSize;
	int				iCapacity;

	void expandList();
};

#endif